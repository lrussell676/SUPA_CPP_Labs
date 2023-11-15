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
}