#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	cin.ignore();
	while(t--){	
		string str;
		getline(cin,str);
		string ans="";
		bool cnt[256]={0};
		ans+=str[0];
		cnt[int(str[0])]=1;
		for(int i=1;i<str.length();i++)
			if(str[i]!=str[i-1] and cnt[int(str[i])]==0){
				ans+=str[i];	cnt[int(str[i])]=1;
			}
		cout<<ans<<endl;
	}
}