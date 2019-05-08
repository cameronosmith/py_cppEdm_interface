import os
#success install, copy .so
import py_cpp_edm_interface
soPath = py_cpp_edm_interface.__file__
os.sytem("cp %s ../output_lib" % soPath )
