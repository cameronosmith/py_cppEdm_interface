"""
this file will create the .so file for the interface
you then can plop the generated .so file into your pyEDM lib to use this instead
"""
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys, os
import setuptools
import pybind11

__version__ = '0.0.1'

proj_name = "EDM_pybind"

#os.popopen("make -C src").readlines()

ext_modules = [
    Extension(
        proj_name,
        ['src/bindings/PyBind.cpp',],
        include_dirs=[
            # Path to pybind11 headers
            pybind11.get_include(),
            "src/cppEDM/src",
        ],
        language='c++',
        library_dirs=["./src/cppEDM/lib"],
        libraries=['EDM'],
	#extra_compile_args = ["-stdlib=libc++","-std=c++11"], 
    ),
]

setup(
    name=proj_name,
    version=__version__,
    description='pyedm using the cpp edm code',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.2'],
    zip_safe=False,
)

