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

int main(){
	int t;	cin>>t;
	while(t--){
		ll n,k;	cin>>n>>k;
		ll all1=pow(2,ceil(log2(k)+1))-1;
		if(k==1){
			fr(i,n)	cout<<"1 ";
			cout<<endl;
			continue;
		}
		if((k^all1)==0)
		{
			if(n%2==0){
				cout<<k-1<<" ";
				cout<<(all1^(k-1))<<" ";
				fr(i,n-2)	cout<<"1 ";
			}
			else
			{
				fr(i,n)	cout<<k<<" ";
			}
		}
		else{
			if(n%2==0){
				cout<<k<<" "<<(all1^k)<<" ";
				fr(i,n-2)	cout<<"1 ";
			}
			else{
				if(n==3 and (k^all1)-1==0){
					cout<<k<<" "<<"3 "<<"2 "<<endl;
					continue;
				}
				if(n>=3){
					cout<<k<<" "<<(all1^k)<<" "<<"2 "<<"3 ";
					fr(i,n-4)	cout<<"1 ";
				}
				if(n==1)
					cout<<k;
			}
		}
		cout<<endl;
	}
	return 0;
}