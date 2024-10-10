#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "libs/matfun.h"
#include "libs/geofun.h"
#include <math.h>
void point_gen(FILE *fptr, double **A, double **B, int num_points) {
    for (int i = 0; i <= num_points; i++) {
		double temp = (double)i/(double)num_points;
		double temp1 = 1-temp;
        double **output = Matadd(Matscale(A,2,1,temp1),Matscale(B,2,1,temp),2,1);
		//printf("%lf,%lf\n",output[0][0],output[1][0]);
		fprintf(fptr, "%lf,%lf\n", output[0][0], output[1][0]);
        freeMat(output,2);
	}}

void circ_gen(FILE *fptr, double **A, int num_points, double radius){
	for(int i=0;i<=num_points;i++){
		double theta = 2 * M_PI * (double)i / (double)num_points;
		//double theta=(double)i/(double)(2*M_PI*num_points);
		double **output=createMat(2,1);
		output[0][0]=A[0][0]+(radius*cos(theta));
		output[1][0]=A[1][0]+(radius*sin(theta));
		fprintf(fptr,"%lf,%lf\n",output[0][0],output[1][0]);
		freeMat(output,2);
	}
}
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
void xparabola_gen(FILE *fptr, double a, double num_points, double **vertex){
	for(int i=num_points;i>=0;i--){
		double t = 3*i/num_points;
		double **output=createMat(2,1);
		output[0][0]=vertex[0][0]+a*t*t;
		output[1][0]=vertex[1][0]+2*a*t;
		fprintf(fptr,"%lf,%lf\n",output[0][0],output[1][0]);
		freeMat(output,2);
	}
	for(int i=0;i<=num_points;i++){
		double t = -3*i/num_points;
		double **output=createMat(2,1);
		output[0][0]=a*t*t;
		output[1][0]=2*a*t;
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
    vertex[1][0] = y1;
	a1[0][0]=2*sqrt(2);a1[1][0]=2;
	a2[0][0]=4;a2[1][0]=4;
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
	//fprintf(fptr,"%lf,%lf\n",A[0][0],A[1][0]);
	yparabola_gen(fptr, a, 1000,vertex);
	point_gen(fptr,a01,a1,11);
    point_gen(fptr,a02,a2,11);
	//xparabola_gen(fptr, a, 1000,vertex);
	//fprintf(fptr, "%lf,%lf\n", directionvector[0][0], directionvector[1][0]);
	//fprintf(fptr, "%lf,%lf\n", normalvector[0][0], normalvector[1][0]);
    fclose(fptr);
    return 0;
}
