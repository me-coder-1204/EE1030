#include <stdio.h>
#include <string.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <complex.h>
#include <stdlib.h>
#include "matcals.h"
#include "QR.h"

int main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    srand(1);
    int m = 3;
    double complex** A = createMat(m, m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            A[i][j] = (double complex) ((rand()/(double)RAND_MAX)-0.5);
        }
    }
    double complex*** Hq = malloc(2 * sizeof(double complex**));
    // hessenberg(A, m,Hq);

    Hq[0] = createMat(m , m); Hq[1] = createMat(m , m);
    // printMat(A, m, m);
    hessenberg(A, m, Hq);
    // printMat(Hq[0], m ,m);
    // A[0][0] = 2+0*I;   A[0][1] = 3+0*I;   A[0][2] = 5+0*I;   A[0][3] = 7+0*I;   A[0][4] = 11+0*I;  A[0][5] = 13+0*I;
    // A[1][0] = 17+0*I;  A[1][1] = 19+0*I;  A[1][2] = 23+0*I;  A[1][3] = 29+0*I;  A[1][4] = 31+0*I;  A[1][5] = 37+0*I;
    // A[2][0] = 41+0*I;  A[2][1] = 43+0*I;  A[2][2] = 47+0*I;  A[2][3] = 53+0*I;  A[2][4] = 59+0*I;  A[2][5] = 61+0*I;
    // A[3][0] = 67+0*I;  A[3][1] = 71+0*I;  A[3][2] = 73+0*I;  A[3][3] = 79+0*I;  A[3][4] = 83+0*I;  A[3][5] = 89+0*I;
    // A[4][0] = 97+0*I;  A[4][1] = 101+0*I; A[4][2] = 103+0*I; A[4][3] = 107+0*I; A[4][4] = 109+0*I; A[4][5] = 113+0*I;
    // A[5][0] = 127+0*I; A[5][1] = 131+0*I; A[5][2] = 137+0*I; A[5][3] = 139+0*I; A[5][4] = 149+0*I; A[5][5] = 151+0*I;
    double complex* eig;

    double complex** Ak = QReig(Hq[0], m);
    printMat(Ak, m,m);printf("\n");
    eig = eigs(Ak, m);
    for(int i=0;i<m;i++) printf("%lf + i%lf\n",creal(eig[i]),cimag(eig[i]));

    end = clock();
    printf("%lf\n", (double) (end-start)/CLOCKS_PER_SEC);
    free(A);
    freeMat(Ak,m);
    free(eig);
    return 0;
}