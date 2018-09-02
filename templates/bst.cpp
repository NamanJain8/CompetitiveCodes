#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uint unsigned int
#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,a,b)   for(int i=a;i<b;i++)
#define rf(i,n)     for(int i=n-1;i>=0;i--)
#define init(mem,v) memset(mem,v,sizeof(mem))
#define vc(r) vector< r >
#define mk(a,b) make_pair(a,b)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(v,it) for(typeof((v).begin()) it = (v).begin(); it != (v).end() ; it++)
#define vpresent(v,x) ((v).find(x) != (v).end())
#define present(v,x) (find(all(v),x) != (v).end())
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
#define INF 2000000000

typedef struct node{
	int ele;
	node* left = NULL;
	node* right = NULL;
} NODE;

NODE* newNode(){
	return (NODE*)malloc(sizeof(node));
}

NODE* insert(NODE* root,int ele){
	if(root==NULL)
	{
		NODE* temp = newNode(); 
		temp->ele = ele;
		return temp;
	}
	if(ele < root->ele)
		root->left = insert(root->left,ele);
	else
		root->right = insert(root->right,ele);	
	return root;
}

void printTree(NODE* root){
	if(root==NULL)	return;
	printTree(root->left);
	cout<<root->ele<<" ";
	printTree(root->right);
}

int main(){
	int n;	cin>>n;
	int arr[n];
	fr(i,n)	cin>>arr[i];

	NODE* root = newNode();
	root->ele = arr[0];

	frr(i,1,n)
		root=insert(root,arr[i]);
	
	printTree(root);
	cout<<endl;
}