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

int pageFaults(int arr[],int n, int c){
	int faults=0;
	set <int> s;
	map <int,int> index;
	for(int i=0;i<n;i++){
		if(s.size() < c){
			if(s.find(arr[i])==s.end()){
				s.insert(arr[i]);	faults++;
			}
			index[arr[i]]=i;
		}
		else{
			if(s.find(arr[i])==s.end()){
				int lru=INF,val;
				for(auto it=s.begin();it!=s.end();it++){
					if(index[*it]<lru){
						lru=index[*it];
						val=*it;
					}
				}
				s.erase(val);
				s.insert(arr[i]);
				faults++;
			}
			index[arr[i]]=i;
		}
	}
	return faults;
}

int main(){
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int arr[n];
		fr(i,n)	cin>>arr[i];
		int c;	cin>>c;
		cout<<pageFaults(arr,n,c)<<endl;
	}
}