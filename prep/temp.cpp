#include <bits/stdc++.h>
using namespace std;

template <typename T> T Max(T a, T b){
	return a<b ? b:a;
}

int main(){
	cout<<Max(1,20)<<endl;
	cout<<Max(1.3,3.1)<<endl;
	return 0;
}