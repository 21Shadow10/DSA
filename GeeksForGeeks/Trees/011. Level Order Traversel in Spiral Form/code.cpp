// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ret ;
    deque<Node*> dq;
    int l=1;
    Node *temp ;
    if(root==NULL) return ret ;
    ret.push_back(root->data) ;
    dq.push_back(root) ;
    
    while(!dq.empty()) {
        int n = dq.size() ;
        for(int i=0;i<n;i++) {
            if(l%2!=0){
                temp = dq.front() ;
                dq.pop_front() ;
            }
            else {
                temp = dq.back();
                dq.pop_back() ;
            }
            
            if(l%2!=0) {
                if(temp->left) {
                    dq.push_back(temp->left);
                    ret.push_back(temp->left->data) ;
                }
                if(temp->right) {
                    dq.push_back(temp->right) ;
                    ret.push_back(temp->right->data) ;
                }
            }
            
            else if(l%2==0) {
                if(temp->right) {
                    dq.push_front(temp->right) ;
                    ret.push_back(temp->right->data);
                }
                if(temp->left) {
                    dq.push_front(temp->left) ;
                    ret.push_back(temp->left->data) ;
                }
            }
        }
        l++;
    }
    
    return ret ;
}
