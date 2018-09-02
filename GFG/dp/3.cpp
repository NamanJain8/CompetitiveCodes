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

int jump(int arr[], int n){
	int jcnt=0;
	for(int i=0;i<n;){
		if(arr[i]==0)
			return -1;
		if(arr[i]>=n-i-1){
			jcnt++;	break;
		}

		int idx=-1;
		int maxi=0;
		for(int j=i+1;j<=i+arr[i] and j<n;j++){
			int off = arr[j]+j-i;
			if(off>maxi){
				maxi = off; 
				idx = j; 
			}
 		}
 		if(idx==-1 and maxi==0){
 			jcnt=-1;
 			break;
 		}
 		else{
	 		i=idx;
	 		jcnt++;
	 	}
	}
	return jcnt;
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