#ifndef WRAPPER_COMMON
#define WRAPPER_COMMON

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Common.h"
#include "Embed.h"

//for convenience in wrapper function arg types since long and annoying
using PyDF = std::list< std::pair<std::string, std::valarray<double> >>;

////////////////////////////////////////////
// method to take a py map input and return dataframe
// @param pyInput: the py df equivalent
// @return: DataFrame 
////////////////////////////////////////////
DataFrame< double > PyToDataFrame (PyDF pyInput) {

    //get num rows for reference
    size_t numRows = 0;
    if ( pyInput.size() != 0) {
        numRows = pyInput.front().second.size();
    }
    
    //get col names to setup df with
    std::vector< std::string > colNames;
    for (auto colPair : pyInput) {
        colNames.push_back(colPair.first);
    } 

    //convert the py input to dataframe
    DataFrame< double > fromPy (numRows, colNames.size(), colNames); 

    for (PyDF::iterator it = pyInput.begin(); it != pyInput.end(); it++) {

        fromPy.WriteColumn( std::distance(pyInput.begin(), it), it->second); 

    }

    return fromPy;
}

////////////////////////////////////////////
// method to take a dataframe and convert it to a map for python output
// @param df: the data to package for python
// @return: the py df equivalent for python to get back
////////////////////////////////////////////
PyDF DataFrameToPy (DataFrame< double > outputDF) {

    PyDF toPy;

    //setup list with dataframe contents to give to python
    for ( std::string colName : outputDF.ColumnNames() ) {

        std::valarray< double > colData = outputDF.VectorColumnName (colName);

        toPy.push_back (std::make_pair( colName, colData ));

    }

    return toPy;
}
#endif
