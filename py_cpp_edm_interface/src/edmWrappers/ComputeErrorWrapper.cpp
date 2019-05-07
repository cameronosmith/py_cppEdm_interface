//this file is a wrapper for the compute vector error method

#include "WrapperCommon.h"

////////////////////////////////////////////
// Compute Error Wrapper method
// @param vec1      : the first vector to compare
// @param vec2      : the second vector to compare
// @return          : map/dictionary w the rho, mae, rmse
////////////////////////////////////////////
std::map<std::string, double> ComputeErrorWrapper (
                        std::valarray<double> vec1, 
                        std::valarray<double> vec2 ){

    //just delegate to computer error 

    VectorError vecErr = ComputeError( vec1, vec2 );

    //setup as map instead of vecErr struct
    std::map<std::string, double> toPy;

    toPy[ "MAE" ]   = vecErr.MAE; 
    toPy[ "rho" ]   =  vecErr.rho; 
    toPy[ "RMSE" ]  = vecErr.RMSE;

    return toPy;
}
