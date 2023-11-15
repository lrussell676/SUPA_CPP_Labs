/* ----------------------------------------------------------------------------------------
   This file contains my code for the Main Assignment for Labs 1-2, 15/11/23 and 22/11/23.
   I have decided to split each Step into its own function, which are all executed
   within "int main()" - this is overkill for the example, although I think makes for
   good practice for larger codebases. ------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

//double x_read_in, y_read_in;

/* ---- Step 1 : Opening a text file containing (x,y) Data ----------------------------- */

std::vector<std::vector<double>> read_data_from_file(
   std::string file_location=
   "/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt") {

   std::ifstream datafile;
   int filelength = 0;
   std::string line;
   std::string field;
   std::vector<std::vector<double>> input_data_read_in(2);
   int data_point_count = 0;

   datafile.open(file_location);
   if (datafile.fail() ) {
      std::cout << "ERROR: Could not open datafile." << std::endl;
      exit(1);
   }

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
               float f;  // (default value is 0.0)
               fs >> f;
               //std::cout << f << " " << typeid(f).name() << std::endl;
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

   //for (int i=0; i<data_point_count; i++) {
   //   std::cout << input_data_read_in[0][i] << " " << input_data_read_in[1][i] << std::endl;
   //}

   std::cout << "Number of lines read from file: " << filelength << std::endl;
   std::cout << "Number of (x,y) data points returned: " << data_point_count << std::endl;
   datafile.close();

   return input_data_read_in;

}


/* ---- Complete Execution ------------------------------------------------------------- */

int main() {

   std::vector<std::vector<double>> input_2D_xy_data;
   
   input_2D_xy_data = read_data_from_file();
}