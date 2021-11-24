// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
  
    Node* lca(Node* root, int n1, int n2) {
        if(root==NULL) return root ;
        
        if(root->data == n1 || root->data == n2)
            return root ;
            
        Node *l = lca(root->left,n1,n2);
        Node *r = lca(root->right,n1,n2);
        
        if(l&&r) return root ;
        
        return (l==NULL)?r:l ;
    }
    
    bool countTurns(Node *root, int k, bool turn, int *count) {
        if(root==NULL) return false;
        
        if(root->data == k) return true;
        
        if(turn==true) {
            if(countTurns(root->left,k,turn,count))
                return true ;
                
            if(countTurns(root->right,k,!turn,count)) {
                *count += 1;
                return true ;
            }
        }
        
        else {
            if(countTurns(root->right,k,turn,count))
                return true ;
                
            if(countTurns(root->left,k,!turn,count)) {
                *count += 1;
                return true ;
        }
    }
}
    
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      
      Node *lc = lca(root,first,second) ;
      
      int count = 0;
      
      if(lc->data != first && lc->data != second) 
      {
          if(countTurns(lc->right,second,false,&count) || 
            countTurns(lc->left,second,true,&count));
            
            if(countTurns(lc->right,first,false,&count) || 
            countTurns(lc->left,first,true,&count));
            
        return count+1;
      }
      
      if(lc->data==first) {
          
          countTurns(lc->right,second,false,&count);
          countTurns(lc->left,second,true,&count);
          
          return count ;
      }
      
      else {
          countTurns(lc->right,first,false,&count);
          countTurns(lc->left,first,true,&count);
          
          return count ;
      }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends