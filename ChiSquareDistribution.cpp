#include<iostream>
#include<cmath>
#include"ChiSquareDistribution.h"

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

void ChiSquareDistribution::setValues(float *ptr){
    value = ptr;
}

void ChiSquareDistribution::setDistribution(float DISTRIBUTION){
    distribution = DISTRIBUTION;
}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada
void ChiSquareDistribution::setProbabilityDensityFunction(const double t){                   
   
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

float ChiSquareDistribution::getDistribution() const{
    return distribution;
}

float ChiSquareDistribution::getCumulativeDistributionFunction() const{
    return CDF;
}

void ChiSquareDistribution::CalculateValues(const float *measurement,const float *estimatedMeasurement,const double *covarianceMatrix){
    for (int i = 0; i < size; i++)
    {
        value[i] = (measurement[i] - estimatedMeasurement[i])/sqrt(covarianceMatrix[i*size + i]);
    }
}

void ChiSquareDistribution::CalculateDistribution(){          
    for(int i = 0; i < size; i++){
        distribution += pow(value[i], 2);
    }
}

void ChiSquareDistribution::printResult() const{
    std::cout << "xt = " << distribution << std::endl
              << "P = " << CDF << std::endl;

    std::cout << std::endl
              << "Nivel de confianca: " << confidenceLevel << std::endl;

    if(CDF > confidenceLevel){
        std::cout << std::endl 
                  << "Erro Detectado" << std::endl;
    }
    else{
        std::cout << std::endl 
                  << "Nao ha erro no conjunto de medicoes" << std::endl << std::endl;
    }   
}

void ChiSquareDistribution::ChiSquareTest(const float *measurement, const float* estimatedMeasurement, const double *covarianceMatrix){
    
    CalculateValues(measurement, estimatedMeasurement, covarianceMatrix);    
    CalculateDistribution();
    setCumulativeDistributionFunction(0, distribution);
    printResult();

}



