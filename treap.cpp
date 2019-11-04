#include <bits/stdc++.h> 
using namespace std;

class Treap
{
public:
	int key,priority;
	Treap* left;
	Treap* right;
};

Treap* rr(Treap* y)
{
	Treap* x = y->left;
	Treap* z = x->right;
	y->left = z;
	x->right = y;
	return x;
}

Treap* ll(Treap* y)
{
	Treap* x = y->right;
	Treap* z = x->left;
	y->right = z;
	x->left = y;
	return x;
}

Treap* newnode(int key)
{
	Treap* node = new Treap();
	node->key=key;
	node->priority = rand()%100;
	node->left= node->right = NULL;
	return node;
}

Treap* search(Treap* root, int key)
{
	if(root==NULL||root->key == key)
		return root;
	else if(root->key<key)
		return search(root->right,key);
	else
		return search(root->left,key);
}

Treap* insert(Treap* root, int key)
{
	if(!root)
		return newnode(key);
	if(key<root->key)
	{
		root->left = insert(root->left,key);
		if(root->left->priority>root->priority)
			root = rr(root);
	}
	if(key>root->key)
	{
		root->right = insert(root->right,key);
		if(root->right->priority>root->priority)
			root = ll(root);
	}
	return root;
}

Treap* deleten(Treap* root , int key)
{
	if(root==NULL){
		cout<<"This node is not presesnt\n";
		return root;
	}
	if(key<root->key)
		root->left = deleten(root->left,key);
	else if(key>root->key)
		root->right = deleten(root->right,key);
	else if(root->left == NULL)
	{
		Treap* z = root->right;
		delete(root);
		root = z;
		cout<<"Dleted Sucessfully\n";
	}
	else if(root->right == NULL)
	{
		Treap* z = root->left;
		delete(root);
		root = z;
		cout<<"Dleted Sucessfully\n";
	}
	else if(root->left->priority<root->right->priority)
	{ 
		root = ll(root);
		root->left = deleten(root->left,key);
	}
	else
	{
		root = rr(root);
		root->right = deleten(root->right,key);
	}
	return root;
}

void inorder(Treap* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        cout << "key: "<< root->key << " | priority: %d "
            << root->priority; 
        if (root->left) 
            cout << " | left child: " << root->left->key; 
        if (root->right) 
            cout << " | right child: " << root->right->key; 
        cout << endl; 
        inorder(root->right); 
    } 
} 

int main()
{  
    struct Treap *root = NULL; 
    int a=0;
    while(a!=5)
    {
    	cin>>a;
    	if(a==1)
    	{
    		int val;
    		cin>>val;
    		root = root = insert(root, val);
    	}
    	else if(a==2){
    		cout << "Inorder traversal of the given tree \n"; 
   		 	inorder(root); 
    	}
    	else if(a==3){
    		int val;
    		cin>>val;
    		root = deleten(root, val);
    	}
    	else if(a==4)
    	{
    		int val;
    		cin>>val;
		    Treap *res = search(root, val); 
		    (res == NULL)? cout << "\nNot Found ": 
		                   cout << "\nFound";
    	}

    }    
    return 0; 
} 
