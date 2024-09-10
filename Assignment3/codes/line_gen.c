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
		printMat(Matscale(A,2,1,i/10.0),2,1);
		fprintf(file,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",Matadd(A,Matscale(Matsub(B,A,2,1),2,1,i/10.0),2,1)[0][0],Matadd(A,Matscale(Matsub(B,A,2,1),2,1,i/10.0),2,1)[1][0],Matadd(A,Matscale(Matsub(C,A,2,1),2,1,i/10.0),2,1)[0][0],Matadd(A,Matscale(Matsub(C,A,2,1),2,1,i/10.0),2,1)[1][0],Matadd(A,Matscale(Matsub(D,A,2,1),2,1,i/10.0),2,1)[0][0],Matadd(A,Matscale(Matsub(D,A,2,1),2,1,i/10.0),2,1)[1][0],Matadd(B,Matscale(Matsub(C,B,2,1),2,1,i/10.0),2,1)[0][0],Matadd(B,Matscale(Matsub(C,B,2,1),2,1,i/10.0),2,1)[1][0],Matadd(B,Matscale(Matsub(D,B,2,1),2,1,i/10.0),2,1)[0][0],Matadd(B,Matscale(Matsub(D,B,2,1),2,1,i/10.0),2,1)[1][0],Matadd(C,Matscale(Matsub(D,C,2,1),2,1,i/10.0),2,1)[0][0],Matadd(C,Matscale(Matsub(D,C,2,1),2,1,i/10.0),2,1)[1][0]);
	}
	
	free(A);
	free(B);
	free(C);
	free(D);
	free(file);
}
