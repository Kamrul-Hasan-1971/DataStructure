/*AVL Tree is a self-balancing Binary Search Tree (BST)
where the difference between heights of left and right
subtrees cannot be more than one for all nodes.*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int key , height;
    Node *left;
    Node *right;
    Node() : key(0),left(NULL),right(NULL),height(1){}
    Node(int keyValue) : key(keyValue),left(NULL),right(NULL),height(1){}
    Node(int keyValue, Node *left, Node *right) : key(keyValue),left(left),right(right),height(1){}
};

int height(Node *N)
{
    if(N == NULL) return 0;
    return N->height ;
}


int getBalance(Node *N)
{
    if( N == NULL) return 0;
    return height(N->left) - height(N->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left ;
    Node *T2 = x -> right ;

    //perform rotation
    x -> right = y ;
    y -> left = T2 ;

    //update heights
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    return x ;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right ;
    Node *T2 = y->left ;

    //perform rotation
    y->left = x ;
    x->right = T2 ;

    //update heights
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return y;
}


Node *insert(Node* node , int key)
{
    if(node == NULL) return (new Node(key));

    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if( key > node->key){
        node->right = insert(node->right,key);
    }
    else{
        return node; //Equal keys are not allowed in BST
    }
    //update height of this ancestor node
    node -> height = 1+max(height(node->left),height(node->right));

    //Get the balance factor of this ancestor
    //node to check whether this node became unbalanced
    int balance = getBalance(node);

    //left left case
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    //right right case
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    //left right case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //right left case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node ;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int n , key ;
    cin >> n ;
    for( int i = 1 ; i<= n ; i++)
    {
        cin >> key ;
        root = insert(root,key);
    }
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
