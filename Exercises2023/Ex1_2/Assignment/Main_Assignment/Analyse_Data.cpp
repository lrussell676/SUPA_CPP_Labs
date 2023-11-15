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
#include "aux_cli_messages.cpp"

/* ---- Complete Execution --------------------------------------------------------------------- */

int main() {

   std::string input2D = opening_message();

   /* ---- Main Assignment, STEP 1. Instructions, STEPS 1-3 ------------------ */

   std::vector<std::vector<double>> input_2D_xy_data;
   
   input_2D_xy_data = read_data_from_file(input2D);

   std::cout << "(x,y) data points now contained in 2D vector \"input_2D_xy_data\".\n" \
   << std::endl;
   
   print_input_2D_vector(input_2D_xy_data);

   /* ---- Main Assignment, STEP 2. Instructions, STEPS 4-5 ------------------ */

   std::vector<double> mag_1D_vec;
   mag_1D_vec = calc_magnitude(input_2D_xy_data);
   int n;

   std::cout << "After calculating the magnitude of these vectors, would you like " \
   "these \nprinted to the terminal as well? (type \"y\" for yes, or " \
    "enter any other \n key to continue with calculation only)."
   << std::endl;

   std::string in;
   std::cin >> in;

   if (in == "y") {
      std::cout << "Ok, here are the calculated vector magnitudes. But first,\n" \
      "Please specify an INTEGER value of lines " \
      "you wish to print:" << std::endl;
      std::cin >> n;
      if ( n > mag_1D_vec.size() ) {
         std::cout << "WARNING: your value of \'n\' is larger than the number " \
         "of data points within this vector. \nOnly the first 5 data points " \
         "will be printed to the terminal." << std::endl;
         do {
            std::cout << "Press Enter to continue..." << std::endl;
         } while (std::cin.get() != '\n');
         std::cin.get();
         n = 5;
         for (int i=0; i<n; i++) {
            std::cout << mag_1D_vec[i] << std::endl;
         }
      } else {
         std::cout << "Ok, " << n << " vector magnitudes will now sequentially be " \
        "printed to the terminal." << std::endl;
        do {
            std::cout << "Press Enter to continue..." << std::endl;
        } while (std::cin.get() != '\n');
        std::cin.get();
         print_mag_calc(mag_1D_vec,n);
      }
   } else {
        std::cout << "Ok, the calculated vector magnitudes have just been stored." 
        << std::endl;
   }


}