#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,root,var;
		cin>>n;
		root=floor(sqrt(n));
		var=n-root*root;
		if(var==0)
		{
			for(int i=0;i<root;i++)
				cout<<"X";
			for(int i=0;i<root;i++)
				cout<<"D";
			cout<<endl;
		}
		else if(root*(root+1)>n)
		{
			int i;
			for(i=0;i<var;i++)
				cout<<"X";
			if(var!=0)
				cout<<"D";
			while(i<root){
				cout<<"X";	i++;
			}
			for(int i=0;i<root;i++)
				cout<<"D";
			cout<<endl;
		}
		else
		{
			int i;
			var=n-root*(root+1);
			for(i=0;i<var;i++)
				cout<<"X";
			if(var!=0)
				cout<<"D";
			while(i<root+1){
				cout<<"X";	i++;
			}
			for(int i=0;i<root;i++)
				cout<<"D";
			cout<<endl;
		}
	}
	return 0;
}