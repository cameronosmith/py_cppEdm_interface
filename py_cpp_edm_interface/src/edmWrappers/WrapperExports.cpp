//file to actually expose the wrapper functions to python

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "EmbedWrapper.cpp"
#include "SimplexWrapper.cpp"
#include "MultiviewWrapper.cpp"
#include "SMapWrapper.cpp"
#include "CCMWrapper.cpp"
#include "ComputeErrorWrapper.cpp"

PYBIND11_MODULE(py_cpp_edm_interface, pyMod) {

    pyMod.def("CPP_Embed",          &EmbedWrapper);
    pyMod.def("CPP_EmbedEval",      &EvaluateEmbedding);
    pyMod.def("CPP_Multiview",      &MultiviewWrapper);
    pyMod.def("CPP_Simplex",        &SimplexWrapper);
    pyMod.def("CPP_SMap",           &SMapWrapper);
    pyMod.def("CPP_CCM",            &CCMWrapper);
    pyMod.def("CPP_ComputeError",   &ComputeErrorWrapper);

}
