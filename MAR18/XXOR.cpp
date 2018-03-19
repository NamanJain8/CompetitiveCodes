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
	unsigned int n,q,ele;
	cin>>n>>q;
	unsigned int a[n][31]={0},ca[n][31]={0};
	cin>>ele;
	int idx=0;
	while(idx<31)
	{
		a[0][idx]=ele%2;	ca[0][idx]=ele%2;
		ele=ele>>1;
		idx++;
	}

	frr(i,1,n)	{
		cin>>ele;
		idx=0;
		while(idx<31)
		{
			a[i][idx]=ele%2;	ca[i][idx]=ele%2 + ca[i-1][idx];
			ele=ele>>1;
			idx++;
		}
	}

	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;	r--;
		unsigned int ans[31]={0};
		if(l==0)
		{
			fr(i,31)
				if(ca[r][i]<(r-l+2)/2)
					ans[i]=1;
		}
		else
		{
			fr(i,31)
				if(ca[r][i]-ca[l-1][i]<(r-l+2)/2)
					ans[i]=1;
		}
		int result=0;
		result+=ans[0];
		frr(i,1,31)
			result+=pow(2*ans[i],i);
		cout<<result<<endl;
	}

	return 0;
}