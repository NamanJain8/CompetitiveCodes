#include <bits/stdc++.h>
using namespace std;

#define ll long double
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
#define norm 100000

ll con(ll py,ll pz,ll qy,ll qz,ll cy,ll cz){
	return (cy-py)*qz + cz*py - (cz-pz)*qy - cy*pz;
}
ll mul(ll py,ll pz,ll cy,ll cz,ll dy,ll dz){
	return (cy-py)*dz - (cz-pz)*dy;
}

void sq(ll arr[],ll a,ll b){
	arr[0]=a*a;
	arr[1]=2*a*b;
	arr[2]=b*b;
	return;
}

int main()
{
	int t;	cin>>t;
	while(t--){
		ll px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r;
		cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
		px/=norm;	py/=norm;	pz/=norm;
		qx/=norm;	qy/=norm;	qz/=norm;
		dx/=norm;	dy/=norm;	dz/=norm;
		cx/=norm;	cy/=norm;	cz/=norm;
		r/=norm;
		
		ll x[3],y[3];
		x[0] = con(py,pz,qy,qz,cy,cz);
		y[0] = mul(py,pz,cy,cz,dy,dz);

		x[1] = con(pz,px,qz,qx,cz,cx);
		y[1] = mul(pz,px,cz,cx,dz,dx);

		x[2] = con(px,py,qx,qy,cx,cy);
		y[2] = mul(px,py,cx,cy,dx,dy);

		ll arr[3];
		ll a[3]={0},b[3]={0};

		fr(i,3){
			sq(arr,x[i],y[i]);
			fr(j,3)
				a[j]+=arr[j];
		}

		sq(arr,qx-px,dx);
		fr(i,3)
			b[i]+=arr[i];

		sq(arr,qy-py,dy);
		fr(i,3)
			b[i]+=arr[i];
		
		sq(arr,qz-pz,dz);
		fr(i,3)
			b[i]+=arr[i];

		fr(i,3)
			b[i]*=r*r;

		ll a1,b1,c1;
		a1 = a[2]-b[2];
		b1 = a[1]-b[1];
		c1 = a[0]-b[0];
		ll det = sqrt( pow(b1,2) - 4*a1*c1 );
		ll ans,ans1,ans2;
		if(a1!=0){
			ans1=(double)(-b1+det)/(2*a1);
			ans2=(double)(-b1-det)/(2*a1);
			if(ans1>ans2 and ans2>=0)
				ans=ans2;
			else if(ans1<ans2 and ans1<0)
				ans=ans2;
			else
				ans=ans1;
		}
		else
			ans=-(double)c1/b1;

		cout<<setprecision(20)<<ans<<endl;

	}
	return 0;
}