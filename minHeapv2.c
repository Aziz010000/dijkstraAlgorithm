#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#include "minHeapv2.h"

void swap(Node **a, Node **b){
	Node *temp; 
	temp = *a; 
	*a = *b; 
	*b = temp;
}


bool controlSwap(Node *nodeA, Node *nodeB){
	if(nodeA->value > nodeB->value) return true; 
	if(nodeA->value == nodeB->value && nodeA->number>nodeB->number) return true; 
	return false; 
}

void ordinateUp(MinHeap *myHeap, int i){
	if(i != 0 && controlSwap(myHeap->h[(i-1)/2], myHeap->h[i])){
		swap(&myHeap->h[(i-1)/2], &myHeap->h[i]); 
		ordinateUp(myHeap, (i-1)/2);
	}


}


void enqueque(MinHeap * myHeap, int value, int number){
	Node *newNode = createNode(value, number);
	myHeap->h = realloc(myHeap->h, sizeof(Node*)*(++myHeap->size)); 
	if(myHeap->h == NULL){
		fprintf(stderr, "Error in realloc\n"); 
		exit(EXIT_FAILURE);
	}
	myHeap->h[myHeap->size-1] = newNode; 
	ordinateUp(myHeap, myHeap->size-1);
}


void ordinateDown(MinHeap *myHeap, int i){
	int index = i; 
	int l = 2*i+1; 
	int r = 2*i+2;
	if(l<myHeap->size && controlSwap(myHeap->h[index], myHeap->h[l])){
		index = l; 
	}
	if(r<myHeap->size && controlSwap(myHeap->h[index], myHeap->h[r])){
		index = r; 
	}
	if(i != index){
		swap(&myHeap->h[index], &myHeap->h[i]);; 
		ordinateDown(myHeap, index); 
	}


}

Node *dequeque(MinHeap *myHeap){
	if(myHeap->size > 0){
		Node *temp = myHeap->h[0]; 
		myHeap->h[0] = myHeap->h[myHeap->size -1];
		myHeap->h = realloc(myHeap->h, sizeof(Node *) * (--myHeap->size));  
		if(myHeap == NULL){
			fprintf(stderr, "Error in reallocating memory\n"); 
			exit(EXIT_FAILURE);
		}
		ordinateDown(myHeap, 0);
		return temp;
	}
	return NULL;
		
}
Node *createNode(int value, int number){
	Node *newNode; 
	newNode = malloc(sizeof(Node)); 
	if(newNode == NULL){
		fprintf(stderr, "Error in malloc occured\n"); 
		exit(EXIT_FAILURE); 
	}
	newNode->value = value;
	newNode->number = number; 
	return newNode; 
}

MinHeap *createHeap(){
	MinHeap *myHeap = malloc(sizeof(MinHeap)); 
	if(myHeap == NULL){
		fprintf(stderr, "Error in malloc\n");
		exit(EXIT_FAILURE);
	}
	myHeap->h = NULL; 
	myHeap->size = 0; 

}


void visualize(MinHeap *myHeap){
	printf("\n");
	for(int i= 0; i<myHeap->size; i++){
		printf("%d %d\n", myHeap->h[i]->value, myHeap->h[i]->number);
	
	}
	printf("\n");


}


