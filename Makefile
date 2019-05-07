all:
	pip install py_cpp_edm_interface --user
	python py_cpp_edm_interface/copyGeneratedPyLib.py
