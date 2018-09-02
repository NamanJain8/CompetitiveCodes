#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int arr[n];
		map<int,int> m;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(m.find(arr[i])==m.end())
				m.insert({arr[i],1});
			else
			{
				int cnt=m[arr[i]];
				m.erase(arr[i]);
				m.insert({arr[i],cnt+1});
			}
		}
		int ans,flag=0;
		for(auto it = m.begin();it!=m.end();it++){
			// cout<<it->second<<" ";
			if(it->second>n/2.0)	{
				ans = it->first;	flag=1;
				break;
			}
		}
		if(flag)	cout<<ans;
		else cout<<"NO Majority Element";
		cout<<endl;
	}
}
