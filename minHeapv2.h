#include<stdbool.h>



typedef struct node{
	int number; 
	int value; 
}Node; 

typedef struct minHeap{
	int size ;
	Node **h; 
}MinHeap; 


void swap(Node **a, Node **b); 
bool swapControlUp(Node *nodeA, Node *nodeB); 
void ordinateUp(MinHeap *myHeap, int index); 
bool swapControlDown(Node *nodeA, Node *nodeB); 
void ordinateDown(MinHeap *myHeap, int index); 
void enqueque(MinHeap *myHeap, int value, int number); 
Node *dequeque(MinHeap *myHeap);
void visualize(MinHeap *myHeap); 
Node *createNode(int value, int number); 
MinHeap *createHeap(); 
