#include<iostream>
#include"ProbabilityDistribution.h"

using namespace std;

void ChiSquareTest(int, int, float *, float *, float *);

int main()
{   
    const int size = 5, df = 5;

    float measurement[] = {1.0285, 1.0121, 0.9893, 0.4796, 0.3891};
    float estimatedMeasurements[] = {0.9999, 0.9886, 0.9833, 0.4856, 0.3821};
    double covarianceMatrix[][size] = {{0.00004637, 0,0,0,0},
                                       {0,0.00003285,0,0,0},
                                       {0,0, 0.000006805,0,0},
                                       {0,0,0, 0.000006805,0},
                                       {0,0,0,0, 0.0000405}};

    double *cmPtr = covarianceMatrix[0];                                       

    ChiSquareTest(size, df, measurement, estimatedMeasurements, cmPtr);

    return 0;
}

<<<<<<< HEAD
void ChiSquareTest(int size, int df, float *v){
    ProbabilityDistribution X2(size);
    
    X2.setValues(v);    
    X2.setDistribution(size);
=======
void ChiSquareTest(int size, int df, float *measurement, float* mEstimated, double *covarianceMatrix){
    ProbabilityDistribution X2(size,df);

    X2.setValues(measurement, mEstimated, covarianceMatrix);    
    X2.setDistribution();
>>>>>>> patch_1
    float d = X2.getDistribution();
    X2.setCumulativeDistributionFunction(0, d);
    X2.print();

    float test = X2.getCumulativeDistributionFunction();
    const float confidenceLevel = 0.99;

    cout << endl
         << "Nivel de confianca: " << confidenceLevel << endl << endl;

    if(test > confidenceLevel){
        cout << endl 
             << "Erro Detectado" << endl;
    }
    else{
        cout << endl 
             << "Nao ha erro no conjunto de medicoes" << endl << endl;
    }
}

