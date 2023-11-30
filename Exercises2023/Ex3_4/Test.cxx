#include "CustomFunctions.h"

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

    /* --- Importing Data -------------------- */
    std::string data_path = "Outputs/data/MysteryData03211.txt";
    std::vector<double> points = read_data_from_file(data_path,0);

    /* --- Obtaining min-max Values ---------- */
    std::vector<double>::iterator m_RMin = \
        std::min_element(std::begin(points),std::end(points));
    std::vector<double>::iterator m_RMax = \
        std::max_element(std::begin(points),std::end(points));
    
    /* --- Initialising FiniteFunctions ------ */
    FiniteFunction FinFunc(*m_RMin,*m_RMax,"./Outputs/png/InvXsq03211.png");

    //int n = points.size();
    //std::cout << n << std::endl;
    
    FinFunc.plotFunction();
    FinFunc.plotData(points,100);

    FinFunc(*m_RMin,*m_RMax,"./Outputs/png/NormDist03211.png");

    int *dist_flag = 0;
    FinFunc.plotFunction();
    FinFunc.plotData(points,100);

}