
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printSpiral(root);
    cout<<endl;
  }
    return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
     stack<Node*> s1;
     stack<Node*> s2;
     s1.push(root);
     while(!(s1.empty() and s2.empty())){

      if(s2.empty()){
        while(!s1.empty())
        {
          Node* top = s1.top();
          s1.pop();
          cout<<top->data<<" ";
          if(top->right != NULL)
            s2.push(top->right);
          if(top->left != NULL)
            s2.push(top->left);
        }  
      }

      if(s1.empty()){
        while(!s2.empty())
        {
          Node* top = s2.top();
          s2.pop();
          cout<<top->data<<" ";
          if(top->left != NULL)
            s1.push(top->left);
          if(top->right != NULL)
            s1.push(top->right);
        }  
      }
     }
}