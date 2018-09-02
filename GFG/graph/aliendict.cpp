//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
string printOrder(string dict[], int N, int k)
{
    vector<int> v[k];

   for(int i=0;i<N-1;i++){
    int idx=0;
    while(idx<min(dict[i].length(),dict[i+1].length())){
        int l1 = dict[i][idx]-'a';
        int l2 = dict[i+1][idx]-'a'; 
        if(l1!=l2){
            v[l1].push_back(l2);
            break;
        }
        idx++;
    }
   }

   vector<int> indeg(k,0);
   for(int i=0;i<k;i++){
       vector<int>::iterator it;
       for(it=v[i].begin();it!=v[i].end();it++)
            indeg[*it]++;
   }

    // vector<int>:: iterator it;
    // for(it=indeg.begin();it!=indeg.end();it++)
    //     cout<<*it<<" ";   

   queue <int> q;
   for(int i=0;i<k;i++)
    if(indeg[i]==0) q.push(i);

    vector <int> top_order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        vector<int>:: iterator it;
        for(it=v[u].begin();it!=v[u].end();it++){
            if(--indeg[*it]==0)
                q.push(*it);
        }
    }

    string ans;
    for(int i=0;i<k;i++)
        ans+=char('a'+top_order[i]);
    // cout<<ans<<endl;
    return ans;
}