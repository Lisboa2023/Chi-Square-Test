#ifndef CHISQUAREDISTRIBUTION_H
#define CHISQUAREDISTRIBUTION_H

#include"ProbabilityDistribution.h"

class ChiSquareDistribution:public ProbabilityDistribution{
    public:
        ChiSquareDistribution(int, int);

        // Funções SET
        void setDegreeOfFreedom(int);
        virtual void setDistribution(int);
        virtual void setProbabilityDensityFunction(double);

    private:
        int DF;
};

#endif


