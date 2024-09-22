#include<stdlib.h>
#include<stdio.h>

#include "minHeapv2.h"
#include "matrixLib.h"

#define p 0.4
#define MAX_VALUE 15
#define MAX_DISTANCE 99


int *valuesCr(int n){
	int *values = malloc(sizeof(int)*n); 
	if(values == NULL){
		fprintf(stderr, "Error in malloc\n"); 
		exit(EXIT_FAILURE); 
	}
	for(int i = 0; i<n; i++) values[i] = MAX_DISTANCE; 
	return values; 
}

int *visitedCr(int n){
	int *visited = malloc(sizeof(int)*n); 
	if(visited == NULL){
		fprintf(stderr, "Error in malloc\n"); 
		exit(EXIT_FAILURE); 
	}
	for(int i = 0; i<n; i++) visited[i] = 0; 
	return visited; 
}

void shortPath(int *values, int n ){
	for(int i = 0; i<n; i++) printf("The path cost to reach the node %d is %d\n", i, values[i]); 

}


void dAlg(int **aM, int **dM, int *values, int *visited, int n, int s){
	int l; 
	Node *mynode; 
	if(controlValues(visited,n)) return; 
	MinHeap *myHeap = createHeap(); 
	enqueque(myHeap, values[s],s); 	
	values[s] = 0; 
	while(1){ 
	if(controlValues(visited, n)) break; 
	Node *mynode = dequeque(myHeap);
	int v; 
	l = mynode->number;  
	for(int j = 0; j<n; j++){
			if(aM[l][j] == 1 && l!=j){
				if(visited[j] != 1){
					enqueque(myHeap, dM[l][j]+values[l], j); 
					if(values[j] > dM[l][j]+values[l]){
						values[j] = dM[l][j]+values[l]; 
					}
					if(values[j] == 99){
						values[j] = dM[l][j]; 
					
					}
				}

			}
	} 
	visited[l] = 1; 
	}

}


int main(int arcv, char *argv[]){
	
	int n; 
	int **myAdj; 
	initMatAdj(&n, &myAdj, "matrix.txt"); 
	int **myDis = disMat(myAdj,n); 
	int *values = valuesCr(n); 
	int *visited = visitedCr(n); 
	int s = 0; 
	
	printf("Adj matrix\n"); 
	visualizeMat(myAdj, n); 
	printf("Dis matrix\n"); 
	visualizeMat(myDis, n); 
	dAlg(myAdj, myDis, values, visited, n, s); 
	
	shortPath(values, n); 
	
	return 0; 
}
