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
	int n;	cin>>n;
	string arr[n];
	fr(i,n)	cin>>arr[i];
	int q;	cin>>q;
	vector< pair < pii, string > > queries;
	fr(i,q){
		int r;	string s;
		cin>>r>>s;
		queries.pb( mk( mk(r,i) ,s) );
	}
	sort(queries.begin(),queries.end());
	string ans[q];

	set<string> sorted;
	int i=0;
	tr(queries,it){
		pair<int,int> p = (*it).first;
		string s= (*it).second;
		int r = p.first;
		int idx = p.second;

		while(i<r){
			sorted.insert(arr[i]);
			i++;
		}

		string temp="";
		string prev="";
		string first = *(sorted.begin());
		string last = *(sorted.rbegin());

		fr(j,s.length()){
			temp+=s[j];
			bool already = (sorted.find(temp)!=sorted.end());
			if(already)
				prev = temp;
			else{
				if( temp > last )
					break;
				sorted.insert(temp);
				set<string>::iterator ptr=sorted.find(temp);

				string s2=*(++ptr);
				string com="";
				for(int k=0;k<temp.length() and k<s2.length();k++)
					com+=s2[k];
				sorted.erase(temp);
				if(temp==com)
					prev=s2;
				else
					break;
			}
		}
		if(prev=="")
			prev=first;
		ans[idx]=prev;
	}

	fr(i,q)
		cout<<ans[i]<<endl;
	return 0;
}