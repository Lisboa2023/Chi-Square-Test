#include<iostream>
#include<cmath>
#include"ChiSquareTest.h"

ChiSquareDistribution::ChiSquareDistribution(const int SIZE, const int DF, const float CL){
    
    setNumberOfMeasurements(SIZE);
    setDegreesOfFreedom(DF);
    setConfidenceLevel(CL);
    chi_squared_variable = probability = 0;

}

ChiSquareDistribution::~ChiSquareDistribution(){}

//Funcoes SET=======================================================================================
void ChiSquareDistribution::setNumberOfMeasurements(const int SIZE){
    number_of_measurements = SIZE;
}

void ChiSquareDistribution::setDegreesOfFreedom(const int DF){
    degrees_of_freedom = DF;
}

void ChiSquareDistribution::setConfidenceLevel(const float CL){
    confidence_level = CL;
}

void ChiSquareDistribution::setChiSquaredVariable(float variable){
    chi_squared_variable = variable;
}
//==========================================================================================

//Funcoes GET================================================================================
int ChiSquareDistribution::getNumberOfMeasurements() const{
    return number_of_measurements;
}

int ChiSquareDistribution::getDegreesOfFreedom() const{
    return degrees_of_freedom;
}

float ChiSquareDistribution::getConfidenceLevel() const{
    return confidence_level;
}

float ChiSquareDistribution::getChiSquaredVariable() const{
    return chi_squared_variable;
}

float ChiSquareDistribution::getProbability() const{
    return probability;
}
//==================================================================================

void ChiSquareDistribution::CalculateChiSquaredVariable(const float *measurement,const float *estimatedMeasurement,const float *covarianceMatrix){
    
    float temp;
    
    for (int i = 0; i < number_of_measurements; i++)
    {
        temp = (measurement[i] - estimatedMeasurement[i])/sqrt(covarianceMatrix[i*number_of_measurements + i]);
        chi_squared_variable += pow(temp, 2);
    }

}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada===================================
float ChiSquareDistribution::ChiSquareProbabilityDensityFunction(const float t){                   
   
    double a = pow(t,(degrees_of_freedom-2)/2);
    double b = exp(-t/2);
    double c = pow(2,degrees_of_freedom/2);
    double d = tgamma(degrees_of_freedom/2);

    return (a*b)/(c*d);
}

//Função Distribuição Acumulada da Distribuição Qui-Quadrada(integral da Função Densidade de Probabilidade)
void ChiSquareDistribution::ChiSquareCumulativeDistributionFunction(const float a,const float b){   

    const int n = 1000;                                      
    float h = (b-a)/n;

    float result = ChiSquareProbabilityDensityFunction(a);          
    result += ChiSquareProbabilityDensityFunction(b);
    
    for(int i = 1; i < n; i++){
        result += 2 * ChiSquareProbabilityDensityFunction(i*h);
    }

    probability = (h/2)*result;
}

void ChiSquareDistribution::printResult() const{
    std::cout << std::endl
              << "Confidence Level: " << confidence_level << std::endl;
    
    std::cout << "xt = " << chi_squared_variable << std::endl
              << "P = " << probability << std::endl;

    if(probability > confidence_level){
        std::cout << std::endl 
                  << "Message: Error Detected" << std::endl;
                  
    }
    else{
        std::cout << std::endl 
                  << "Message: There is no error in the measurement set" << std::endl << std::endl;
    }   
}

void ChiSquareDistribution::ChiSquareTest(const float *measurement, const float* estimatedMeasurement, const float *covarianceMatrix){
    
    CalculateChiSquaredVariable(measurement, estimatedMeasurement, covarianceMatrix);    
    ChiSquareCumulativeDistributionFunction(0, chi_squared_variable);
    printResult();

}

void ChiSquareDistribution::ChiSquareTest(float variable){
    
    setChiSquaredVariable(variable);
    ChiSquareCumulativeDistributionFunction(0, chi_squared_variable);
    printResult();

}


