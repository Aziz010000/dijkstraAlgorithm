#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#include"matrixLib.h"

#define p 0.4
#define MAX_VALUE 15
#define MAX_DISTANCE 99


int **createMat(int n){
	int **matA = malloc(sizeof(int*)*n); 
	if(matA == NULL){
		fprintf(stderr, "Error in malloc\n"); 
		exit(EXIT_FAILURE); 
	}	
	for(int i = 0; i<n; i++){
		matA[i] = malloc(sizeof(int)*n); 
		if(matA[i] == NULL){
			fprintf(stderr, "Error in malloc\n"); 
			exit(EXIT_FAILURE); 
		}
		for(int j= 0; j<n; j++){
			matA[i][j] = 0; 
		}
	}
	return matA; 
}

void populateMatAdj(int **matA, int n){
	srand(time(NULL));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<=i; j++){
			if( (double)rand()/RAND_MAX  > p){
				matA[i][j] = 1; 
				matA[j][i] = 1; 
			}
		}
	}
}

void visualizeMat(int **matA, int n){ 
	for(int i = 0; i<n; i++){
		printf("\n"); 
		for(int j = 0; j<n; j++){
			printf("%d ", matA[i][j]); 
		}
	}
	printf("\n\n"); 
}

int **matFile(char *name){
	int n;
	FILE *f = fopen(name, "r+"); 
	if(f == NULL){
		fprintf(stderr, "Error in opening file\n"); 
		exit(EXIT_FAILURE); 
	}
	fscanf(f,"%d\n",&n); 
	int **matA = createMat(n); 
	for(int i = 0; i<n; i++){
		for(int j =0; j<n; j++){
			fscanf(f, "%d", &matA[i][j]); 
		}
		fscanf(f, "\n"); 
	}
	return matA; 
}

int takeNum(char *name){
	int n;
	FILE *f = fopen(name, "r+"); 
	if(f == NULL){
		fprintf(stderr, "Error in opening file\n"); 
		exit(EXIT_FAILURE); 
	}
	fscanf(f, "%d", &n); 
	return n;

}

int **disMat(int **myAdj, int n){
	int l;
	int **myDis = createMat(n); 
	for(int i=0; i<n; i++){
		for(int j= 0; j<=i; j++){
			if(myAdj[i][j] == 1){
				l = (int)((double)rand()/RAND_MAX*MAX_VALUE); 
				myDis[i][j] = l;
				myDis[j][i] = l;
			}
		}	
	
	}
	return myDis; 
}





bool controlValues(int *visited, int n){
	for(int i=0; i<n; i++){
		if(visited[i] == 0) return false;
	}
	return true; 


}




void initMatAdj(int *ptn, int ***ptmyAdj, char *filename){
	*ptn = takeNum(filename); 
	*ptmyAdj = matFile(filename); 
}



