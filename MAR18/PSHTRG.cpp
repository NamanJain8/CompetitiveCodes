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

/*ll bsearch(ll arr[],ll start,ll end,ll size)
{
	if(end-start<3)
		return 0;

	ll mid=(start+end)/2;
	int p1=0,p2=0;
	if(mid<size-1){
		p1=1;
		p2=0;
	}		

	if(arr[mid]<arr[mid-1]+arr[mid-2])
		p1=1;
	if(arr[mid+1]<arr[mid]+arr[mid-1])
		p2=1;

	if(p1==1 && p2==1)
		return bsearch(arr,mid+1,end,size);
	if(p1==1 && p2==0)
		return arr[mid]+arr[mid-1]+arr[mid-2];
	if(p1==0 && p2==1)
		return bsearch(arr,mid+1,end,size);
	if(p1==0 && p2==0)
		return bsearch(arr,start,mid,size);

}*/

int main()
{
	int n,q;
	cin>>n>>q;
	int arr[n];
	fr(i,n)	cin>>arr[i];

	while(q--)
	{
		ll type,x1,x2;
		cin>>type>>x1>>x2;
		x1--;
		if(type==1)
			arr[x1]=x2;
		else if(type==2)
		{
			x2--;
			ll peri=0;
			int size=x2-x1+1;
			if(size<3){
				cout<<"0"<<endl;
				continue;
			}

			ll new_arr[size];

			frr(i,0,size)	new_arr[i]=arr[i+x1];
			sort(new_arr,new_arr+size);
			
			for(int i=size-1;i>=2;i--)
				if(new_arr[i]<new_arr[i-1]+new_arr[i-2]){
					peri=new_arr[i]+new_arr[i-1]+new_arr[i-2];
					break;
				}
			cout<<peri<<endl;
		}
	}
	return 0;
}