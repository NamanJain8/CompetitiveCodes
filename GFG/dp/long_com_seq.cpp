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

int find(string s1,string s2,int l1,int l2){
	int dp[l1+1][l2+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = dp[l1][l2];
	return ans;
}

int main(){
	int t;	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.length();
		int l2=s2.length();
		cout<<find(s1,s2,l1,l2)<<endl;
	}
}