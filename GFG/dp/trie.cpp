#include <bits/stdc++.h>
using namespace std;

typedef struct trie{
	string data = "";
	trie* child[26];
	bool valid = false;
} T;

T* insert(T* root, string s){
	if(s.length()==0)
		return NULL;
	int idx = int(s[0]-'a');
	// if(root->child[idx]==NULL)	root->child[idx] = new T;
	root->child[idx]->data = root->child[idx]->data + s[0];
	root->child = insert(root->child,s.substr(1,s.length()-1));
	return root;
}

int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		string str[n];
		for(int i=0;i<n;i++)	cin>>str[i];

		T* root = new T;

		for(int i=0;i<n;i++)	root=insert(root,str[i]);
	}
}