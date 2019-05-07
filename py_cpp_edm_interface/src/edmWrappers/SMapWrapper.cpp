//this file is a wrapper for the simplex algo

#include "WrapperCommon.h"

////////////////////////////////////////////
// SMap Wrapper method
// @param pyInput   : the input from python
// @other args      : see smap method header for details
// @return          : map/dictionary w the pred and coeff's
////////////////////////////////////////////
std::map<std::string, PyDF> SMapWrapper (PyDF pyInput, 
                     std::string lib, std::string pred, 
                     int E, int Tp, int knn, int tau, double theta,
                     std::string columns, std::string target,
                     bool embedded, bool verbose) {

    //just setup df's and delegate to smap. lol ez money. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

    SMapValues SMapOutput = SMap (  inputDF, "", "", lib, pred, E, 
                                    Tp, knn, tau, theta, columns, 
                                    target,"","", embedded, verbose);
    //setup for py
    std::map<std::string, PyDF> toPy;
    toPy["predictions"] = DataFrameToPy( SMapOutput.predictions );
    toPy["coefficients"] = DataFrameToPy( SMapOutput.coefficients );

    return toPy;
}
