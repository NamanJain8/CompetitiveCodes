#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	while(t--){
		int n,m,x,k;
		cin>>n>>m>>x>>k;
		string str;		cin>>str;
		int e=0,o=0;
		for(int i=0;i<k;i++){
			if(str[i]=='E')	e++;
			else o++;
		}

		for(int i=1;i<=m;i++)
		{
			if(n<=0)
				break;
			if(i%2==0){
				(x>e)?n-=e:n-=x;
				(x>e)?e-=e:e-=x;
			}
			else{
				(x>o)?n-=o:n-=x;
				(x>o)?o-=o:o-=x;
			}
		}
		if(n<=0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}