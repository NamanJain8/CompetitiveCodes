#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;

typedef struct queue{
	Node* front;
	Node* rear;
}Queue;

Queue* createQ(){
	Queue* q= (Queue*)malloc(sizeof(Queue));	
	q->front = NULL;
	q->rear  = NULL; 
	return q;
}

Node* newN(){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;	
	return temp;
}

int isempty(Queue* q){
	if(q->front == q->rear && q->front==NULL)
		return 1;
	return 0;
}

Queue* enque(Queue* q,int k){
	Node* tmp = newN();
	tmp->data = k;
	if(q->front == NULL){
		q->front = tmp;
		q->rear = tmp;
		return q;	
	}
	q->rear->next = tmp;
	q->rear = tmp;
	return q;
}

Queue* dequeue(Queue* q){
	if(isempty(q)){
		printf("Empty\n");
		return q;
	}
	else{
		Node* temp = q->front;
		free(temp);
		if(q->rear == q->front){
			q->rear = NULL;
		}
		q->front = q->front->next;
		return q;
	}
}

void printQ(Queue* q){
	Node* ptr = q->front;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	Queue *q = createQ();
	while(n--){
		int a;
		scanf("%d",&a);
		if(a==1){
			int ele;
			scanf("%d",&ele);
			q = enque(q,ele);
			printQ(q);
		}
		if(a==2){
			q = dequeue(q);
			printQ(q);
		}
	}
	return 0;
}