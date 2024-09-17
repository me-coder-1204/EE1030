#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct {
	double p1;
	double p2;
} Result;

double *points(double x1, double y1, double y2, double d, Result* result){
	result -> p1 = (x1+sqrt(pow(d,2)-pow((y2-y1),2)));
	result -> p2 = (x1-sqrt(pow(d,2)-pow((y2-y1),2)));
	
}
