#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

class ProbabilityDistribution{
    public:
        ProbabilityDistribution(int);
        ~ProbabilityDistribution();

        //Funções SET
        void setValues(float *);
        virtual void setDistribution(int)=0;
        virtual void setProbabilityDensityFunction(double)=0;
        virtual void setCumulativeDistributionFunction(float, float, int);
        
        //Funções GET
        float getDistribution() const;
        float getCumulativeDistributionFunction() const;

        virtual void print() const;
    protected:
        float *value;
        float distribution;
        float PDF;
        float CDF;
};

#endif
