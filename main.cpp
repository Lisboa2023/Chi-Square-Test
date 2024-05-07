#include<iostream>
#include"ProbabilityDistribution.h"

using namespace std;

int main()
{   
    const int size = 5, df = 4;

    const float measurement[] = {1.0, 1.2, 1.6, 1.0, 0.9};
    const float estimatedMeasurements[] = {0.5, 2.4, 0.8, 0.8, 4.0};
    const double covarianceMatrix[][size] = {{1, 0,0,0,0},
                                             {0,1,0,0,0},
                                             {0,0,1,0,0},
                                             {0,0,0,1,0},
                                             {0,0,0,0,1}};

    const double *cmPtr = covarianceMatrix[0];                                       

    ProbabilityDistribution X2(size,df);
    X2.ChiSquareTest(size, df, measurement, estimatedMeasurements, cmPtr);

    return 0;
}



