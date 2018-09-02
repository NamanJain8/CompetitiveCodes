#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;  cin>>t;
	while(t--)
	{
	    string str; cin>>str;
	    int len=str.length();
	    sort(str.begin(),str.end());
	    int arr[len];
	    for(int i=0;i<len;i++)
	    	arr[i]=i;
	    do{
	    	for(int i=0;i<len;i++)
	    		cout<<str[arr[i]];
	    	cout<<" ";
	    }while(next_permutation(arr,arr+len));
	    cout<<endl;
	}
	return 0;
}