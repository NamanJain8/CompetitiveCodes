#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		long long int n;	cin>>n;
		long long int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		long long int maxi=*max_element(arr,arr+n);
		long long int c,d,s;
		cin>>c>>d>>s;
		long long int ans=(c-1)*maxi;
		cout<<ans<<endl;
	}
}