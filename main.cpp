#include<iostream>
#include"ChiSquareDistribution.h"

using namespace std;

void ChiSquareTest(int, int, float *);

int main()
{   
    int size, df = 5;

    cout << "Insira a quantidade de valores: ";
    cin >> size;

    float *v = new float[size];

    for (int i = 0; i < size; i++){
        cout << "Insira o valor de x[" << i+1 << "]: ";
        cin >> *(v+i); 
    }

    ChiSquareTest(size, df, v);

    return 0;
}

void ChiSquareTest(int size, int df, float *v){
    ChiSquareDistribution X2(size,df);
    
    X2.setValues(v);    
    X2.setDistribution(size);
    float d = X2.getDistribution();
    X2.setCumulativeDistributionFunction(0, d, df);
    X2.print();
}
