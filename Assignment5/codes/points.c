#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libs/matfun.h"
#include "libs/geofun.h"


double conicForm(double** V, double **u, double f, double** x){
    return **Matadd(Matadd(Matmul(Matmul(transposeMat(x,2,1),V,1,2,2),x,1,2,1),Matscale(Matmul(transposeMat(u,2,1),x,1,2,1),1,1,2),1,1),Matscale(Mateye(1),1,1,f),1,1);
}

double* kapG(double** V, double** u, double f, double** h, double** m){
    double a = (**(Matscale(Matmul(transposeMat(m,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1),1,1,-1))+sqrt(**Matadd(Matmul(transposeMat(m,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1),Matscale(Matmul(Matmul(transposeMat(m, 2, 1),V,1,2,2),m,1,2,1),1,1,-conicForm(V, u, f, h)),1,1)))/ **(Matmul(Matmul(transposeMat(m, 2, 1),V,1,2,2),m,1,2,1));
    double b = (**(Matscale(Matmul(transposeMat(m,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1),1,1,-1))-sqrt(**Matadd(Matmul(transposeMat(m,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1),Matscale(Matmul(Matmul(transposeMat(m, 2, 1),V,1,2,2),m,1,2,1),1,1,-conicForm(V, u, f, h)),1,1)))/ **(Matmul(Matmul(transposeMat(m, 2, 1),V,1,2,2),m,1,2,1));
    double* x; x = malloc(2*sizeof(double));
    x[0] = a;
    x[1] = b;
    return x;
}

double*** inter(double** m, double** h, double* kap){
    double** x1 = Matsub(h,Matscale(m,2,1,kap[0]),2,1);
    double** x2 = Matsub(h,Matscale(m,2,1,kap[1]),2,1);

    double*** x;x =  malloc(2*sizeof(*x));
    x[0] = x1;
    x[1] = x2;
    return x;
}

void point_gen(FILE *fptr, double **A, double **B, int num_points) {
    for (int i = 0; i <= num_points; i++) {
		double temp = (double)i/(double)num_points;
		double temp1 = 1-temp;
        double **output = Matadd(Matscale(A,2,1,temp1),Matscale(B,2,1,temp),2,1);
		//printf("%lf,%lf\n",output[0][0],output[1][0]);
		fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        freeMat(output,2);
	}}


void yparabola_gen(FILE *fptr, double a, double num_points, double **vertex){
	for(int i=num_points;i>=0;i--){
		double t = 3*i/num_points;
		double **output=createMat(2,1);
		output[1][0]=vertex[0][0]+a*t*t;
		output[0][0]=vertex[1][0]+2*a*t;
		fprintf(fptr,"%lf,%lf\n",output[0][0],output[1][0]);
		freeMat(output,2);
	}
	for(int i=0;i<=num_points;i++){
		double t = -3*i/num_points;
		double **output=createMat(2,1);
		output[1][0]=a*t*t;
		output[0][0]=2*a*t;
		fprintf(fptr,"%lf,%lf\n",output[0][0],output[1][0]);
		freeMat(output,2);
	}

}

int main() {
    double x1, y1,x2,y2;
//    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    x1 = 0; y1 = 0; x2=8;y2=15;
    int m = 2, n = 1;
    double **vertex = createMat(m, n);
	double **a1= createMat(m,n);
	double **a2=createMat(m,n);
    double **a01 = createMat(m,n);
    double **a02 = createMat(m,n);
	vertex[0][0] = x1;
    double** V;
    V[0][0] = 1; V[0][1] = 0;
    V[1][0] = 0; V[1][1] = 0;
    double** u;
    u[0][0] = 0;
    u[1][0] = 2;
    double f = 0;
    double** h1 = createMat(2,1); double** h2 = createMat(2,1);
    h1[0][0] = 0; h1[1][0] = 2;
    h2[0][0] = 0; h2[1][0] = 4;
    double** m1 = createMat(2,1); 
    m1[0][0] = 1; m1[1][0] = 0;
    double *kap1; double* kap2;
    kap1 = kapG(V, u, f, h1, m1);
    kap2 = kapG(V, u, f, h2, m1);
    double*** in1 = inter(m1, h1, kap1);
    double*** in2 = inter(m1, h2, kap2);

    for(int i=0;i<2;i++){
        if(**in1[i]>0) a1 = in1[i];
        if(**in2[i]>0) a2 = in2[i];
    }
    vertex[1][0] = y1;
	// a1[0][0]=2*sqrt(2);a1[1][0]=2;
	// a2[0][0]=4;a2[1][0]=4;
    a01[0][0] = 0; a01[1][0] = 2;
    a02[0][0] = 0; a02[1][0] = 4;

	double radius = 4;
	FILE *fptr;
    fptr = fopen("line_points.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
	double a = 1;
	yparabola_gen(fptr, a, 1000,vertex);
	point_gen(fptr,a01,a1,11);
    point_gen(fptr,a02,a2,11);
    fclose(fptr);
    return 0;
}
