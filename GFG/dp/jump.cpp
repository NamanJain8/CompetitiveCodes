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

int jump(int arr[],int n){
	int ans;
	int idx=0;
	int cnt=0;
	while(1){
		int maxi=arr[idx];
		int new_idx=0;
		for(int i=idx;i<arr[idx]+idx+1 and i<n;i++){
			if(i+arr[i]>maxi){
				maxi=i+arr[i];	new_idx = i;
			}
		}
		if(new_idx != idx)	{
			cnt++;	idx=new_idx;
		}
		else
			break;
	}
	ans = cnt;
	if(ans==0)	return -1;
	return ans;
}

int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int arr[n];
		fr(i,n)	cin>>arr[i];

		cout<<jump(arr,n)<<endl;
	}
}