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
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(v,it) for(typeof((v).begin()) it = (v).begin(); it != (v).end() ; it++)
#define vpresent(v,x) ((v).find(x) != (v).end())
#define present(v,x) (find(all(v),x) != (v).end())
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
#define INF 2000000000
#define mydtype set< pair< ll,pair<ll,ll> > >
#define mod 1000000007
#define gmax 2000000

void make_fact(ll fact[]){
	fact[0]=1;
	for(ll i=1;i<2000000;i++)
		fact[i]=(fact[i-1]*i)%mod;
}

ll power(ll a, ll b){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	

ll mod_inverse(ll a)
{
	return power(a, mod-2);
}

ll nCr(ll n, ll r,ll fact[])
{
	ll ans=1;
	frr(i,1,n+1)
		ans=((ans%mod)*(i%mod))%mod;
	frr(i,1,r+1)
		ans/=i;
	frr(i,1,n-r+1)
		ans/=i;
	return ans;

	/*ll a1=mod_inverse(fact[r]);
	ll a2=mod_inverse(fact[n-r]);
	return (fact[n]*((a1*a2)%mod))%mod;*/
}

////////////////////////////
ll f[100001];
 
ll powr(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD; 	
 	b /= 2;
 	}
 return x;
}
 
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
 return powr(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
 
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
//////////////////////////



void displayData(mydtype mins){
	mydtype::iterator it;
	for(it=mins.begin();it!=mins.end();it++)
	{
		pair<ll,pair<ll,ll> > p_dash = *it;
		ll sz=p_dash.first;
		pair<ll,ll> pr = p_dash.second;
		ll g=pr.first;
		ll b=pr.second;
		cout<<sz<<" "<<g<<" "<<b<<endl;
	}
}

int main()
{

	f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)
		f[i] = (f[i-1]*i)%mod;
	ll ans=0;
	ll *fact;
	fact=(ll*)malloc(2000000*sizeof(ll));
	ll p,q,c,m;	cin>>p>>q>>c>>m;
	ll rem=p+q-c-1;
	mydtype mins;
	fr(i,m){
		ll g,b;	cin>>g>>b;
		mins.insert(mp(g-c-1+b,mp(g-c-1,b)));
	}

	//displayData(mins);
	//make_fact(fact);
	//remove extras
	//cout<<C(10001,10000,mod)<<endl;

	mydtype::iterator it;
	for(it=mins.begin();it!=mins.end();it++)
	{
		pair<ll,pair<ll,ll> > p_dash = *it;
		ll sz=p_dash.first;
		pair<ll,ll> pr = p_dash.second;
		ll g=pr.first;
		ll b=pr.second;
		if(g<0)	mins.erase(it);
		else if(sz>rem)	mins.erase(it);
	}

	while(mins.size()!=0)
	{
		mydtype::iterator it;
		it=mins.end();	it--;
		pair <ll,pair<ll,ll> > p_dash = *(it);
		ll sz=p_dash.first;
		pair<ll,ll> pr = p_dash.second;
		ll g=pr.first;
		ll b=pr.second;

		ll var=C(g,b,mod)*pow(2,rem-sz);
		var%=mod;
		ans+=var;
		ans%=mod;
		cout<<ans<<endl;

		for(it=mins.begin();it!=mins.end();it++)
		{
			pair<ll,pair<ll,ll> > p_dash = *it;
			ll sz=p_dash.first;
			pair<ll,ll> pr = p_dash.second;
			ll g1=pr.first;
			ll b1=pr.second;
			if(g1<=g and b1<=b)	mins.erase(it);
			else if(g1+b1>g+b)	mins.erase(it);
		}

	}
	cout<<ans;

	return 0;
}