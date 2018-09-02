#include <stdio.h>

void merge(int arr[],int start, int end, int n){
	int mid =  (start+ end)/2;
	int i=start,j=mid+1,k=start;
	int newarr[n];
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
			newarr[k]=arr[i];	i++;	k++;
		}
		else{
			newarr[k]=arr[j];	j++;	k++;
		}
	}
	while(i<=mid){
		newarr[k] = arr[i];	i++;k++;
	}
	while(j<=end){
		newarr[k] = arr[j];	j++;k++;
	}
	for(int i=start;i<=end;i++){
		arr[i] = newarr[i];
	}
	return;
}

void mergeSort(int arr[],int start, int end, int n){
	if(start>=end)	return;
	int mid = (start+end)/2;
	mergeSort(arr,start,mid,n);
	mergeSort(arr,mid+1,end,n);
	merge(arr,start,end,n);
	return;
}

int main(){
	int n;	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)	scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1,n);
	for(int i=0;i<n;i++)	printf("%d ",arr[i]);
	printf("\n");
}