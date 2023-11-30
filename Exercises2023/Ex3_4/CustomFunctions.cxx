#include <math.h>
#include "CustomFunctions.h"


/*
###################
//Distribution Functions
###################
*/ 

double CustomFunction::normdist(double x) {
    
    return (1/(1*(sqrtf32(2*M_PI_2f32))))*exp((-1/2)*((x+1/1)*(x+1/1)));

};

double CustomFunction::CLdist(double x) {
    
    return (1/(1*(sqrtf32(2*M_PI_2f32))))*exp((-1/2)*((x+1/1)*(x+1/1)));

};

double CustomFunction::nCBdist(double x) {
    
    return (1/(1*(sqrtf32(2*M_PI_2f32))))*exp((-1/2)*((x+1/1)*(x+1/1)));

};

/*
###################
//Function eval
###################
*/ 

double CustomFunction::callFunction(double x) {

    if (dist_flag==0) {
        return this->normdist(x);
    }
    if (dist_flag==1) {
        return this->CLdist(x);
    }
    if (dist_flag==2) {
        return this->nCBdist(x);
    }

};