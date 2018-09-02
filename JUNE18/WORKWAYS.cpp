#include <bits/stdc++.h>
using namespace std;
#if DEBUG && !ONLINE_JUDGE
    #include "/home/chaman/Desktop/cpp/debug.h"
#else
    #define debug(args...)
    #define DBG(x...)
#endif
typedef     long long int                        ll;
typedef     long double                          ld;
typedef     vector<ll>                           vi;
typedef     pair<ll,ll>                          pii;
typedef     vector<pii>                          vpi;
typedef     vector<vi>                           vvi;
typedef     map<ll,ll>                           mii;
typedef     map<char,ll>                         mci;
typedef     priority_queue<ll>                   pqi;
typedef     priority_queue<pii>                  pqii;
typedef     priority_queue<ll,vi,greater<ll>>    pqmini;
typedef     priority_queue<pii,vpi,greater<pii>> pqminpi;
 
#define     fi              first
#define     se              second
#define     sz(a)           (ll)((a).size())
#define     rep(i,n)        for(ll i=0;i<n;i++)
#define     repA(i,a,n)     for(auto i=a;i<=n;i++)
#define     repD(i, a, n)   for(auto i = a; i >= (n); --i)
#define     trav(a, x)      for(auto& a : x)
#define     all(x)          x.begin(), x.end()
#define     fill(a)         memset(a, 0, sizeof (a))
#define     pb              push_back
#define     MOD             1000000007
#define     PI              3.14159265359
#define     EULER           2.7182818284
 
//////////////////////////////////////////////////////////////////////
vi divisor,div1;
vi ans,fans;
ll n,c;
 
 
ll div(ll m,ll rem,ll cnt){
    if(cnt==n &&rem==1) return 1;
    if(cnt>n) return 0;
    if(rem==1) {
        ans[cnt]=1;
        return div(m,rem,cnt+1);
    }
    ll pos=1;
    if(rem ==1)pos=0;
    DBG(divisor[m]);
    while(pos<sz(divisor) && (divisor[m]+1>=(divisor[pos]))){
        if(rem%divisor[pos]==0){
            if (cnt<n&&div(pos,rem/divisor[pos],cnt+1)) {
                ans[cnt]=divisor[pos];
                return 1;
            }
        }
        pos++;
    }
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    ll t;
    cin>>t;
    srand(time(NULL));
    while(t--){
        cin>>n>>c;
        divisor.clear();
        div1.clear();
        ans.clear();
        ans.resize(n);
        fans.clear();
        
        ll tt = sqrt(c);
        divisor.pb(1);
        repA(i,2,tt){
            if(c%i==0){
                divisor.pb(i);
                div1.pb(c/i);
            }
        }
        repD(i,sz(div1)-1,0)divisor.pb(div1[i]);
        divisor.pb(c);
        ll l = sz(divisor);
        DBG(divisor);
        ll start = 0;
        while(start<l){
            ans.clear();
            ans.resize(n);
            ans[0]=(divisor[start]);
            ll t = div(start,c/divisor[start],1);
            if(t) {
                fans = ans;
                break;
            }
            start++;
        }
        ll s=n-1;
        vi v;
        for(auto i:fans){
            v.pb(i+s);
            s--;
        }
        sort(all(v));
        for(auto i:v)cout<<i<<' ';
        cout<<endl;
    }
    debug("\nRuntime = " + to_string((ll)clock()/CLOCKS_PER_SEC));
    return 0;
} 