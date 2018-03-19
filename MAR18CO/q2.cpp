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
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,flag=0;
		cin>>n>>m;
		long long int arr[n][m];
		fr(i,n)
			fr(j,m)
				cin>>arr[i][j];


		if(arr[0][0]==-1)
			arr[0][0]=1;

		for(int i=1;i<n;i++){
			if(arr[i][0]!=-1 && arr[i][0]<arr[i-1][0])
				flag=1;
			if(arr[i][0]==-1)
				arr[i][0]=arr[i-1][0];
		}

		for(int i=1;i<m;i++){
			if(arr[0][i]!=-1 && arr[0][i]<arr[0][i-1])
				flag=1;
			if(arr[0][i]==-1)
				arr[0][i]=arr[0][i-1];
		}

		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
			{
				if(arr[i][j]!=-1 && (arr[i][j]<arr[i][j-1] || arr[i][j]<arr[i-1][j]))
					flag=1;
				if(arr[i][j]==-1)
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
			}
		if(flag==1)
			cout<<"-1"<<endl;
		else
			{
				fr(i,n){
					fr(j,m){
						cout<<arr[i][j]<<" ";
					}
					cout<<endl;
				}
			}

	}
}