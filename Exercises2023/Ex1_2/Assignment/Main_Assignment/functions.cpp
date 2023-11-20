/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"
#include "aux_cli_messages.cpp"

/* ---- Opening a text file containing (x,y) Data, Saves to 2D vector -----------------------------
   --------- Corresponds to: STEPS 1,   Main Assignment (partially) -------------------------------
   ------------------------- STEPS 1-2, Instructions ------------------------------------------- */


std::vector<std::vector<double>> read_data_from_file(
    std::string file_location, int print_flag = 1) {

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
    if (print_flag) {
    std::cout << "The lines read-in from the datafile will be printed " \
    "to this terminal in raw format (plain text)." << std::endl;
    do {
        std::cout << "Press Enter to continue..." << std::endl;
    } while (std::cin.get() != '\n');
    std::cin.get();
    }
   
    while ( !datafile.eof() ){
        if ( !datafile.eof() ){
            filelength++;
            getline(datafile, line);
            std::stringstream ss(line);
            if (print_flag) {std::cout << line << std::endl;}
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

   if (print_flag) {
   std::cout << "Number of lines read from file: " << filelength << std::endl;
   std::cout << "Number of (x,y) data points returned: " << data_point_count << std::endl;
   }
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

/* ---- Least Squares Method and Chi-squared Calc -------------------------------------------------
   --------- Corresponds to: STEPS 3,   Main Assignment (partially) -------------------------------
   ------------------------- STEPS 7,   Instructions (partially) ------------------------------- */

std::vector<std::vector<double>> LSM_chi2_xy_data_calc(std::vector<std::vector<double>>
    data_vec, double& p, double& q, double& chi2) {

   int n = data_vec[0].size();

   std::vector<double> row(n,0);
   std::vector<std::vector<double>> LSM_xy_data(2,row);

   /* ---- Least Squares Method -------------------------- */

   double sum_xy, sum_x, sum_y, sum_xx;

   for (int i=0; i<n; i++) {
      sum_x += data_vec[0][i];
      sum_y += data_vec[1][i];
      sum_xx += data_vec[0][i]*data_vec[0][i];
      sum_xy += data_vec[0][i]*data_vec[1][i];
   }

   p = ( ((n*sum_xy)-(sum_x*sum_y)) / \
                ((n*sum_xx)-(sum_x*sum_x)) );
    
   q = ( ((sum_xx*sum_y)-(sum_xy*sum_x)) / \
                ((n*sum_xx)-(sum_x*sum_x)) );

   for (int i=0; i<n; i++) {
      LSM_xy_data[0][i] = data_vec[0][i];
      LSM_xy_data[1][i] = (p*data_vec[0][i] + q); 
   }

   /* ---- Chi**2 ---------------------------------------- */

   std::string error_path = LSM_chi2_error_file_path();

   std::vector<std::vector<double>> error_data;
   error_data = read_data_from_file(error_path, 0/*print_flag*/);

   //for (int i=0; i<n; i++) {
   //     std::cout << error_data[0][i] << " " << error_data[1][i] << std::endl;
   //}

   /* observed */
   double obs_i;
   /* expected */
   double exp_i;

   for (int j=0; j<2; j++) {
      for (int i=0; i<n; i++) {
         obs_i = (data_vec[j][i] - LSM_xy_data[j][i]) ;
         exp_i = error_data[j][i];
         chi2 += ( (( obs_i - exp_i )* \
                    ( obs_i - exp_i )) / \
                  //  ( exp_i*exp_i )) ;
                    ( exp_i )) ;
      }
   }

   chi2 = chi2/(2*n);

   std::cout << "\n\\* -------- LSM,Chi**2 Results -------- *\\" << std::endl;
   std::cout << "LSM Eq of Line: y = " << p <<"x + " << q << std::endl;
   std::cout << "Chi-Squared = " << chi2 << std::endl;
   std::cout << "\\* ------------------------------------ *\\\n" << std::endl;

   return LSM_xy_data;
}

/* ---- Calculates magnitude of 2D vectors as ((0,0),(x,y)) ---------------------------------------
   --------- Corresponds to: STEPS 4,   Main Assignment -------------------------------------------
   ------------------------- STEPS 10,  Instructions ------------------------------------------- */

std::vector<double>  x_pow_y_calc(std::vector<std::vector<double>>& 
    data_vec) {

    int n = data_vec[0].size();
    std::vector<double> x_pow_y(n);

    double x, y, y_int, pow;

    for (int i=0; i<n; i++) {
      x = data_vec[0][i];
      y = std::round(data_vec[1][i]);
      y_int = int(y);
      pow = exp(y*log(x));
      x_pow_y[i] = pow;
    }

    return x_pow_y;

}

/* ---- Handles writting data to files ------------------------------------------------------------
   --------- Corresponds to: STEPS 5,   Main Assignment -------------------------------------------
   ------------------------- STEPS 11-12,  Instructions ---------------------------------------- */

/* 1D Vector Write to File */
void write_to_file(std::string file_write_path, std::vector<double>&);
void write_to_file(std::string file_write_path, std::vector<double>& data_vec_1D) {

   std::ofstream file_out;

   file_out.open(file_write_path);

   if (file_out.fail()) {
      std::cout << "ERROR: Cound not open or write to file.\n" << std::endl;
   } else {
      int n = data_vec_1D.size();
      for (int i=0; i<n; i++) {
         file_out << data_vec_1D[i] << std::endl;
      }
   file_out.close();
   std::cout << "Successful write to file!\n" << std::endl;
   }

}

/* 2D Vector Write to File */
void write_to_file(std::string file_write_path, std::vector<std::vector<double>>&, \
                  double&, double&, double&);
void write_to_file(std::string file_write_path, std::vector<std::vector<double>>& \
                  data_vec_2D, double& p, double& q, double& chi2) {

   std::ofstream file_out;

   file_out.open(file_write_path);

   if (file_out.fail()) {
      std::cout << "ERROR: Cound not open or write to file.\n" << std::endl;
   } else {

      file_out << "LSM Equation of Line: y = " << p <<"x + " << q << std::endl;
      file_out << "Chi-Squared = " << chi2 << std::endl;
      file_out << "\nLSM Data Points (x \\t \\t y):\n" <<std::endl;

      int n = data_vec_2D[1].size();

      for (int i=0; i<n; i++) {
         file_out << data_vec_2D[0][i] << "\t\t" << data_vec_2D[1][i] << std::endl;
      }

   file_out.close();
   std::cout << "Successful write to file!\n" << std::endl;
   }
   
}