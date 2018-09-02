#include <stdio.h>
#include <stdlib.h>
int main(){
	int t;	scanf("%d",&t);
	while(t--){
		int k;	scanf("%d",&k);
		char str[100];
		scanf("%s",str);
		int ans=0;
		int level = -1;
		int i=0;
		while(str[i]!='\0'){
			if(str[i]=='(')	level++;
			else if(str[i]==')')	level--;
			else if(level==k){
				// printf("%c",str[i]);
				int j=i;
				char tmp[10]="";
				int k=0;
				while(str[j]!='(' && str[j]!=')'){
					tmp[k]=str[j];	j++;	k++;
				}
				// printf("%d ",atoi(tmp));
				ans+=atoi(tmp);
				i = j-1;
			}
			// printf("%d\n",level );
			i++;
		}
		printf("%d\n",ans );
	}
	return 0;
}