#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		string ans="";
		while(n>0){
			if(n%26==0)	{
				ans = "Z"+ans;	n--;
			}
			else
				ans = (char)(n%26 + 64) + ans;
			n/=26;
		}
		cout<<ans<<endl;
	}
	return 0;
}