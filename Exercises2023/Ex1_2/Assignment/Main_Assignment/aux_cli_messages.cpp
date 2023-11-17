/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"

/* ---- Somewhat arbitrary opening message ----------------------------------------------------- */

std::string opening_message() {

    std::string input_path = "/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt";

    std::cout << "Hello!\nThis script is designed to auto import 2D data by default from:\n" << \
    input_path << "\nWould you like to change this path? (type \"y\" only to change,\n" \
    "or enter any other key to continue with default path)." << std::endl;
    
    std::string in;
    std::cin >> in;

    if (in == "y") {
        std::cout << "Ok, please type the desired path:" << std::endl;
        std::cin >> input_path;
        std::cout << "Ok, will now attempt to use input data from path:\n" << \
        input_path << std::endl;
    } else {
        std::cout << "Ok, using default path...." << std::endl;
    }
    return input_path;
}

/* ---- STEP 3 FROM INSTRUCTIONS --------------------------------------------------------------- */

void print_input_2D_vector(std::vector<std::vector<double>> data_vec) {

    int n;

    std::cout << "The (x,y) data within this vector will now be printed " \
        "to this terminal. \nPlease specify an INTEGER value of lines " \
        "you wish to print:" << std::endl;
    std::cin >> n;
    if ( n > data_vec[0].size() ) {
        std::cout << "WARNING: your value of \'n\' is larger than the number " \
        "of data points within this vector. \nOnly the first 5 data points " \
        "will be printed to the terminal." << std::endl;
        do {
            std::cout << "Press Enter to continue..." << std::endl;
        } while (std::cin.get() != '\n');
        std::cin.get();
        n = 5;
        for (int i=0; i<n; i++) {
            std::cout << data_vec[0][i] << " " << data_vec[1][i] << std::endl;
        }
    } else {
        std::cout << "Ok, " << n << " (x,y) data points will now sequentially be " \
        "printed to the terminal." << std::endl;
        do {
            std::cout << "Press Enter to continue..." << std::endl;
        } while (std::cin.get() != '\n');
        std::cin.get();
        for (int i=0; i<n; i++) {
            std::cout << data_vec[0][i] << " " << data_vec[1][i] << std::endl;
        }
    }
}

/* ---- Print condition for vector magnitudes of 2D data ------------------------------------------
   --------- Corresponds to: STEPS 2,   Main Assignment -------------------------------------------
   ------------------------- STEPS 5-6, Instructions ------------------------------------------- */

void print_mag_calc(std::vector<double> mag_print, int n){
    for (int i=0; i<n; i++) {
            std::cout << mag_print[i] << std::endl;
        }
}

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

/* ---- STEPS 3 MAIN ASSIGNMENT ---------------------------------------------------------------- */

void print_message_LSM_chi2() {
    std::cout << "\nUsing the provided (x,y) input data, a straight line will be fitted \n" \
    "using the Least Squares Method, and the goodness of this fit assessed \n" \
    "via a chi-squared calculation." << std::endl;
    do {
        std::cout << "Press Enter to continue..." << std::endl;
    } while (std::cin.get() != '\n');
    std::cin.get();
}

std::string LSM_chi2_error_file_path(){

    std::string input_path = "/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/error2D_float.txt";

    std::cout << "The calculation of chi-squared relies of inputted expected error\n" \
    "measurement data. This script is designed to auto import 2D data by default from:\n" << \
    input_path << "\nWould you like to change this path? (type \"y\" only to change,\n" \
    "or enter any other key to continue with default path)." << std::endl;
    
    std::string in;
    std::cin >> in;

    if (in == "y") {
        std::cout << "Ok, please type the desired path:" << std::endl;
        std::cin >> input_path;
        std::cout << "Ok, will now attempt to use input data from path:\n" << \
        input_path << std::endl;
    } else {
        std::cout << "Ok, using default path...." << std::endl;
    }
    return input_path;
}