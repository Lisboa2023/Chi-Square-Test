#include<iostream>
#include<cmath>
#include"ProbabilityDistribution.h"

using std::cout;
using std::endl;

ProbabilityDistribution::ProbabilityDistribution(int size){
    value = new float [size];
    distribution = PDF = CDF = 0;
}

ProbabilityDistribution::~ProbabilityDistribution(){
    delete [] value;
}

//Recebe valores para a Distribuição Qui-Quadrada
void ProbabilityDistribution::setValues(float *ptr){
    value = ptr;          
}

void ProbabilityDistribution::setDistribution(int size){          
    for(int i = 0; i < size; i++){
        distribution += pow(*(value+i), 2);              
    }
}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada
void ProbabilityDistribution::setProbabilityDensityFunction(double t, int v){                   
    //t, variável da função; v, graus de liberdade da função
    double a = pow(t,(v-2)/2);
    double b = exp(-t/2);
    double c = pow(2,v/2);
    double d = tgamma(v/2);

    PDF = (a*b)/(c*d);
}


float ProbabilityDistribution::getDistribution() const{
    return distribution;
}

//Função Distribuição Acumulada da Distribuição Qui-Quadrada(integral da Função Densidade de Probabilidade)
void ProbabilityDistribution::setCumulativeDistributionFunction(float a, float b, int c){   

    const int n = 1000;                                      
    float h = distribution/n;

    setProbabilityDensityFunction(a,c);          
    float somatoria = PDF;

    setProbabilityDensityFunction(b,c);
    somatoria += PDF;

    for(int i = 1; i < n; i++){
        setProbabilityDensityFunction(i*h,c);
        somatoria += 2 * PDF;
    }

    CDF = (h/2)*somatoria;
}

float ProbabilityDistribution::getCumulativeDistributionFunction() const{
    return CDF;
}

void ProbabilityDistribution::print() const{
    cout << "xt = " << distribution << endl
         << "P = " << CDF << endl;   
}

