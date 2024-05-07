#include<iostream>
#include<cmath>
#include"ProbabilityDistribution.h"

using std::cout;
using std::endl;

ProbabilityDistribution::ProbabilityDistribution(const int SIZE, const int DF){
    setNumberOfMeasurements(SIZE);
    setDegreesOfFreedom(DF);
    value = new float [SIZE];
    distribution = PDF = CDF = 0;
}

ProbabilityDistribution::~ProbabilityDistribution(){
    delete [] value;
}

void ProbabilityDistribution::setNumberOfMeasurements(const int SIZE){
    size = SIZE;
}

void ProbabilityDistribution::setDegreesOfFreedom(const int DF){
    df = DF;
}

//Recebe valores para a Distribuição Qui-Quadrada
void ProbabilityDistribution::setValues(const float *measurement,const float *mEstimated,const double *covarianceMatrix){
    for (int i = 0; i < size; i++)
    {
        value[i] = measurement[i] - mEstimated[i]/sqrt(covarianceMatrix[i*size + i]);
    }
}

void ProbabilityDistribution::setDistribution(){          
    for(int i = 0; i < size; i++){
        distribution += pow(value[i], 2);
    }
}

//Função Densidade de Probabilidade da Distribuição Qui-Quadrada
void ProbabilityDistribution::setProbabilityDensityFunction(const double t){                   
    //t, variável da função; v, graus de liberdade da função
    double a = pow(t,(df-2)/2);
    double b = exp(-t/2);
    double c = pow(2,df/2);
    double d = tgamma(df/2);

    PDF = (a*b)/(c*d);
}

//Função Distribuição Acumulada da Distribuição Qui-Quadrada(integral da Função Densidade de Probabilidade)
void ProbabilityDistribution::setCumulativeDistributionFunction(const float a,const float b){   

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

void ProbabilityDistribution::ChiSquareTest(const float *measurement, const float* mEstimated, const double *covarianceMatrix){
    
    setValues(measurement, mEstimated, covarianceMatrix);    
    setDistribution();
    float d = getDistribution();
    setCumulativeDistributionFunction(0, d);
    print();

    float test = getCumulativeDistributionFunction();
    const float confidenceLevel = 0.99;

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

float ProbabilityDistribution::getDistribution() const{
    return distribution;
}

float ProbabilityDistribution::getCumulativeDistributionFunction() const{
    return CDF;
}

void ProbabilityDistribution::print() const{
    cout << "xt = " << distribution << endl
         << "P = " << CDF << endl;   
}

