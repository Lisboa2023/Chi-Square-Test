#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

class ProbabilityDistribution{
    public:
        ProbabilityDistribution(int, int );
        ~ProbabilityDistribution();
        
        //Funções SET
        void setNumberOfMeasurements(int);
        void setDegreesOfFreedom(int);
        void setValues(float *, float *, double *);
        virtual void setDistribution();
        virtual void setProbabilityDensityFunction(double);
        virtual void setCumulativeDistributionFunction(float, float);
        
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
