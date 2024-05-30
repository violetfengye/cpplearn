#include<bits/stdc++.h>
using namespace std;
void gauss_l(double **A, double *b,int w){
    double **ZG = new double *[w];
    for(int i = 0; i < w;i++){
        ZG[i] = new double[w+1];
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            ZG[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < w; i++){
        ZG[i][w] = b[i];
    }
    for(int i = 0; i <w; i++){
        
    }
}
int main(void){
    const int w = 4;
    double **A = new double*[w];
    for(int i = 0; i < w; i++){
        A[i] = new double[w];
    }
    double *b = new double[w];
    double A[w][w] = {{1, 1, 0, 1}, {2, 1, -3, 1}, {4, -1, -2, 2}, {3, -1, -1, 2}};
    double b[w] = {2, 1, 0, -3};
    gauss_l(A, b, w);
    return 0;
}