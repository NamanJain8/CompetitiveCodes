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

void LPS(int lps[],string s, int l){
	lps[0]=0;
	int len=0;
	for(int i=1;i<l;i++){
		if(s[i]==s[len])
			lps[i]=++len;
		else{
			if(len!=0){
				len=lps[len-1];
				i--;
			}
			else
				lps[i]=len;
		}
	}
	// int ans=0;
	// for(int i=0;i<l;i++)
	// 	if(lps[i]>ans)
	// 		ans=lps[i];
	// return ans;
	return;
}

int main()
{
	int t;	cin>>t;
	while(t--){
		string s,tex;	cin>>tex>>s;
		int l=s.length();
		int l2=tex.length();
		int lps[l];
		memset(lps,0,sizeof(lps));
		LPS(lps,s,l);
		for(int i=0;i<l;i++)
			cout<<lps[i]<<" ";
		cout<<endl;
		int i=0,j=0;
		for(;i<l2;){
			if(tex[i]==s[j]){
				i++;	j++;
			}
			if(j==l){
				cout<<"Found at:"<<i-j<<endl;	j=lps[j-1];
			}
			else if(i<l2 and s[j]!=tex[i]){
				if(j!=0)
					j = lps[j-1];
				else
					i++;
			}
		}
	}
}