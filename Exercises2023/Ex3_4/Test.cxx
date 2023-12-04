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

    /* -------------------------------------------------------------------------- */
    /* --- Task 2, Main Assignment, Plotting Functions -------------------------- */
    /* -------------------------------------------------------------------------- */
    
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

    /* -------------------------------------------------------------------------- */
    /* --- Task 2.1, Sampling --------------------------------------------------- */
    /* -------------------------------------------------------------------------- */

    std::size_t sample_data_size = 100000;

    std::vector<double> Msteps_pts_ND(sample_data_size);
    std::vector<double> Msteps_pts_CL(sample_data_size);
    std::vector<double> Msteps_pts_nCB(sample_data_size);

    CusFunc1.LinearSpacedArray(Msteps_pts_ND, *m_RMin, *m_RMax, sample_data_size);
    CusFunc2.LinearSpacedArray(Msteps_pts_CL, *m_RMin, *m_RMax, sample_data_size);
    CusFunc3.LinearSpacedArray(Msteps_pts_nCB, *m_RMin, *m_RMax, sample_data_size);

    for (int i=0; i<sample_data_size; i++) {
        Msteps_pts_ND[i] = CusFunc1.callFunction(Msteps_pts_ND[i]);
        Msteps_pts_CL[i] = CusFunc2.callFunction(Msteps_pts_CL[i]);
        Msteps_pts_nCB[i] = CusFunc3.callFunction(Msteps_pts_nCB[i]);
    }

    std::cout << "Calculating Metropolis Algorithms. This takes a moment...." << std::endl;

    for (int i=0; i<sample_data_size; i++) {
        Msteps_pts_ND[i+1] = CusFunc1.Mstep(Msteps_pts_ND[i], *m_RMin, *m_RMax);
        Msteps_pts_CL[i+1] = CusFunc2.Mstep(Msteps_pts_CL[i], *m_RMin, *m_RMax);
        Msteps_pts_nCB[i+1] = CusFunc3.Mstep(Msteps_pts_nCB[i], *m_RMin, *m_RMax);
    }

    CusFunc1.plotData(Msteps_pts_ND,100,false);
    CusFunc2.plotData(Msteps_pts_CL,100,false);
    CusFunc3.plotData(Msteps_pts_nCB,100,false);

    std::cout << "\\* ------------------------------------------- *\\" << std::endl;
    std::cout << "END OF PROGRAM: Generated graphs can be found at;" << std::endl;
    std::cout << "Exercises2023/Ex3_4/Outputs/png/*.png" << std::endl;

}