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

int arr[100],seg[100];

int build(int idx, int s, int e){
	if(s == e){
		seg[idx] = arr[s];
		return seg[idx];
	}
	int mid = (e+s)/2;
	seg[idx] = build(2*idx+1, s, mid) + build(2*idx+2, mid+1, e);
	return seg[idx];
}

void update(int curr,int diff,int idx, int s, int e){
	if(idx > e || idx < s)
		return;
	if(s==e){
		seg[curr]+=diff;
		return;
	}
	seg[curr] += diff;
	int mid = (s+e)/2;
	update(2*curr+1,diff,idx, s, mid);
	update(2*curr+2,diff,idx, mid+1, e);
	return;
}

int query(int idx,int qs, int qe, int s, int e){
	if(qs<=s and qe>=e)
		return seg[idx];
	if(qs>e || qe<s)
		return 0;
	int mid = (s+e)/2;
	return query(2*idx+1,qs,qe,s,mid) + query(2*idx+2,qs,qe,mid+1,e);

}

void print(int n){
	for(int i=0;i<2*n-1;i++){
		cout<<seg[i]<<" ";
	}
}

int main(){
	int n;	cin>>n;	
	for(int i=0;i<n;i++)	cin>>arr[i];

	build(0,0,n-1);
	update(0,10-arr[2],2,0,n-1);
	arr[2] = 10;
	cout<<query(0,1,3,0,n-1)<<endl;
	print(n);
	cout<<endl;
}