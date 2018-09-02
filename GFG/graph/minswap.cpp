
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You are required to complete this method */
int minSwaps(int A[], int N){
    int ans = 0;
    int srt[N];
   	set< pair <int,int> > myset;
   	int visited[N]={0};
    for(int i=0;i<N;i++)	myset.insert({A[i],i});

  	set< pair <int,int> > :: iterator it;
  	int count=0;
  	for(it=myset.begin();it!=myset.end();it++){
  		srt[count] = (*it).second;	count++;
  	}
  	for(int i=0;i<N;i++){
  		if(visited[i])
  			continue;
  		int curr = i;
  		int len = 0;
  		while(!visited[curr]){
  			visited[curr]=1;
  			len++;
  			curr = srt[curr];
  		}
  		ans+=(len-1);
  	}
  	return ans;
}
