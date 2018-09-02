
// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   /* Let us create the example graph discussed above */
   int t;
int V;
   cin>>t;
   while(t--){
cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
  int dis[V];
  set<pair<int,int> > myset;
  for(int i=0;i<V;i++){
   myset.insert({graph[s][i],i});
   dis[i] = graph[s][i];
 }
    while(!myset.empty()){
      pair<int,int> p = *(myset.begin());
      int d = p.first;
      int v = p.second;
      myset.erase({d,v});
      for(int i=0;i<V;i++){
        if(dis[i] > d+graph[v][i]){
          myset.erase({dis[i],i});
          dis[i] = d+graph[v][i];
          myset.insert({dis[i],i});
        }
      }
    }

  for(int i=0;i<V;i++)
    cout<<dis[i]<<" ";
}