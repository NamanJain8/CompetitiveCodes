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

ll bsearch(ll arr[],ll h,int n, ll start,ll end)
{
	ll mid=(start+end)/2;
	ll req1=0,req2=0;
	fr(i,n)
		req1+=ceil((arr[i]*1.0)/mid);
	fr(i,n)
		req2+=ceil((arr[i]*1.0)/(mid+1));

	if(req1==h && req2==h)
		return bsearch(arr,h,n,start,mid);
	else if(req1>h && req2<=h)
		return mid+1;
	else if(req2>h)
		return bsearch(arr,h,n,mid+1,end);
	else if(req1<h)
		return bsearch(arr,h,n,start,mid-1);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		ll h;
		cin>>n>>h;
		ll arr[n];
		fr(i,n)	cin>>arr[i];

		cout<<bsearch(arr,h,n,1,1000000000)<<endl;
	}
	return 0;
}