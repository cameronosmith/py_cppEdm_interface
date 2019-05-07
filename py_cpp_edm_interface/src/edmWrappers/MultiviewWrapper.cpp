//this file is to wrap the multiview helpeer method from cppedm

#include "WrapperCommon.h"

////////////////////////////////////////////
// Multiview Wrapper method
// @param pyInput   : the input from python
// @other args      : see ccm method header for details
// @return          : pyOutput type
////////////////////////////////////////////
std::map<std::string, PyDF> MultiviewWrapper ( PyDF pyInput, 
                     std::string lib, std::string pred,
					 int E, int Tp, int knn, int tau, 
                     std::string columns, std::string target,
                     int multiview, bool verbose, unsigned int numThreads ){

    //just setup df's and delegate to simplex. lol ez money. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

    MultiviewValues mvOutput = Multiview (inputDF, "", "", lib, pred, 
			E, Tp, knn, tau, columns, target, multiview, verbose, numThreads);

	//construct df of df's from multiview struct
	std::map<std::string, PyDF> toPy;
    toPy["Combo_rho"] 	= DataFrameToPy( mvOutput.Combo_rho );
    toPy["Predictions"] = DataFrameToPy( mvOutput.Predictions );

    return toPy;
}
