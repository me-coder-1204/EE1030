#include<stdio.h>
#include<stdlib.h>
#include "./libs/matfun.h"
#include<math.h>
void line_gen(double **A, double **B, int len, int dim, char *file){
	FILE *dat;
	dat = fopen(file, "w");
	for(int i=0;i<=len;i++){
		double x1 = A[0][0]+(B[0][0]-A[0][0])*i/(double)len;
		double y1 = A[1][0]+(B[1][0]-A[1][0])*i/(double)len;
		fprintf(dat,"%lf %lf\n",x1,y1);
	}
}

int main(void){
	double **A = createMat(2,1);
	double **B = createMat(2,1);
	double **C = createMat(2,1);
	double **D = createMat(2,1);

	A[0][0] = 4; A[1][0] = 3;
	B[0][0] = 6; B[1][0] = 4;
	C[0][0] = 5; C[1][0] = -6;
	D[0][0] = -3; D[1][0] = 5;
	line_gen(A,B,10,2,"./x_AB.dat");
	line_gen(A,C,10,2,"./x_AC.dat");
	line_gen(A,D,10,2,"./x_AD.dat");
	line_gen(B,C,10,2,"./x_BC.dat");
	line_gen(B,D,10,2,"./x_BD.dat");
	line_gen(C,D,10,2,"./x_CD.dat");
}
