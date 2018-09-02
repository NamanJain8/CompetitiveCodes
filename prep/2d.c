#include <stdio.h>

void print(int arr[][1000],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

int main(){
	int n,m;	scanf("%d%d",&n,&m);
	int arr[n][1000];
	for(int i=0;i<n;i++)	for(int j=0;j<m;j++)	scanf("%d",&arr[i][j]);
	print(arr,n,m);
	return 1;
}