#include <stdio.h>

int main(){
	int t;	scanf("%d",&t);
	while(t--){
	int n;	scanf("%d",&n);
	int dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=0;
		for(int j=0;j<=i-1;j++){
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	printf("%d\n",dp[n]);
	}
	return 0;
}