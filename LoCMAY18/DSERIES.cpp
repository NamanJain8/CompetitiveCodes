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
	int q;	cin>>q;
	while(q--){
		ull n,t;	cin>>n>>t;
		ull tfact=1,ft=1;

		for(ll i=n+1;i<=n+t+1;i++){
			ull a=i%(t+1);
			if(a==0){
				ft*=(i/(t+1));	ft%=mod;
			}
			else{
				ft*=i;	ft%=mod;
			}
		}

		for(ll i=1;i<=t;i++){
			tfact*=i;	tfact%=mod;
		}

		ft=(mod+ft-tfact)%mod;
		cout<<ft<<endl;
	}
	return 0;
}