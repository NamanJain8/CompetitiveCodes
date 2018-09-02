
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  
int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int findIslands(int A[MAX][MAX], int N, int M)
{
	int visited[N][M];
	memset(visited,0,sizeof(visited));
	int ans=0;

	stack <pair<int,int > > s;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visited[i][j] or A[i][j]==0)
				continue;
			ans++;
			s.push({i,j});
			while(!s.empty()){
				pair<int,int> p = s.top();
				int x = p.first;	int y = p.second;
				visited[x][y]=1;
				s.pop();
				if(x<N-1 and y<M-1 and visited[x+1][y+1]==0 and A[x+1][y+1]==1)
					s.push({x+1,y+1});
				if(x<N-1 and visited[x+1][y]==0 and A[x+1][y]==1)
					s.push({x+1,y});
				if(y<M-1 and visited[x][y+1]==0 and A[x][y+1]==1)
					s.push({x,y+1});
				if(x<N-1 and y>0 and visited[x+1][y-1]==0 and A[x+1][y-1]==1)
					s.push({x+1,y-1});

				if(x>0 and y>0 and visited[x-1][y-1]==0 and A[x-1][y-1]==1)
					s.push({x-1,y-1});
				if(x>0 and visited[x-1][y]==0 and A[x-1][y]==1)
					s.push({x-1,y});
				if(y>0 and visited[x][y-1]==0 and A[x][y-1]==1)
					s.push({x,y-1});
				if(x>0 and y<M-1 and visited[x-1][y+1]==0 and A[x-1][y+1]==1)
					s.push({x-1,y+1});
			}
		}
	}
	return ans;
}