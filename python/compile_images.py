import glob
import os
import sys

import numpy as np
from PIL import Image

os.chdir(sys.argv[1])  # Expect to be passed ${CMAKE_CURRENT_SOURCE_DIR} from cmake


files = glob.glob("./images/**/*.png", recursive=True)

size = 0
header_str = ""
header_str += "#ifndef _IMAGES_H\n"
header_str += "#define _IMAGES_H\n"
header_str += "\n"
cpp_str = ""
cpp_str += '#include <stdint.h>\n'
cpp_str += '#include "images.hpp"\n'
cpp_str += "\n"
for fname in files:
    print(f"Adding {fname}")
    img = np.array(Image.open(fname))
    bool_arr: np.ndarray = img[:, :, 0] == 0  # For all columns and rows, compare the 1st channel (0th index) to 0 and return a bool
    bool_arr.flatten()  # Make the multidimensional array 1-dimensional
    int_arr = np.packbits(bool_arr)  # Pretend the bools are bitmasks for bytes
    size += int_arr.size  # Accumulate the size of each image so we can prepend the header with the flash consumed
    variable_name = os.path.splitext(os.path.basename(fname))[0]
    cpp_str += f"uint8_t {variable_name}[] =\n{{"
    header_str += f"extern uint8_t {variable_name}[];\n"
    for i, val in enumerate(int_arr):
        if i % (img.shape[1] / 8) == 0:
            cpp_str += "\n  "
        cpp_str += f"0x{val:X}, "
    if cpp_str[-3:] == "\n  ":  # Trim the trailing newline if it exists
        cpp_str = cpp_str[:-3]
    cpp_str += "\n};\n\n"

cpp_str = f"// Autogenerated.  Takes {size:,} bytes of flash.\n" + cpp_str
header_str = f"// Autogenerated.  Takes {size:,} bytes of flash.\n" + header_str + "\n#endif"


with open("./images.hpp", "w") as f:
    f.write(header_str)

with open("./images.cpp", "w") as f:
    f.write(cpp_str)