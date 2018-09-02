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

int main()
{
	int t;	cin>>t;
	while(t--){
		int n,q;	cin>>n>>q;
		ll arr[n+1],sorted[n+1];	arr[0]=0;	sorted[0]=0;
		map <ll,ll>	idx;
		map <ll,ll> sortidx;	
		frr(i,1,n+1)	{
			cin>>arr[i];	idx[arr[i]]=i;	sorted[i]=arr[i];
		}
		sort(sorted,sorted+n+1);
		frr(i,1,n+1){
			sortidx[sorted[i]]=i;
		}


		while(q--){
			ll x;	cin>>x;
			ll sidx=idx[x];
			ll big=0,small=0;
			ll high=n,low=1,mid=(high+low)/2;
			ll bigger=sortidx[x]-1,smaller=n-sortidx[x];
			while(mid!=sidx){
				if(mid<sidx){
					if(arr[mid]>x)
						big++;
					else
						bigger--;
					low=mid+1;
				}
				else if(mid>sidx){
					if(arr[mid]<x)
						small++;
					else
						smaller--;
					high=mid-1;
				}
				mid=(low+high)/2;
			}
			if(big>bigger or small>smaller)
				cout<<"-1"<<endl;
			else
				cout<<max(big,small)<<endl;
		}
	}
	return 0;
}