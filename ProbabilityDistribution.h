#ifndef CHISQUAREDISTRIBUTION_H
#define CHISQUAREDISTRIBUTION_H

class ChiSquareDistribution{
    public:
        ChiSquareDistribution(const int, const int);
        ~ChiSquareDistribution();
        
        //Funções SET
        void setNumberOfMeasurements(const int);
        void setDegreesOfFreedom(const int);
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
        int df;
        float *value;
        float distribution;
        float PDF;
        float CDF;
};

#endif
