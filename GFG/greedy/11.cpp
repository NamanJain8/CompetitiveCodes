#include <bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
bool val_compare(val lhs, val rhs){
	if (rhs.second != lhs.second)
		return rhs.second > lhs.second;
	else
		return rhs.first > lhs.first;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
	sort(p,p+n,val_compare);
	int ans=0;
	int end=0;
	for(int i=0;i<n;i++){
		if(end<p[i].first){
			ans++;	end=p[i].second;
		}
	}
	return ans;
}