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
		ll a,b,a1,b2;	cin>>a>>b;
		a1=a;	b2=b;
		int cnt1=0,cnt2=0,k=0;
		while(a1!=0){
			if(a1%2!=0)	cnt1++;
			a1/=2;
		}

		while(b2%2==0 and b2!=0){
			k++;	b2/=2;
		}

		b2=b;
		while(b2!=0){
			if(b2%2!=0)	cnt2++;
			b2/=2;
		}
		if(a==b)
			cout<<"0"<<endl;
		else{
			int diff=cnt2-cnt1+k;
			if((b==1 and a!=0) or b==0)
				cout<<"-1"<<endl;
			else if(diff>0)
				cout<<diff<<endl;
			else
				cout<<"2"<<endl;
		}
	}
	return 0;
}