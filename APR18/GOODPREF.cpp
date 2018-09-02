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
		string s;	int n;
		cin>>s;	cin>>n;
		int sz=s.size();
		int arr[sz];
		ll count=0;

		s[0]=='a'?arr[0]=1:arr[0]=-1;
		frr(i,1,sz){
			if(s[i]=='a')
				arr[i]=arr[i-1]+1;
			else
				arr[i]=arr[i-1]-1;
		}

		int diff=arr[sz-1];
		
		int cor[sz]={0};

		fr(i,sz){
			if(diff>0){
				if(arr[i]>0)
					cor[i]=n;
				else{
					while(arr[i]<=0 and cor[i]<n)
					{
						arr[i]+=diff;
						cor[i]++;
					}
					cor[i]=n-cor[i];
				}
			}
			else if(diff<0){
				if(arr[i]<=0)
					cor[i]=0;
				else
					while(arr[i]>0 && cor[i]<n)
					{
						arr[i]+=diff;
						cor[i]++;
					}
			}
			else
				cor[i]=arr[i]>0?n:0;
		}
		fr(i,sz)
			count+=cor[i];
		cout<<count<<endl;
	}
	return 0;
}