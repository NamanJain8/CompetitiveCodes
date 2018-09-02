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

int unbnd_ks(int val[],int wt[],int N,int W){
	int K[W+1][N+1];
	int x,y;
	for(int w=0;w<=W;w++){
		for(int n=0;n<=N;n++){
			x = (w>=0 and n>1) ? K[w][n-1]:0;
			y = (w>=wt[n-1] and n>0) ? K[w-wt[n-1]][n]+val[n-1]:0;

			K[w][n]=max(x,y);
		}
	}
	// fr(i,W+1){
	// 	fr(j,N+1)
	// 		cout<<K[i][j]<<" ";
	// 	cout<<endl;
	// }
	return K[W][N];
}

int main(){
	int t;	cin>>t;
	while(t--){
		int n,w;	cin>>n>>w;
		int val[n],wt[n];
		fr(i,n)	cin>>val[i];
		fr(i,n)	cin>>wt[i];

		cout<<unbnd_ks(val,wt,n,w)<<endl;	
	}
}
