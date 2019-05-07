//this file is to wrap the ccm algo from edm

#include "WrapperCommon.h"

////////////////////////////////////////////
// CCM Wrapper method
// @param pyInput   : the input from python
// @other args      : see ccm method header for details
// @return          : pyOutput type
////////////////////////////////////////////

PyDF CCMWrapper (    PyDF pyInput, 
                     int E, int Tp, int knn, int tau, 
                     std::string columns, std::string target,
                     std::string libSizes_str, int sample,
                     bool random, unsigned seed, 
                     bool embedded, bool verbose) {

    //just setup df's and delegate to simplex. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

    DataFrame< double > ccmOutput = CCM (inputDF, "", "", E, 
			Tp, knn, tau, columns, target, 
			libSizes_str, sample, random,
			seed, verbose);

    PyDF toPy = DataFrameToPy (ccmOutput);

    return toPy;
}
