//this file is a wrapper for the Embed DataFrame

#include "WrapperCommon.h"

////////////////////////////////////////////
// Embed Wrapper method
// @param pyInput   : the input from python
// @other args      : see embed method header for details
// @return          : pyOutput type
////////////////////////////////////////////
PyDF EmbedWrapper (PyDF pyInput, int E, int tau, 
		std::string columns, bool verbose) {

    //just setup df's and delegate to embed. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

    DataFrame< double > embedded = Embed (inputDF, E, tau, columns, verbose);

    PyDF toPy = DataFrameToPy (embedded);

    return toPy;
}

////////////////////////////////////////////
// EmbeddingEvaluation method
// @param pyInput   : the input from python
// @other args      : see embed method header for details
// @return          : pyOutput type
////////////////////////////////////////////
PyDF EvaluateEmbedding (PyDF pyInput, int tau, int tp,
		std::string lib, std::string pred,
		std::string columns, std::string targetName, 
		bool verbose, unsigned int numThreads ) {

    //just setup df's and delegate to embed. lol ez money. 

    DataFrame< double > inputDF = PyToDataFrame (pyInput);

	DataFrame< double > embeddedDf = 
		EmbedDimension (inputDF, "","", lib, pred, tp, tau, columns, targetName,
				false, verbose, numThreads);

    PyDF toPy = DataFrameToPy (embeddedDf);

    return toPy;
}
