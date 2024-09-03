#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include<stdlib.h>
#include<math.h>
#include "libs/matfun.h"

int main() {
FILE *dat;
FILE *out;
dat = fopen("./points.dat","r");
int nVec; fscanf(dat,"%d",&nVec);
int m, n; fscanf(dat,"%d %d",&m,&n);
double ***vecArray;
vecArray = (double ***)malloc(nVec * sizeof(**vecArray));
for(int i=0;i<nVec;i++){
	vecArray[i]=createMat(m,n);
}
for(int i = 0; i<nVec; i++){
	vecArray[i] = createMat(m,n);
	for(int j=0;j<m;j++){
		for(int k=0;k<n;k++){
			fscanf(dat,"%lf",&vecArray[i][j][k]);
		}
	}
}

for(int i=1;i<nVec;i++){
	printMat(vecArray[i], m, n);
	for(int j=0;j<i;j++){
		printMat(Matsub(vecArray[i],vecArray[j],m,n),m,n);
	}
}
};
