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
	while(t--)
	{
		int x1,x2,x3,v1,v2;	cin>>x1>>x2>>x3>>v1>>v2;
		float t1=abs(x1-x3)*1.0/v1;
		float t2=abs(x2-x3)*1.0/v2;
		if(t1==t2)	cout<<"Draw"<<endl;
		else if(t1<t2) cout<<"Chef"<<endl;
		else cout<<"Kefa"<<endl;
	}
}