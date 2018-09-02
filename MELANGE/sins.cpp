#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int gc=__gcd(x,y);
		cout<<2*gc<<endl;
	}
	return 0;
}