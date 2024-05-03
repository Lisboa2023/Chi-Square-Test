#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void calculateValues(double *[], int);

int main(){

    const int size = 5;
    double *cm[size];

    calculateValues(cm, size);

    return 0; 
}

void calculateValues(double *covarianceMatrix[], int size){
    for (int i = 0; i < size; i++)
        for(int j = 0; i < size; j++)
        {   
            if(i==j){
                covarianceMatrix[i] = 1.0;
            }
            else{
                covarianceMatrix[i] = 0;
            }
        }

    for (int i = 0; i < size; i++){
        for(int j = 0; i < size; j++)
        {   
            cout << setw(13) << *(*(covarianceMatrix+i)+j); 
        }

        cout << endl;
    }  

    cout << endl << endl;  
}