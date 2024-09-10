#include<stdio.h>
#include<stdlib.h>
#include "./libs/matfun.h"
#include<math.h>

int main(void){
	double **A = createMat(2,1);
	double **B = createMat(2,1);
	double **C = createMat(2,1);
	double **D = createMat(2,1);

	A[0][0] = 4; A[1][0] = 3;
	B[0][0] = 6; B[1][0] = 4;
	C[0][0] = 5; C[1][0] = -6;
	D[0][0] = -3; D[1][0] = 5;

	FILE *file;
	int len = 10;
	file = fopen("./lines.dat","w");
	for(int i = 0;i<=10;i++){
		fprintf(file,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",A[0][0]+(B[0][0]-A[0][0])*i/(double)len,A[1][0]+(B[1][0]-A[1][0])*i/(double)len,A[0][0]+(C[0][0]-A[0][0])*i/(double)len,A[1][0]+(C[1][0]-A[1][0])*i/(double)len,A[0][0]+(D[0][0]-A[0][0])*i/(double)len,A[1][0]+(D[1][0]-A[1][0])*i/(double)len,B[0][0]+(C[0][0]-B[0][0])*i/(double)len,B[1][0]+(C[1][0]-B[1][0])*i/(double)len,B[0][0]+(D[0][0]-B[0][0])*i/(double)len,B[1][0]+(D[1][0]-B[1][0])*i/(double)len,C[0][0]+(D[0][0]-C[0][0])*i/(double)len,C[1][0]+(D[1][0]-C[1][0])*i/(double)len);
	}
}
