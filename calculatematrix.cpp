#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void manipulateMatrix(double **, int);

int main(){

    const int size = 5;

    double **cmPtr = new double *[size];
    for (int i = 0; i < size; ++i) {
        cmPtr[i] = new double[size];
    }

    manipulateMatrix(cmPtr, size);

    for (int i = 0; i < size; ++i) {
        delete [] cmPtr[i];
    }

    delete [] cmPtr;

    return 0; 
}

void manipulateMatrix(double **cmPtr, int size){
        for (int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {   
            if(i==j){
                cmPtr[i][j] = 1.0;
            }
            else{
                cmPtr[i][j] = 0;
            }
    }

    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
        {   
            cout << setw(13) << cmPtr[i][j]; 
        }

        cout << endl;
    }  

    cout << endl << endl;
}
