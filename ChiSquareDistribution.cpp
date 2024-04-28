#include <cmath>
#include "ChiSquareDistribution.h"

ChiSquareDistribution::ChiSquareDistribution(int size, int df):ProbabilityDistribution(size){
    setDegreeOfFreedom(df);
}

void ChiSquareDistribution::setDegreeOfFreedom(int df){
    DF = df;
}

//Calcula os valores Qui-Quadrados
void ChiSquareDistribution::setDistribution(int size){          
    for(int i = 0; i < size; i++){
        distribution += pow(*(value+i), 2);              
    }
}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada
void ChiSquareDistribution::setProbabilityDensityFunction(double t, int v){                   
    //t, variável da função; v, graus de liberdade da função
    double a = pow(t,(v-2)/2);
    double b = exp(-t/2);
    double c = pow(2,v/2);
    double d = tgamma(v/2);

    PDF = (a*b)/(c*d);
}


