#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	while(t--){
		int n,s;	cin>>n>>s;
		int arr[n];
		for(int i=0;i<n;i++)	cin>>arr[i];
		sort(arr,arr+n);
		int start=0,end=n-1;
		bool ans=false;
		while(start<end){
			int sum = arr[start]+arr[end];
			if(sum==s){
				ans=true;
				break;
			}
			else if(sum>s)	end--;
			else if(sum<s)	start++;
		}
		ans==true?cout<<"Yes":cout<<"No";
		cout<<endl;
	}
}
