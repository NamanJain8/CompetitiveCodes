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
		string str;	cin>>str;
		int len=str.length();
		int mat[26][len]={0};
		for(int j=0;j<26;j++)
		{
			if(j >= str[0]-'a')
				mat[j][0] = 1;
			else
				mat[j][0] = 0;
		}
		for(int i=1;i<len;i++){
			for(int j=0;j<26;j++){
				if(j >= str[i]-'a')
					mat[j][i] = mat[j][i-1]+1;
				else
					mat[j][i] = mat[j][i-1];
			}
		}

		/*
		fr(i,26){
			fr(j,len){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/

		// Computes Y //
		ll y=0;
		for(int i=1;i<len;i++)
		{
			if(str[i]!='a')
				y += mat[str[i]-'a'-1][i-1];
		}

		ll maxdiff=0;

		for(int i=0;i<len;i++){
			ll contrib=0;
			if(str[i]!='a' and i!=0)
				contrib += mat[str[i]-'a'-1][i-1];
			contrib += len-1-i - (mat[str[i]-'a'][len-1]-mat[str[i]-'a'][i]);
			
			for(int j=0;j<26;j++){
				ll newc=0;
				if(j!=0 and i!=0)
					newc += mat[j-1][i-1];
				newc += len-1-i - (mat[j][len-1]-mat[j][i]);
				newc += abs(str[i]-'a'-j);
				
				if(maxdiff < contrib - newc)
					maxdiff = contrib - newc;
			}
		}
		cout<<y-maxdiff<<endl;
	}
}
