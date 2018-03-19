#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;	cin>>t;
	while(t--){
		int arr[26]={0};
		string str;
		vector<int> v[26];
		cin>>str;
		int len=str.length();
		int even=0,odd=0;
		int oddidx=-1;

		for(int i=0;i<len;i++){
			arr[str[i]-'a']+=1;
			v[str[i]-'a'].push_back(i);
		}

		for(int i=0;i<26;i++){
			if(arr[i]%2==0)	even++;
			else {	odd++; oddidx=i;	}
		}

		char newstr[len];
		int s=0,e=len-1;
		for(int i=0;i<26;i++)
		{
			if(i==oddidx)
				continue;
			for(int j=0;j<v[i].size()/2;j++)
				{	newstr[s]=97+i;	newstr[e]=97+i;	s++;	e--;}
		}
		for(int i=s;i<=e;i++)
			newstr[i]=97+oddidx;

		if(odd>1) {cout<<"-1"<<endl;	continue;	}
		int arr2[len];
		for(int i=0;i<len;i++)
		{
			arr2[i]=v[newstr[i]-'a'][v[newstr[i]-'a'].size()-1]+1;
			v[newstr[i]-'a'].pop_back();
		}
		for(int i=0;i<len;i++)
			cout<<arr2[i]<<" ";
		cout<<endl;

	for(int i=0;i<26;i++)
		v[i].clear();
	}
	return 0;
}