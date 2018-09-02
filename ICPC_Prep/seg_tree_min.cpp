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

int build(int idx, int s, int e, int arr[], int seg[]){
	// if(idx >= 2*pow(2,ceil(log2(n))) - 1)	return 0;
	if(s==e){
		seg[idx] = arr[s];
		return seg[idx];
	}
	int mid = (s+e)/2;
	seg[idx] = min(build(2*idx+1,s,mid,arr,seg),build(2*idx+2,mid+1,e,arr,seg));
	return seg[idx]; 
}

void print(int seg[],int n){
	for(int i=0;i<2*n-1;i++){
		cout<<seg[i]<<" ";
	}
}

int query(int idx, int qs, int qe, int s, int e, int seg[]){
	if(qs<=s and qe>=e)
		return seg[idx];
	if(qs>e or qe<s)
		return INF;
	int mid = (s+e)/2;
	return min(query(2*idx+1,qs,qe,s,mid,seg),query(2*idx+2,qs,qe,mid+1,e,seg));
}

void update(int seg[], int idx, int s, int e, int up_idx){
	if(up_idx<s or up_idx>e)
		return;
	seg[idx] = min(arr[up_idx],seg[idx]);
	int mid=(s+e)/2;
	update(seg,2*idx+1,s,mid,up_idx);
	update(seg,2*idx+2,mid+1,e,up_idx);
	return;
}

int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int arr[n];
		fr(i,n)	cin>>arr[i];

		int size = 2*pow(2,ceil(log2(n))) - 1;
		int seg[size];
		build(0,0,n-1,arr,seg);

		print(seg,n);
		cout<<endl;
		cout<<query(0,3,6,0,n-1,seg)<<endl;
	}
}