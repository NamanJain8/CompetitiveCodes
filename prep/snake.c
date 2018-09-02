#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

typedef struct queue{
	NODE* front;
	NODE* rear;
}QUEUE;

QUEUE* newq(){
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

QUEUE* insert(QUEUE* q, int k){

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = k;
	temp->next = NULL;
	if(q->front==NULL){
		q->rear = temp;
		q->front = temp;
	}
	else{
		q->rear->next = temp;
		q->rear = temp;
	}
	return q;
}

QUEUE* delete(QUEUE* q){
	if(q->front == NULL)	return q;
	if(q->front == q->rear) q->rear = NULL;
	NODE* temp = q->front;
	q->front = q->front->next;
	free(temp);
	return q;
}

void printq(QUEUE* q){
	NODE* curr = q->front;
	while(curr!=NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	int t;	scanf("%d",&t);
	while(t--){
		int n;	scanf("%d",&n);
		int arr[30][6]={0};
		int size[30]={0}; 
		for(int i=0;i<30;i++){
			for(int j=0;j<6 && i+j+1<30;j++){
				arr[i][j]=i+j+1;
				size[i]++;
			}
		};
		for(int i=0;i<n;i++){
			int a,b;	scanf("%d%d",&a,&b);
			a--;	b--;
			if(a<b)	for(int j=0;j<6;j++){
				if(a-j-1>=0)	arr[a-j-1][j] = b;
			}
			if(a>b)	for(int j=0;j<6;j++){
				if(a+j+1<30)	arr[a+j+1][j] = b;
			}
		}
		for(int i=0;i<30;i++){
			for(int j=0;j<6;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}

		// BFS
		int visited[30]={0};
		visited[0]=1;
		int d[30];
		int parent[30];
		parent[0]=-1;
		d[0]=0;
		QUEUE* q = newq();
		insert(q,0);
		while(!(q->front == q->rear && q->front==NULL)){
			int u = q->front->data;
			delete(q);
			for(int i=0;i<size[u];i++){
				int v=arr[u][i];
				if(visited[v]==0){
					insert(q,v);
					d[v]=d[u]+1;
					visited[v]=1;
					parent[v]=u;
				}
			}
		}
		printf("%d\n",d[29]);
		int c=29;
		while(parent[c]!=-1){
			printf("%d ",parent[c]);	c = parent[c];
		}
	}
	return 0;
}