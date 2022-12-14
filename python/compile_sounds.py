import copy
import os
import sys

import yaml

os.chdir(sys.argv[1])  # Expect to be passed ${CMAKE_CURRENT_SOURCE_DIR} from cmake


TAB_SIZE = 2

class SoundElement:
    sizeof = 8
    def __init__(self, sequence_name, element_name, data, defaults=dict()):
        self._sequence_name = sequence_name
        self._element_name = element_name
        self.data = data
        self.frequency = data.get("frequency", defaults.get("frequency", 0))
        self.duration = data.get("duration", defaults.get("duration", 0))
        self.delay = data.get("delay", defaults.get("delay", 0))
        if self.frequency == 0:
            raise ValueError("Can't have sound of frequency 0")
    
    @property
    def name(self):
        return f"_{self._sequence_name}_{self._element_name}_id{id(self)}"
    
    def __repr__(self):
        return f"SoundElement(id={id(self)}, name={self.name}, frequency={self.frequency}, duration={self.duration}, delay={self.duration})"

    def get_cpp(self, next_name=None, tab_index=0):
        next_name = "nullptr" if next_name is None else "&" + next_name
        return f"""static const SoundElement {self.name} = 
{" " * (TAB_SIZE * tab_index + 0)}{{
{" " * (TAB_SIZE * tab_index + 1)}.frequency = {self.frequency},
{" " * (TAB_SIZE * tab_index + 1)}.duration = {self.duration},
{" " * (TAB_SIZE * tab_index + 1)}.delay = {self.delay},
{" " * (TAB_SIZE * tab_index + 1)}.next = {next_name}
{" " * (TAB_SIZE * tab_index + 0)}}};
"""


class SoundSequence:
    sizeof = 3
    def __init__(self, name, raw_sequence, sequence_id=0):
        self.name = name
        self.data = raw_sequence
        self.id = sequence_id
        if "defaults" in raw_sequence:
            self.defaults = raw_sequence["defaults"]
            del raw_sequence["defaults"]
        else:
            self.defaults = dict()
        self.elements = self.loop_handler(raw_sequence)
        seen_ids = set()
        for element in self.elements:
            if (id(element)) in seen_ids:
                raise RuntimeError("ID duplicate detected")
            seen_ids.add(id(element))
        
    """Returns a list of SoundELements.  Recursive"""
    def loop_handler(self, loop_data, existing_elements=[], loop_amt=1):
        new_elements = list()
        for element_name, raw_element in loop_data.items():
            if element_name == "loop":  # Ignore these once we recurse into a loop
                continue
            if "frequency" in raw_element:
                new_elements.append(SoundElement(self.name, element_name, raw_element, self.defaults))
            elif "loop" in raw_element:
                new_elements = self.loop_handler(raw_element, new_elements, raw_element["loop"])
        copied_new_elements = []
        for _ in range(loop_amt):
            copied_new_elements.extend(copy.deepcopy(new_elements))
        return existing_elements + copied_new_elements

    def get_cpp(self, tab_index=0):
        return f"""const SoundSequence {self.name} = 
{" " * (TAB_SIZE * tab_index + 0)}{{
{" " * (TAB_SIZE * tab_index + 1)}.id = {self.id},
{" " * (TAB_SIZE * tab_index + 1)}.head = &{self.elements[0].name}
{" " * (TAB_SIZE * tab_index + 0)}}};
"""

    def render_cpp(self):
        out_str = ""
        out_str += f"#pragma region {self.name}\n"
        prev_name = None
        for i in reversed(range(len(self.elements))):
            out_str += self.elements[i].get_cpp(prev_name) + "\n"
            prev_name = self.elements[i].name
        out_str += self.get_cpp()
        out_str += f"#pragma endregion {self.name}\n"
        return out_str

    def render_header(self):
        return f"extern const SoundSequence {self.name};\n"


def main():
    with open("./yaml/sounds.yaml") as f:
        yaml_data = yaml.load(f, Loader=yaml.Loader)
    
    sequences = []
    flash_size = 0
    sequence_counter = 0
    for name, data in yaml_data.items():
        sequence = SoundSequence(name, data, sequence_counter)
        sequences.append(sequence)
        flash_size += SoundSequence.sizeof
        flash_size += len(sequence.elements) * SoundElement.sizeof
        sequence_counter += 1
    
    with open("./sounds.cpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash\n")
        f.write("\n")
        f.write('#include "sounds.hpp"\n')
        f.write('#include "notes.h"\n')
        f.write('#include "globals.hpp"\n')
        f.write('#include "Animator.hpp"\n')
        f.write("\n")
        for sequence in sequences:
            f.write(sequence.render_cpp())
            f.write("\n")
    
    with open("./sounds.hpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash\n")
        f.write("\n")
        f.write("#ifndef _SOUNDS_H\n")
        f.write("#define _SOUNDS_H\n")
        f.write("\n")
        f.write('#include "Animator.hpp"\n')
        f.write("\n")
        for sequence in sequences:
            print(f"Defined sound sequence {sequence.name}")
            f.write(sequence.render_header())
        f.write("\n#endif")

main()
