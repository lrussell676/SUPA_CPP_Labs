/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"
#include "aux_cli_messages.cpp"

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

/* ---- Print condition for vector magnitudes of 2D data ------------------------------------------
   --------- Corresponds to: STEPS 2,   Main Assignment -------------------------------------------
   ------------------------- STEPS 5-6, Instructions ------------------------------------------- */

void print_condition_vec_mag(std::vector<double> vec_mag) {
    std::cout << "\nAfter calculating the magnitude of these vectors, would you like " \
   "these \nprinted to the terminal as well? (type \"y\" for yes, or " \
   "enter any other \nkey to continue with calculation only)."
   << std::endl;

   std::string in;
   std::cin >> in;

   int n;

   if (in == "y") {
      std::cout << "Ok, here are the calculated vector magnitudes. But first,\n" \
      "Please specify an INTEGER value of lines " \
      "you wish to print:" << std::endl;
      std::cin >> n;
      if ( n > vec_mag.size() ) {
         std::cout << "WARNING: your value of \'n\' is larger than the number " \
         "of data points within this vector. \nOnly the first 5 data points " \
         "will be printed to the terminal." << std::endl;
         do {
            std::cout << "Press Enter to continue..." << std::endl;
         } while (std::cin.get() != '\n');
         std::cin.get();
         n = 5;
         for (int i=0; i<n; i++) {
            std::cout << vec_mag[i] << std::endl;
         }
      } else {
         std::cout << "Ok, " << n << " vector magnitudes will now sequentially be " \
        "printed to the terminal." << std::endl;
        do {
            std::cout << "Press Enter to continue..." << std::endl;
        } while (std::cin.get() != '\n');
        std::cin.get();
         print_mag_calc(vec_mag,n);
      }
   } else {
        std::cout << "Ok, the calculated vector magnitudes have just been stored." 
        << std::endl;
   }
}

/* ---- Least Squares Method Calc -----------------------------------------------------------------
   --------- Corresponds to: STEPS 3,   Main Assignment (partially) -------------------------------
   ------------------------- STEPS 7,   Instructions (partially) ---------------------------------- */

std::vector<std::vector<double>> LSM_chi2_xy_data_calc(std::vector<std::vector<double>>
    data_vec) {

    int n = data_vec[0].size();

    std::vector<double> row(2,0);
    std::vector<std::vector<double>> LSM_xy_data(n,row);

    double sum_xy, sum_x, sum_y, sum_xx;

    for (int i=0; i<n; i++) {
        sum_x += data_vec[0][i];
        sum_y += data_vec[1][i];
        sum_xx += (data_vec[0][i]*data_vec[0][i]);
        sum_xy += data_vec[0][i]*data_vec[1][i];
    }

    double p = ( ((n*sum_xy)-(sum_x*sum_y)) / \
                 ((n*sum_xx)-(sum_x*sum_x)) );
    
    double q = ( ((sum_xx*sum_y)-(sum_xy*sum_x)) / \
                 ((n*sum_xx)-(sum_x*sum_x)) );

    for (int i=0; i<n; i++) {
        LSM_xy_data[0][i] = data_vec[0][i];
        LSM_xy_data[1][i] = (p*data_vec[0][i] + q);
        std::cout << LSM_xy_data[0][i] << " " << LSM_xy_data[1][i] << std::endl; 
    }
    
    std::cout << "HERE?" << std::endl;

    return LSM_xy_data;
}