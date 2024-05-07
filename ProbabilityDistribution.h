#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

class ProbabilityDistribution{
    public:
        ProbabilityDistribution(int, int );
        ~ProbabilityDistribution();
        
        //Funções SET
<<<<<<< HEAD
        void setValues(float *);
        virtual void setDistribution(int);
        virtual void setProbabilityDensityFunction(double,int);
        virtual void setCumulativeDistributionFunction(float, float, int);
=======
        void setNumberOfMeasurements(int);
        void setDegreesOfFreedom(int);
        void setValues(float *, float *, double *);
        virtual void setDistribution();
        virtual void setProbabilityDensityFunction(double);
        virtual void setCumulativeDistributionFunction(float, float);
>>>>>>> patch_1
        
        //Funções GET
        float getDistribution() const;
        float getCumulativeDistributionFunction() const;

        virtual void print() const;
    private:
<<<<<<< HEAD
=======
        int size;
        int df;
>>>>>>> patch_1
        float *value;
        float distribution;
        float PDF;
        float CDF;
};

#endif
