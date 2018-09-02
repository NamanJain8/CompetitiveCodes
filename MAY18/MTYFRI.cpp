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
		int n,k;	cin>>n>>k;
		int a[n-n/2],b[n/2];
		fr(i,n){
			if(i%2==0)
				cin>>a[i/2];
			else
				cin>>b[i/2];
		}
		sort(a,a+n-n/2,greater<int>());	sort(b,b+n/2);
		
		ll s1=0,s2=0;
		int i;
		for(i=0;i<k and i<n/2;i++){
			if(a[i]<b[i])	break;
			s2+=a[i];	s1+=b[i];
		}
		for(;i<n/2;i++){
			s2+=b[i];	s1+=a[i];
		}
		if(n%2!=0)
			s1+=a[n-n/2-1];
		if(s2>s1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
			
		//cout<<s1<<" "<<s2<<endl;
	}
}