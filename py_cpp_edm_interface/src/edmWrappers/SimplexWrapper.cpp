//this file is a wrapper for the simplex algo

#include "WrapperCommon.h"

////////////////////////////////////////////
// Simplex Wrapper method
// @param pyInput   : the input from python
// @other args      : see simplex method header for details
// @return          : pyOutput type
////////////////////////////////////////////
PyDF SimplexWrapper (PyDF pyInput, std::string lib, std::string pred, 
                     int E, int Tp, int knn, int tau, 
                     std::string columns, std::string target,
                     bool embedded, bool verbose) {

    //just setup df's and delegate to simplex. lol ez money. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

    DataFrame< double > simplexOutput = Simplex (inputDF, "", "", lib, pred, E, 
                                                 Tp, knn, tau, columns, target, 
                                                 embedded, verbose);

    PyDF toPy = DataFrameToPy (simplexOutput);

    return toPy;
}
