#include<iostream>
#include<cmath>
#include"ChiSquareDistribution.h"

using std::cout;
using std::endl;

ChiSquareDistribution::ChiSquareDistribution(const int SIZE, const int DF, const float CL){
    setNumberOfMeasurements(SIZE);
    setDegreesOfFreedom(DF);
    setConfidenceLevel(CL);
    value = new float [SIZE];
    distribution = PDF = CDF = 0;
}

ChiSquareDistribution::~ChiSquareDistribution(){
    delete [] value;
}

void ChiSquareDistribution::setNumberOfMeasurements(const int SIZE){
    size = SIZE;
}

void ChiSquareDistribution::setDegreesOfFreedom(const int DF){
    degreesoffreedom = DF;
}

void ChiSquareDistribution::setConfidenceLevel(const float CL){
    confidenceLevel = CL;
}

//Recebe valores para a Distribuição Qui-Quadrada
void ChiSquareDistribution::setValues(const float *measurement,const float *estimatedMeasurement,const double *covarianceMatrix){
    for (int i = 0; i < size; i++)
    {
        value[i] = (measurement[i] - estimatedMeasurement[i])/sqrt(covarianceMatrix[i*size + i]);
    }
}

void ChiSquareDistribution::setDistribution(){          
    for(int i = 0; i < size; i++){
        distribution += pow(value[i], 2);
    }
}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada
void ChiSquareDistribution::setProbabilityDensityFunction(const double t){                   
    //t, variável da função; v, graus de liberdade da função
    double a = pow(t,(degreesoffreedom-2)/2);
    double b = exp(-t/2);
    double c = pow(2,degreesoffreedom/2);
    double d = tgamma(degreesoffreedom/2);

    PDF = (a*b)/(c*d);
}

//Função Distribuição Acumulada da Distribuição Qui-Quadrada(integral da Função Densidade de Probabilidade)
void ChiSquareDistribution::setCumulativeDistributionFunction(const float a,const float b){   

    const int n = 1000;                                      
    float h = (b-a)/n;

    setProbabilityDensityFunction(a);          
    float somatoria = PDF;

    setProbabilityDensityFunction(b);
    somatoria += PDF;

    for(int i = 1; i < n; i++){
        setProbabilityDensityFunction(i*h);
        somatoria += 2 * PDF;
    }

    CDF = (h/2)*somatoria;
}

void ChiSquareDistribution::ChiSquareTest(const float *measurement, const float* estimatedMeasurement, const double *covarianceMatrix){
    
    setValues(measurement, estimatedMeasurement, covarianceMatrix);    
    setDistribution();
    float d = getDistribution();
    setCumulativeDistributionFunction(0, d);
    print();

    float test = getCumulativeDistributionFunction();

    cout << endl
         << "Nivel de confianca: " << confidenceLevel << endl;

    if(test > confidenceLevel){
        cout << endl 
             << "Erro Detectado" << endl;
    }
    else{
        cout << endl 
             << "Nao ha erro no conjunto de medicoes" << endl << endl;
    }
}

float ChiSquareDistribution::getDistribution() const{
    return distribution;
}

float ChiSquareDistribution::getCumulativeDistributionFunction() const{
    return CDF;
}

void ChiSquareDistribution::print() const{
    cout << "xt = " << distribution << endl
         << "P = " << CDF << endl;   
}

