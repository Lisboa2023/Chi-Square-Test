#ifndef CHISQUAREDISTRIBUTION_H
#define CHISQUAREDISTRIBUTION_H

class ChiSquareDistribution{
    public:
        ChiSquareDistribution(const int, const int, const float);
        ~ChiSquareDistribution();
        
        //Funções SET
        void setNumberOfMeasurements(const int);
        void setDegreesOfFreedom(const int);
        void setConfidenceLevel(const float);
        void setValues(float *);
        void setDistribution(const float);
        void setProbabilityDensityFunction(const double);
        void setCumulativeDistributionFunction(const float, const float);
                
        //Funções GET
        float getDistribution() const;
        float getCumulativeDistributionFunction() const;
        
        //Funcoes auxiliares
        void CalculateValues(const float *, const float *, const double *);
        void CalculateDistribution();
        void ChiSquareTest(const float *, const float *, const double *);
        void printResult() const;

    private:
        int size;
        int degreesoffreedom;
        float confidenceLevel;
        float *value;
        float distribution;
        float PDF;
        float CDF;
};

#endif
