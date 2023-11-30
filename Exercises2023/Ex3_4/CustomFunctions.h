#include "FiniteFunctions.h"

#pragma once

class CustomFunction : public FiniteFunction {

    protected:

        int dist_flag;

        double normdist(double x);
        double CLdist(double x);
        double nCBdist(double x);

        double callFunction(double x) override;

};