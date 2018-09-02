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
		int mat[n][n];
		int sx,sy;
		fr(i,n)	fr(j,n) {
			int ele;	cin>>ele;
			mat[i][j]=ele;
			if(ele==1)	{
				sx=i;	sy=j;
			}
		}	
		int vis[n][n]={0};
		stack <pair<int,int> > s;
		s.push({sx,sy});
		int flag=0;
		while(!s.empty()){
			if(flag)	break;
			pair<int,int>	p = s.top();
			int x=p.first,y=p.second;
			s.pop();
			vis[x][y]=1;

			for(int i=x-1;i<=x+1;i++){
				if(flag)	break;
				for(int j=y-1;j<=y+1;j++){
					if(i<0 or j<0 or j>=n or i>=n or (i==x and j==y) or (abs(i-x)+abs(j-y)==2))
						continue;
					if(mat[i][j]==3 and vis[i][j]==0)
						s.push({i,j});
					if(mat[i][j]==2){
						// cout<<i<<" "<<j<<endl;
						flag=1;
						break;
					}
				}
			}
		}
		cout<<flag<<endl;
	}
}