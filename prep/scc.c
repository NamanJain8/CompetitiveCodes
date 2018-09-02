#include <stdio.h>

// typedef struct node{
// 	int data;
// 	node* next;
// }N;

// typedef struct stack{
// 	node* top;
// 	int size;
// }S;

// S* createS(){
// 	S* s = (S*)malloc(sizeof(S));
// 	s->top=NULL;
// 	s->size=0;
// 	return s;
// }

// bool isEmpty(S* s){
// 	return s->size==0;
// }

// S* push(S* s, int ele){
// 	N* tmp=(N*)malloc(sizeof(N));
// 	tmp->data = ele;
// 	s->size++;
// 	if(isEmpty(s)){
// 		s->next = NULL;
// 		s->top = tmp;
// 	}
// 	else{
// 		tmp->next = s->top;
// 		s->top = tmp;
// 	}
// 	return s;
// }

// S* pop(S* s){
// 	if(isEmpty(s))
// 		return s;
// 	s->size--;
// 	N* tmp = s->top;
// 	s->top = s->top->next;
// 	free(tmp);
// 	return s;
// }

void dfs(int adj[][100],int size[],int visited[],int ft[],int src, int *time){
	visited[src]=1;
	for(int i=0;i<size[src];i++){
		int v = adj[src][i];
		if(visited[v])	continue;
		dfs(adj,size,visited,ft,v,time);
		(*time)++;
	}
	ft[src] = *time;
}

int main(){
	int t;	scanf("%d",&t);
	while(t--){
		int n,m;	scanf("%d%d",&n,&m);
		int adj[n][100];
		int size[n];
		for(int i=0;i<n;i++)	size[i]=0;
		for(int i=0;i<m;i++){
			int u,v;	scanf("%d%d",&u,&v);
			u--;v--;
			adj[u][size[u]]=v;
			size[u]++;
		}
		// S* s = createS();
		int visited[n];
		for(int i=0;i<n;i++)	visited[i]=0;
		int ft[n];
		int time = 0;
		for(int i=0;i<n;i++){
			if(visited[i])	continue;
			dfs(adj,size,visited,ft,i,&time);
		}
		// for(int i=0;i<n;i++)
		// 	printf("%d ",ft[i]);
		// printf("\n");
		
	}

}