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

#define n 3

int maxStarting(int arr[n][n], int dp[n][n], int i, int j){
	if(i<0 || i>=n || j<0 || j>=n)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i-1>=0 and arr[i-1][j]==arr[i][j]+1)
		return 1+maxStarting(arr,dp,i-1,j);

	else if(i+1<n and arr[i+1][j]==arr[i][j]+1)
		return 1+maxStarting(arr,dp,i+1,j);

	else if(j-1>=0 and arr[i][j-1]==arr[i][j]+1)
		return 1+maxStarting(arr,dp,i,j-1);

	else if(j+1<n and arr[i][j+1]==arr[i][j]+1)
		return 1+maxStarting(arr,dp,i,j+1);
	else
		return dp[i][j]=1;
}

int main(){
	int t;	cin>>t;
	while(t--){
		// cin>>n;
		int arr[n][n];
		fr(i,n)	fr(j,n)	cin>>arr[i][j];

		int dp[n][n];
		memset(dp,-1,sizeof(dp));
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++){
				if(dp[i][j]==-1)
					dp[i][j]=maxStarting(arr,dp,i,j);
				if(dp[i][j]>ans)
					ans=dp[i][j];
			}
		}
		cout<<ans<<endl;
	}
}