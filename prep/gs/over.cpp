#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;	cin>>t;
	while(t--){
		int x1,x2,x3,x4,y1,y2,y3,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if(((x1<x4 and x1>=x2) or (x3<x2 and x3>=x1)) and ((y1<x4 and y1>=y2) or (y3<y2 and y3>=y1))) 
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
}