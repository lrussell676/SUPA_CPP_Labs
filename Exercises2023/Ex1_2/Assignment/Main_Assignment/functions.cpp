/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"

/* ---- Opening a text file containing (x,y) Data, Saves to 2D vector -----------------------------
   --------- Corresponds to: STEPS 1,   Main Assignment (partially) -------------------------------
   ------------------------- STEPS 1-2, Instructions ------------------------------------------- */


std::vector<std::vector<double>> read_data_from_file(
    std::string file_location) {

    std::vector<std::vector<double>> input_data_read_in(2);
    std::ifstream datafile;
    std::string line;
    std::string field;
    int filelength = 0;
    int data_point_count = 0;

    datafile.open(file_location);
    if (datafile.fail() ) {
      std::cout << "ERROR: Could not open datafile." << std::endl;
      exit(1);
    }
   
    std::cout << "Path to datafile being read: \n" << file_location << std::endl; 
    std::cout << "The lines read-in from the datafile will be printed " \
    "to this terminal in raw format (plain text)." << std::endl;
    do {
        std::cout << "Press Enter to continue..." << std::endl;
    } while (std::cin.get() != '\n');
    std::cin.get();
   
    while ( !datafile.eof() ){
        if ( !datafile.eof() ){
            filelength++;
            getline(datafile, line);
            std::stringstream ss(line);
            std::cout << line << std::endl;
            int axis_count = 0;
            while (getline( ss, field, ',')) {
                std::stringstream fs( field );
                char str[16];
                fs >> str;
                if (std::isdigit(str[0])) {
                    std::stringstream fs( field );
                    float f; 
                    fs >> f;
                    if (axis_count==0) {
                       input_data_read_in[0].push_back(f);
                    } else {
                       input_data_read_in[1].push_back(f);
                       data_point_count += 1;
                    }
                }
                axis_count = 1;
            }
        } 
    }

   std::cout << "Number of lines read from file: " << filelength << std::endl;
   std::cout << "Number of (x,y) data points returned: " << data_point_count << std::endl;
   datafile.close();

   return input_data_read_in;

}

/* ---- Calculates magnitude of 2D vectors as ((0,0),(x,y)) ---------------------------------------
   --------- Corresponds to: STEPS 2,   Main Assignment -------------------------------------------
   ------------------------- STEPS 4,   Instructions ------------------------------------------- */

std::vector<double>  calc_magnitude(std::vector<std::vector<double>>& 
    data_vec) {

    int n = data_vec[0].size();
    std::vector<double> mag_vec(n);

    double x, y, v;

    for (int i=0; i<n; i++) {
        x = data_vec[0][i]*data_vec[0][i];
        y = data_vec[1][i]*data_vec[1][i];
        v = sqrt(x+y);
        mag_vec[i] = v;
    }

    return mag_vec;
}