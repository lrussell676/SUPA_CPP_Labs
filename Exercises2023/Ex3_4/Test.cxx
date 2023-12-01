/* ------------------------------------------------------------------------------------------------
   -------------------------- Author: Lewis Russell : SUPACOO Class Student -----------------------
   --------------------------------------------------------------------------------------------- */

#include <numeric>
#include "CustomFunctions.h"

int main() {

    /* --- Importing Data ------------------------ */
    std::string data_path = "Outputs/data/MysteryData03211.txt";
    CustomFunction CusFunc;
    std::vector<double> points = CusFunc.read_data_from_file(data_path,0);

    /* --- Obtaining min-max Values -------------- */
    std::vector<double>::iterator m_RMin = \
        std::min_element(std::begin(points),std::end(points));
    std::vector<double>::iterator m_RMax = \
        std::max_element(std::begin(points),std::end(points));
    
    /* --- Initialising FiniteFunctions ---------- */
    /* --- Inverse x-Squared --------------------- */
    FiniteFunction FinFunc1(*m_RMin,*m_RMax,"./Outputs/png/1-InvXsq03211.png");
    FinFunc1.plotFunction();
    FinFunc1.plotData(points,100);

    /* --- Initialising CustomFunctions ---------- */
    /* --- Normal Distribution ------------------- */
    CustomFunction CusFunc1(*m_RMin,*m_RMax,"./Outputs/png/2-NormDist03211.png");
    CusFunc1.dist_flag = 0;
    CusFunc1.plotFunction();
    CusFunc1.plotData(points,100);

    /* --- Initialising CustomFunctions ---------- */
    /* --- Cauchy-Lorentz Distribution ----------- */
    CustomFunction CusFunc2(*m_RMin,*m_RMax,"./Outputs/png/3-CLDist03211.png");
    CusFunc2.dist_flag = 1;
    CusFunc2.plotFunction();
    CusFunc2.plotData(points,100);

    /* --- Initialising CustomFunctions ---------- */
    /* --- Negative Crystall Ball Distribution --- */
    CustomFunction CusFunc3(*m_RMin,*m_RMax,"./Outputs/png/4-nCBDist03211.png");
    CusFunc3.nCB_vars.x_avg = std::reduce(points.begin(), points.end(), 0.0) / points.size();
    CusFunc3.set_nCB_Vars(2.0, 0.5, 1.2);
    CusFunc3.dist_flag = 2;
    CusFunc3.plotFunction();
    CusFunc3.plotData(points,100);

}