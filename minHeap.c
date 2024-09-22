#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value; 
}Node;

typedef struct minHeap{
	int size; 
	Node **h;
}MinHeap;


void swap(Node **a, Node **b){
	Node *temp; 
	temp = *a; 
	*a = *b; 
	*b = temp;
}

Node *createNode(int value){
	Node *newNode; 
	newNode = malloc(sizeof(Node)); 
	if(newNode == NULL){
		fprintf(stderr, "Error in malloc occured\n"); 
		exit(EXIT_FAILURE); 
	}
	newNode->value = value;

	return newNode; 
}

void ordinateUp(MinHeap *myHeap, int i){
	if(i != 0 && myHeap->h[(i-1)/2]->value > myHeap->h[i]->value){
		swap(&myHeap->h[(i-1)/2], &myHeap->h[i]); 
		ordinateUp(myHeap, (i-1)/2);
	}


}


void enqueque(MinHeap * myHeap, int value){
	Node *newNode = createNode(value);
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
	if(l<myHeap->size && myHeap->h[index]->value > myHeap->h[l]->value){
		index = l; 
	}
	if(r<myHeap->size && myHeap->h[index]->value > myHeap->h[r]->value){
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
		free(myHeap->h[0]);
		myHeap->h[0] = myHeap->h[myHeap->size -1];
		myHeap->h = realloc(myHeap->h, sizeof(Node *) * (--myHeap->size));  
		if(myHeap == NULL){
			fprintf(stderr, "Error in reallocating memory\n"); 
			exit(EXIT_FAILURE);
		}
		ordinateDown(myHeap, 0);
	}
	return NULL;
		
}


void visualize(MinHeap *myHeap){
	printf("\n");
	for(int i= 0; i<myHeap->size; i++){
		printf("%d ", myHeap->h[i]->value);
	
	}
	printf("\n");


}



int main(int arcv, char *argv[]){
	MinHeap *myHeap; 
	myHeap->h = NULL; 
	myHeap->size = 0; 
	enqueque(myHeap, 15);
	enqueque(myHeap,2);
	enqueque(myHeap, 1); 
	enqueque(myHeap, 17); 
	enqueque(myHeap, 4); 
	enqueque(myHeap, 25); 
	enqueque(myHeap, 6);
	dequeque(myHeap);
	visualize(myHeap);
	










	return 0;
}
