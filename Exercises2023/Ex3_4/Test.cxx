#include <iostream>
#include <string>
#include <vector>
#include "FiniteFunctions.h"
#include <filesystem> //To check extensions in a nice way

#include "gnuplot-iostream.h" //Needed to produce plots (not part of the course) 

using std::filesystem::path;

std::vector<double> read_data_from_file(
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

}

int main() {

    std::string data_path = "Outputs/data/MysteryData03211.txt";
    std::vector<double> points = read_data_from_file(data_path,0);
    
    FiniteFunction FinFunc(-5.0,5.0,"Outputs/png/Test_Out.png");

    int n = points.size();
    std::cout << n << std::endl;
    
    FinFunc.plotData(points,50);

}