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
		int siz1=0,siz2=0,cnt1=0,cnt2=0;
		while(a1!=0){
			siz1++;
			if(a1%2!=0)	cnt1++;
			a1/=2;
		}
		while(b2!=0){
			siz2++;
			if(b2%2!=0)	cnt2++;
			b2/=2;
		}
		int ans=0,diff;
		diff=siz1-siz2;
		if(a==b)	cout<<"0"<<endl;
		if(a+1==b)	cout<<"1"<<endl;
		if(cnt1==cnt2){
			if(diff>=0)	cout<<"1"<<endl;
			else cout<<"2"<<endl;
		}
		else if(cnt1>cnt2){
			if(diff<0)
				ans++;
			if((a+1)%(ll)pow(2,diff)==0 and (a+1)%(ll)pow(2,diff+1)!=0)
				ans+=2;
			else{
				ans+=2;
				if(b%(ll)pow(2,diff)!=0)
					ans++;
			}
			cout<<ans;
		}
		else if(cnt1<cnt2){
			if(diff<0)
				ans++;
			int n=cnt2-cnt1;
			if(!a%2 and b%2)
				ans+=2*n-1;
			else if(!a%2 and !b%2)
				ans+=2*n;
			else if(a%2 and b%2)
				ans+=2*n;
			else
				ans+=2*n+1;
			cout<<ans<<endl;
		}
	}
	return 0;
}