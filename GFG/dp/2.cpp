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

int lcs(string s1,string s2, int m,int n){
	int L[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 or j==0)
				L[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}
	return L[m][n];
}

int main()
{
	int t;	cin>>t;
	while(t--){
		int m,n;	cin>>m>>n;
		string s1,s2;	cin>>s1>>s2;
		cout<<lcs(s1,s2,m,n)<<endl;
	}
}