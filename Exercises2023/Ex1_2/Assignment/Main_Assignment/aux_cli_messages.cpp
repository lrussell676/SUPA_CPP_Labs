/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include "directives.h"

/* ---- Somewhat arbitrary opening message ----------------------------------------------------- */

std::string opening_message() {

    std::string input2D = "/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt";

    std::cout << "Hello!\nThis script is designed to auto import 2D data by default from:\n" << \
    input2D << "\nWould you like to change this path? (type \"y\" only to change,\n" \
    "or enter any other key to continue with default path)." << std::endl;
    
    std::string in;
    std::cin >> in;

    if (in == "y") {
        std::cout << "Ok, please type the desired path:" << std::endl;
        std::cin >> input2D;
        std::cout << "Ok, will now attempt to use input data from path:\n" << \
        input2D << std::endl;
    } else {
        std::cout << "Ok, using default path...." << std::endl;
    }
    return input2D;
}

/* ---- STEP 3 FROM INSTRUCTIONS --------------------------------------------------------------- */

void print_input_2D_vector(std::vector<std::vector<double>> data_vec) {

    int n;

    std::cout << "The x,y data within this vector will now be printed " \
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