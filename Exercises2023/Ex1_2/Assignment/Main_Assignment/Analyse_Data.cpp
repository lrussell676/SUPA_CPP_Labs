/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   ------------------------------------------------------------------------------------------------

   This main file contains my code for the Main Assignment for Labs 1-2, 15/11/23 and 
   22/11/23. I have decided to split my code amongst several files as follows:

   "directives.h" ----------- Simply a header file containing compiler directives. This 
                              prevents me having to include them across multiple files.
   "functions.cpp" ---------- Contains the functions most relevant to the assignment.
   "aux_cli_messages.cpp" --- An extra file designated for CLI prompts.
   
   This is probably overkill for the assignment, although I think makes for
   good practice regarding larger codebases. ------------------------------------------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"
#include "functions.cpp"

/* ---- Complete Execution --------------------------------------------------------------------- */

int main() {

   std::string input_path = opening_message();

   /* ---- Main Assignment, STEP 1. Instructions, STEPS 1-3 ------------------ */

   std::vector<std::vector<double>> input_2D_xy_data;
   input_2D_xy_data = read_data_from_file(input_path);

   std::cout << "(x,y) data points now contained in 2D vector \"input_2D_xy_data\".\n" \
   << std::endl;
   
   print_input_2D_vector(input_2D_xy_data);

   /* ---- Main Assignment, STEP 2. Instructions, STEPS 4-6 ------------------ */

   std::vector<double> mag_1D_vec;
   mag_1D_vec = calc_magnitude(input_2D_xy_data);

   print_condition_vec_mag(mag_1D_vec);

   /* ---- Main Assignment, STEP 3. Instructions, STEPS 7-9 ------------------ */

   print_message_LSM_chi2();

   double p, q, chi2;
   
   std::vector<std::vector<double>> LSM_xy_data;
   LSM_xy_data = LSM_chi2_xy_data_calc(input_2D_xy_data, p, q, chi2);

   /* ---- Main Assignment, STEP 4. Instructions, STEPS 10 ------------------- */

   print_message_x_pow_y();

   std::vector<double> x_pow_y_1D_vec;
   x_pow_y_1D_vec = x_pow_y_calc(input_2D_xy_data);

   std::cout << "The values of \"x**y\" now contained in 1D vector \"x_pow_y_1D_vec\".\n" \
   << std::endl;

   /* ---- Main Assignment, STEP 5. Instructions, STEPS 11-12----------------- */

   std::cout << "\\* -------------------------------------------------------------------\n" << \
                "--------------------- All Calculations Completed ---------------------\n" << \
                "------------------------------------------------------------------- *\\" << \
                std::endl;

   std::cout << "\nThe program can either now be terminated, or calculated data can be\n" \
                "written to .txt file outputs. The files will be written to the relative\n" \
                "path associated to this program directory using the format:\n" \
                "\"./output_*.txt\"\n\n" << std::endl;

   char op;
   std::string output_file_path;

   while(op != 'x'){
      std::cout << "Please select write to file options: " << std::endl;
      std::cout << "1 ---> All Data" << std::endl;
      std::cout << "2 ---> Magnitude of Vectors Data Only" << std::endl;
      std::cout << "3 ---> LSM and Chi-squared Data Only" << std::endl;
      std::cout << "4 ---> (x**y) Data Only" << std::endl;
      std::cout << "x ---> Exit Program" << std::endl;

      std::cin >> op;

      switch(op){
         case '1':
            std::cout << "case 1" << std::endl;
            break;
         case '2':
            std::cout << "case 2" << std::endl;
            break;
         case '3':
            std::cout << "case 3" << std::endl;
            break;
         case '4':
            std::cout << "case 4" << std::endl;
            break;
         case 'x':
            std::cout << "Ok, Exiting Program....." << std::endl;
            exit(1);
         default:
            std::cout << "ERROR: Unexpected Input: " << op << ":" << int(op) << std::endl;
            continue;
      }
   }

}