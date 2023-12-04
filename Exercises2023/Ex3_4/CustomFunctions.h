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

        int dist_flag;

        struct nCB_Vars
        {
            double x_avg;
            double n, a, s;
            double A,B,N,C,D;
        };
        struct nCB_Vars nCB_vars;

        void set_nCB_Vars(double n, double a, double s);

        double Mstep(double x_old, double delta);

    protected:

        double normdist(double x);
        double CLdist(double x);
        double nCBdist(double x);

        double callFunction(double x) override;

};