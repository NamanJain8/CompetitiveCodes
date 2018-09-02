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
#define mod 1000000007

int main()
{
	int t;	cin>>t;
	ll fib[100005];
	fib[0]=1;	fib[1]=1;	fib[2]=2;
	frr(i,3,100005)	fib[i]=(fib[i-1]+fib[i-2])%mod;

	while(t--)
	{
		ll m,n;	cin>>m>>n;
		ll a[m],b[m];
		ll sa=0,sb=0;
		fr(i,m)	cin>>a[i];
		fr(i,m)	cin>>b[i];
		fr(i,m) sa=(sa+a[i])%mod;
		fr(i,m) sb=(sb+b[i])%mod;

		ll ans;
		if(n>=3)
			ans=(m*((fib[n-3]*sa)%mod + (fib[n-2]*sb)%mod)%mod)%mod;
		if(n==1)	ans=(m*sa)%mod;
		if(n==2)	ans=(m*sb)%mod;
		cout<<ans<<endl;
	}
}