import sys
import os

os.chdir(sys.argv[1])  # Expect to be passed ${CMAKE_CURRENT_SOURCE_DIR} from cmake

with open("test_output.hpp", "w") as f:
    f.write("Hello World!")
