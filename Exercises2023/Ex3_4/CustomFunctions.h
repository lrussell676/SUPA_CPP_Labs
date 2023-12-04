/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "FiniteFunctions.h"

#pragma once

class CustomFunction : public FiniteFunction {

    public:

        CustomFunction();  //Empty Constructor
        CustomFunction(double range_min, \
        double range_max, std::string outfile); //Variable Constructor
        ~CustomFunction(); //Empty Deconstructor

        std::vector<double> read_data_from_file(
        std::string file_location, int print_flag);

        double callFunction(double x) override; //callFunction is overidden,
        int dist_flag;                          //Then takes "dist_flag"
        double normdist(double x);              //to select either; normal,
        double CLdist(double x);                //Cauchy-Lorentz, or negative
        double nCBdist(double x);               //Crystal Ball distributions.

        struct nCB_Vars                                     //struct here is
        {                                                   //used to contain
            double x_avg;                                   //the many parameters
            double n, a, s;                                 //required for the 
            double A,B,N,C,D;                               //negative Crystal
        };                                                  //Ball distribution.
        struct nCB_Vars nCB_vars;                           //These are then set
        void set_nCB_Vars(double n, double a, double s);    //by this void function.

        //Mstep defines our Metropolis Algorithm
        double Mstep(double x_old, double delta_min=-2.0, double delta_max=2.0);
        //LinearSpacedArray is taken from: https://gist.github.com/mortenpi/f20a93c8ed3ee7785e65
        void LinearSpacedArray(std::vector<double> &xs, double a, double b, std::size_t N);

};