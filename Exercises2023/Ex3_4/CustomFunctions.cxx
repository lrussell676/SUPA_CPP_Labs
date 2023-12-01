/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include <math.h>
#include "CustomFunctions.h"


CustomFunction::CustomFunction(){};
//initialised constructor
CustomFunction::CustomFunction(double range_min, double range_max, std::string outfile){
  m_RMin = range_min;
  m_RMax = range_max;
  m_Integral = NULL;
  this->checkPath(outfile); //Use provided string to name output files
}
CustomFunction::~CustomFunction(){};

/*
###################
//Data Import
###################
*/ 

std::vector<double> CustomFunction::read_data_from_file(
    std::string file_location, int print_flag = 1) {

    std::vector<double> input_data_read_in;
    std::ifstream datafile;
    std::string line;
    std::string field;
    int filelength = 0;

    datafile.open(file_location);
    if (datafile.fail() ) {
      std::cout << "ERROR: Could not open datafile." << std::endl;
      exit(1);
    }
   
    std::cout << "Path to datafile being read: \n" << file_location << std::endl; 
    if (print_flag) {
    std::cout << "The lines read-in from the datafile will be printed " \
    "to this terminal in raw format (plain text)." << std::endl;
    do {
        std::cout << "Press Enter to continue..." << std::endl;
    } while (std::cin.get() != '\n');
    std::cin.get();
    }
   
    while (getline(datafile, line)) {
        filelength++;
        std::stringstream ss(line);
        double f; 
        ss >> f;
        input_data_read_in.push_back(f);
        if (print_flag) {std::cout << line << std::endl;}
    } 

   if (print_flag) {
   std::cout << "Number of lines read from file: " << filelength << "\n" << std::endl;
   }
   datafile.close();

   return input_data_read_in;

};

/*
###################
//Data Import
###################
*/ 

void CustomFunction::set_nCB_Vars(double n, double a, double s) {

    nCB_vars.n = n;
    nCB_vars.a = a;
    nCB_vars.s = s;

    nCB_vars.A = (pow((n/a),n))*exp(-((a*a)/2));
    nCB_vars.B = (n/a)-a;
    nCB_vars.C = (n/a)*(1/(n-1))*exp(-((a*a)/2));
    nCB_vars.D = sqrt(M_PI_2)*(1+std::erf(a/1.4142135624));
    nCB_vars.N = 1/(s*(nCB_vars.C+nCB_vars.D));

}

/*
###################
//Distribution Functions
###################
*/ 

double CustomFunction::normdist(double x) {
    // Sigma = 4, Mu = 1
    return (1.0/(4.0*(sqrt(2*M_PI))))*\
    exp((-1.0/2.0)*(((x-1.0)/1.0)*((x-1.0)/4.0)));
};

double CustomFunction::CLdist(double x) {
    // Gamma = 1, x_0 = 1
    return (1.0/(M_PI*2.0*(1.0+(((x-1.0)/2.0)*((x-1.0)/2.0)))));
};

double CustomFunction::nCBdist(double x) {
    if ( ((x-nCB_vars.x_avg)/nCB_vars.s) <= -nCB_vars.a ){
        return (nCB_vars.A*pow((nCB_vars.B-((x-nCB_vars.x_avg)/nCB_vars.s)),-nCB_vars.n));
    } else {
        return (exp(-((x-nCB_vars.x_avg)*(x-nCB_vars.x_avg))/(2*nCB_vars.s*nCB_vars.s)));
    }
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