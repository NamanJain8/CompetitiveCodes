#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;  cin>>t;
	while(t--)
	{
	    string str; cin>>str;
	    int len=str.length();
	    int arr[len];
	    int ans=0;
	    for(int i=0;i<len;i++){
	    	switch(str[i]){
	    		case 'I': arr[i]=1; break;
	    		case 'V': arr[i]=5; break;
	    		case 'X': arr[i]=10; break;
	    		case 'L': arr[i]=50; break;
	    		case 'C': arr[i]=100; break;
	    		case 'D': arr[i]=500; break;
	    		case 'M': arr[i]=1000; break;
	    	}
	    }
	    ans=arr[0];
	    for(int i=1;i<len;i++)
	    {
	    	if(arr[i]>ans)
	    		ans=arr[i]-ans;

	    }
	    cout<<endl;
	}
	return 0;
}