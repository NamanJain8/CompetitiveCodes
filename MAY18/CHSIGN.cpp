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
		int n;	cin>>n;
		ll arr[n+2];

		for(int i=1;i<n+1;i++)	cin>>arr[i];
		arr[0]=INF;	arr[n+1]=INF;
		
		frr(i,1,n+1)
			if(arr[i]<arr[i-1] and arr[i]<arr[i+1]){
				arr[i]=-arr[i];
				i++;
			}

		frr(i,1,n+1){
			if(arr[i-1]+arr[i]+arr[i+1]>0)	continue;
			else{
				int start=i,end=i,curr=i+2;
				ll sum1=0,sum2=0;
				
				while(curr<n+1 and arr[curr-1]+arr[curr]+arr[curr+1]<=0){
					end=curr;	curr+=2;
				}
				for(int j=start-1;j<=end+1;j+=4)
					sum1+=arr[j];
				for(int j=start+1;j<=end+1;j+=4)
					sum2+=arr[j];
				
				if(sum1>=sum2)
					for(int j=start-1;j<=end+1;j+=4)
						arr[j]=-arr[j];
				else
					for(int j=start+1;j<=end+1;j+=4)
						arr[j]=-arr[j];
				i=end;
			}
		}
		frr(i,1,n+1)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}