import copy
import os
import sys

import yaml

os.chdir(sys.argv[1])  # Expect to be passed ${CMAKE_CURRENT_SOURCE_DIR} from cmake


TAB_SIZE = 2

class AnimationElement:
    sizeof = 10  # Manually updated
    def __init__(self, sequence_name, element_name, data, defaults=dict()):
        self._sequence_name = sequence_name
        self._element_name = element_name
        self.data = data
        self.x = data.get("x", defaults.get("x", 0))
        self.y = data.get("y", defaults.get("y", 0))
        self.w = data.get("w", defaults.get("w", 0))
        self.h = data.get("h", defaults.get("h", 0))
        self.invert = data.get("invert", defaults.get("invert", False))
        self.transparent = data.get("transparent", defaults.get("transparent", False))
        self.cleardisplay = data.get("cleardisplay", defaults.get("cleardisplay", False))
        self.renderonly = data.get("renderonly", defaults.get("renderonly", False))
        self.delay = data.get("delay", defaults.get("delay", 0))
        self.image = data.get("image", defaults.get("image", None))
        if self.image is None:
            raise ValueError("AnimationElement must have an image")
        
    @property
    def name(self):
        return f"_{self._sequence_name}_{self._element_name}_id{id(self)}"

    def __repr__(self):
        return f"AnimationElement(id={id(self)}, name={self.name}, x={self.x}, y={self.y}, w={self.w}, h={self.h}, invert={self.invert}, transparent={self.transparent}, cleardisplay={self.cleardisplay}, renderonly={self.renderonly}, delay={self.delay}, image={self.image}"

    def render_meta(self):
        if not self.invert and not self.transparent and not self.cleardisplay and not self.renderonly:
            return "IMAGE_DEFAULT"
        flags = []
        if self.invert:
            flags.append("IMAGE_INVERT")
        if self.transparent:
            flags.append("IMAGE_TRANSPARENT")
        if self.cleardisplay:
            flags.append("IMAGE_CLEARDISPLAY")
        if self.renderonly:
            flags.append("IMAGE_RENDERONLY")
        return " | ".join(flags)

    def get_cpp(self, next_name=None, tab_index=0):
        next_name = "nullptr" if next_name is None else "&" + next_name
        return f"""static const AnimationElement {self.name} = 
{" " * (TAB_SIZE * tab_index + 0)}{{
{" " * (TAB_SIZE * tab_index + 1)}.x = {self.x},
{" " * (TAB_SIZE * tab_index + 1)}.y = {self.y},
{" " * (TAB_SIZE * tab_index + 1)}.w = {self.w},
{" " * (TAB_SIZE * tab_index + 1)}.h = {self.h},
{" " * (TAB_SIZE * tab_index + 1)}.meta = {self.render_meta()},
{" " * (TAB_SIZE * tab_index + 1)}.delay = {self.delay},
{" " * (TAB_SIZE * tab_index + 1)}.image = {self.image},
{" " * (TAB_SIZE * tab_index + 1)}.next = {next_name}
{" " * (TAB_SIZE * tab_index + 0)}}};
"""


class AnimationSequence:
    sizeof = 3
    def __init__(self, name, raw_sequence, sequence_id=0, face_map=dict()):
        self.name = name
        self.data = raw_sequence
        self.id = sequence_id
        self.face_map = face_map
        if "defaults" in raw_sequence:
            self.defaults = raw_sequence["defaults"]
            del raw_sequence["defaults"]
        else:
            self.defaults = dict()
        self.elements = self.loop_handler(raw_sequence)
        seen_ids = set()
        for element in self.elements:
            if id(element) in seen_ids:
                raise RuntimeError("ID duplicate detected")
            if not isinstance(element, AnimationElement):
                raise TypeError("self.elements should only be AnimationElements")
            seen_ids.add(id(element))

    """Returns a list of AnimationElements.  Recursive"""
    def loop_handler(self, loop_data, existing_elements=[], loop_amt=1):
        new_elements = list()
        for element_name, raw_element in loop_data.items():
            if element_name == "loop":  # Ignore these once we recurse into a loop
                continue
            if "image" in raw_element:
                new_elements.append(AnimationElement(self.name, element_name, raw_element, self.defaults))
            elif "face" in raw_element:
                face_name = raw_element["face"]
                if face_name not in self.face_map:
                    raise KeyError(f"Face '{face_name}' not found")
                face = self.face_map[face_name]
                new_elements.extend(face.elements)
            elif "loop" in raw_element:
                new_elements = self.loop_handler(raw_element, new_elements, raw_element["loop"])
        copied_new_elements = []
        for _ in range(loop_amt):
            copied_new_elements.extend(copy.deepcopy(new_elements))
        return existing_elements + copied_new_elements

    def get_cpp(self, tab_index=0):
        return f"""const AnimationSequence {self.name} = 
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
        return f"extern const AnimationSequence {self.name};\n"


# Turns out this isn't really used, but still handy I guess
class Face(AnimationSequence):
    pass


def main():
    # Do the faces first
    with open("./yaml/faces.yaml") as f:
        yaml_data: dict = yaml.load(f, Loader=yaml.Loader)
    
    flash_size = 0
    face_counter = 0
    face_dict = {}
    for name, data in yaml_data.items():
        face = Face(name, data, face_counter)
        face_dict[name] = face
        flash_size += face.sizeof
        flash_size += len(face.elements) * AnimationElement.sizeof
        face_counter += 1

    with open("./faces.cpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash.\n")
        f.write("// NOTE these are declared backwards for linked list purposes\n")
        f.write("\n")
        f.write('#include "faces.hpp"\n')
        f.write('#include "Animator.hpp"\n')
        f.write('#include "images.hpp"\n')
        f.write('#include "globals.hpp"  // Face size declarations\n')
        f.write("\n")
        for face in face_dict.values():
            f.write(face.render_cpp())
            f.write("\n")
    
    with open("./faces.hpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash.\n")
        f.write("\n")
        f.write("#ifndef _FACES_H\n")
        f.write("#define _FACES_H\n")
        f.write("\n")
        f.write('#include "Animator.hpp"\n')
        f.write("\n")
        for face in face_dict.values():
            print(f"Defined animation sequence {face.name}")
            f.write(face.render_header())
        f.write("\n#endif")
    
    # Do the animation sequences
    with open("./yaml/animations.yaml") as f:
        yaml_data: dict = yaml.load(f, Loader=yaml.Loader)

    if yaml_data is None:
        return

    sequences = []
    flash_size = 0
    sequence_counter = 0
    for name, data in yaml_data.items():
        sequence = AnimationSequence(name, data, sequence_counter, face_dict)
        sequences.append(sequence)
        flash_size += AnimationSequence.sizeof
        flash_size += len(sequence.elements) * AnimationElement.sizeof
        sequence_counter += 1
    
    with open("./sequences.cpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash.\n")
        f.write("// NOTE these are declared backwards for linked list purposes\n")
        f.write("\n")
        f.write('#include "sequences.hpp"\n')
        f.write('#include "Animator.hpp"\n')
        f.write('#include "images.hpp"\n')
        f.write('#include "globals.hpp"  // Face size declarations\n')
        f.write("\n")
        for sequence in sequences:
            f.write(sequence.render_cpp())
            f.write("\n")
    
    with open("./sequences.hpp", "w") as f:
        f.write(f"// Autogenerated.  Takes {flash_size:,} bytes of flash.\n")
        f.write("\n")
        f.write("#ifndef _SEQUENCES_H\n")
        f.write("#define _SEQUENCES_H\n")
        f.write("\n")
        f.write('#include "Animator.hpp"\n')
        f.write("\n")
        for sequence in sequences:
            print(f"Defined animation sequence {sequence.name}")
            f.write(sequence.render_header())
        f.write("\n#endif")


main()
