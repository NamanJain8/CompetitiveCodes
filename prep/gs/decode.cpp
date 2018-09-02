#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;	cin>>t;
	while(t--){
		int l;	cin>>l;
		int arr[l];
		string s;	cin>>s;
		for(int i=0;i<l;i++)	arr[i] = s[i]-'0';
		int dp[l];
		dp[0]=1;
		dp[1]=1;
		if((arr[0]*10+arr[1])<=26 and arr[1]!=0)	dp[1]++;
		for(int i=2;i<l;i++){
			if(arr[i]==0 and arr[i-1]==0){
				dp[l-1]=0; break;
			}
			if((arr[i-1]*10+arr[i])>26 and arr[i]==0){
				dp[l-1]=0; break;
			}	
			if(arr[i]==0){	
				dp[i] = dp[i-2];
				continue;
			}
			dp[i] = dp[i-1];
			if((arr[i-1]*10+arr[i])<=26 and arr[i-1]!=0)	dp[i]+=dp[i-2];
		}
		if(((arr[0]*10+arr[1])>26 and arr[1]==0) or arr[0]==0){
				dp[l-1]=0;
			}	
		cout<<dp[l-1]<<endl;
	}
	return 0;
}