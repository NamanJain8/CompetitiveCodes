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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll s[n],cs[n];
		cin>>s[0];	cs[0]=s[0];
		frr(i,1,n)	{
			cin>>s[i];
			cs[i]=cs[i-1]+s[i];
		}

		///////////////////////////

		ll res[n]={0};
		
		fr(i,n)
		{
			for(int j=i-1;j>=0;j--)
			{
				ll diff=cs[i-1]-cs[j];
				if(diff>s[i])
					break;
				else
					res[j]++;
			}

			for(int j=i+1;j<n;j++)
			{
				ll diff=cs[j-1]-cs[i];
				if(diff>s[i])
					break;
				else
					res[j]++;
			}
		}
		////////////////////////////

		fr(i,n)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}