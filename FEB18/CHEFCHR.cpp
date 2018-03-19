#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count=0;
		for(int i=0;i<s.length();i++){			
			int arr[4]={0};
			for(int j=i;j<i+4;j++){
				if(s[j]=='c')	arr[0]++;
				else if(s[j]=='h')	arr[1]++;
				else if(s[j]=='e')	arr[2]++;
				else if(s[j]=='f')	arr[3]++;
			}
			if(arr[0]==1 && arr[1]==1 && arr[2]==1 && arr[3]==1)
				count++;
		}
		if(count>0)
			cout<<"lovely "<<count<<endl;
		else
			cout<<"normal"<<endl;
	}
}
