#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
int main()
{
int T;
cin>>T;
while(T--)
{
    memset(graph,0,sizeof graph);
    int N,E;
    cin>>E>>N;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    topoSort(graph,N);
    // bool valid =true;
    // for(int i=0;i<N;i++)
    // {
    //     int n=graph[res[i]].size();
    //     for(int j=0;j<graph[res[i]].size();j++)
    //     {
    //         for(int k=i+1;k<N;k++)
    //         {
    //             if(res[k]==graph[res[i] ] [j] )
    //                 n--;
    //         }
    //     }
    //     if(n!=0)
    //     {
    //         valid =false;
    //         break;
    //     }
    // }
    // if(valid==false)
    //     cout<<0<<endl;
    // else
    //     cout<<1<<endl;
}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You need to complete this function */
int * topoSort(vector<int> graph[], int N)
{
    int visited[N];
    memset(visited,0,sizeof(visited));

    int counter=0;
    stack<int> ans;
    stack<int> s;
    
    for(int i=0;i<N;i++){
        if(visited[i])
            continue;
        s.push(i);
        while(!s.empty()){
            int u = s.top();
            visited[i]=1; 
            vector<int>::iterator it;
            for(it=graph[u].begin();it!=graph[u].end();it++){
                // cout<<*it<<endl;
                if(!visited[*it])
                    s.push(*it);
            }
        }
    }

    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}