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
        void setValues(const float *, const float *, const double *);
        virtual void setDistribution();
        virtual void setProbabilityDensityFunction(const double);
        virtual void setCumulativeDistributionFunction(const float, const float);
        void ChiSquareTest(const float *, const float *, const double *);
        
        //Funções GET
        float getDistribution() const;
        float getCumulativeDistributionFunction() const;

        virtual void print() const;
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
