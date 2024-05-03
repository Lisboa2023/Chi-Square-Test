#include<iostream>
#include"ProbabilityDistribution.h"

using namespace std;

void ChiSquareTest(int, int, float *);

int main()
{   
    const int size = 5, df = 5;

    float *v = new float[size];

    // ChiSquareTest(size, df, v);

    delete [] v;
    return 0;
}

void ChiSquareTest(int size, int df, float *values, float *measurement, float* mEstimated, double *covarianceMatrix[]){
    ProbabilityDistribution X2(size);
    
    X2.setValues(values, measurement, mEstimated, covarianceMatrix,size);    
    X2.setDistribution(size);
    float d = X2.getDistribution();
    X2.setCumulativeDistributionFunction(0, d, df);
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

