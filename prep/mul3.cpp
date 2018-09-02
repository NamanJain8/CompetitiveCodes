#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	while(t--){
		string s;	cin>>s;
		int cnt[2]={0};
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='1' and i%2==1)
				cnt[1]++;
			if(s[i]=='1' and i%2==0)
				cnt[0]++;
		}
		int diff = abs(cnt[1]-cnt[0]);
		if(diff%3==0)	cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
}
