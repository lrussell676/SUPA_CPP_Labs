/* --------------------------------------------------------------------------------------
   This file contains my code for the Preliminary Section of the assignment, steps 1-3.
   I have decided to split each Step into its own function, which are all executed
   within "int main()" - this is overkill for the example, although I think makes for
   good practice for larger codebases. ----------------------------------------------- */

#include <iostream>
#include <cmath>

/* ---- Step 1 : Printing "Hello World!" on the terminal upon execution -------------- */

void CLI_Hello_World() {
    std::cout << "Hello World!" << std::endl;
}

/* ---- Step 2 : Compile-time Vector Magnitude Calculation --------------------------- */

void Compiled_Vector_Calc() {

    double x, y, v;
    x = 2.3;
    y = 4.5;
    v = sqrt(x*x + y*y);

    std::cout << "The vector of x = " << x << " and y = " << y << " is " 
        << v << std::endl;
    
}

/* ---- Step 3 : Run-time Vector Magnitude Calculation, with User CLI Input ---------- */

void Runtime_Vector_Calc() {

    double x, y, v;

    std::cout << "Now choose your own values for x and y:" << std::endl;
    std::cout << "x = ?" << std::endl;
    std::cin >> x;
    std::cout << "y = ?" << std::endl;
    std::cin >> y;

    v = sqrt(x*x + y*y);

    std::cout << "The vector of x = " << x << " and y = " << y << " is " 
        << v << std::endl;
    
}

/* ---- Complete Execution of Steps 1-3 ---------------------------------------------- */

int main() {
    CLI_Hello_World();
    Compiled_Vector_Calc();
    Runtime_Vector_Calc();
    return 0;
}