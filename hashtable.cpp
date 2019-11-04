#include <bits/stdc++.h> 
using namespace std;

class Node 
{ 
    public: 
    int key; 
    int val;
    Node *left; 
    Node *right; 
    int height; 
}; 


int max(int a, int b); 

 
int height(Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

Node* newNode(int key,int val) 
{ 
    Node* node = new Node(); 
    node->key = key; 
    node->val = val;
    node->left = NULL; 
    node->right = NULL; 
    node->height = 1; 
    return(node); 
} 
 
Node *rightRotate(Node *y) 
{ 
    Node *x = y->left; 
    Node *T2 = x->right; 
 
    x->right = y; 
    y->left = T2; 

    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
    x->height = max(height(x->left), 
                    height(x->right)) + 1; 

    return x; 
} 
 
Node *leftRotate(Node *x) 
{ 
    Node *y = x->right; 
    Node *T2 = y->left; 

    y->left = x; 
    x->right = T2; 

    x->height = max(height(x->left), 
                    height(x->right)) + 1; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 

    return y; 
} 


int getBalance(Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - 
        height(N->right); 
} 

Node* insert(Node* node, int key,int val) 
{ 
    
    if (node == NULL){ 
    	cout<<"Inserted\n";
        return(newNode(key,val));}

    if (key < node->key) 
        node->left = insert(node->left, key,val); 
    else if (key > node->key) 
        node->right = insert(node->right, key,val); 
    else
    {
 		cout<<"value updated\n";
    	node->val = val; 
        return node;
    } 

    node->height = 1 + max(height(node->left), 
                        height(node->right)); 

    int balance = getBalance(node); 

    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 

    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 

 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    
    return node; 
} 

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 

    while (current->left != NULL) 
        current = current->left; 

    return current; 
} 

 
Node* deleteNode(Node* root, int key) 
{ 

    if (root == NULL){
    	cout<<key<<" is not present in the table\n"; 
        return root; }


    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 

    else if( key > root->key ) 
        root->right = deleteNode(root->right, key);                       


    else
    { 
    	cout<<"deleted successfully\n";
        if( (root->left == NULL) || 
            (root->right == NULL) ) 
        { 
            Node *temp = root->left ? 
                        root->left : 
                        root->right; 

            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
            *root = *temp; 
            free(temp); 
        } 
        else
        { 

            Node* temp = minValueNode(root->right); 

            root->key = temp->key; 

   
            root->right = deleteNode(root->right, 
                                    temp->key); 
        } 
    } 

    if (root == NULL) 
    return root; 

    root->height = 1 + max(height(root->left), 
                        height(root->right)); 

    int balance = getBalance(root); 

    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rightRotate(root); 

    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 

    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 

    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 

    return root; 
} 

Node* search(Node*root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->key)
		return search(root->left,key);
	if(key>root->key)
		return search(root->right,key);
	if(root->key==key)
		return root;
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key<<"-"<<root->val<<"\n";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

class hashtable
{
	int b; 
    Node** table; 
public:
	hashtable(int b);
	void hinsert(int key,int val);
	void deldeteit(int key);
	void displayhash();	
	int value(int key);
	int hashFunction(int x) { 
        return (x % b); 
    } 
};

hashtable::hashtable(int b)
{
	this->b = b;
	table = new Node*[b];
	for (int i = 0; i < b; ++i)
	{
		table[i]=NULL;
	}
}
void hashtable::deldeteit(int key)
{
	int ind = hashFunction(key);
	table[ind] = deleteNode(table[ind],key);
}

void hashtable::hinsert(int key,int val)
{
	int ind = hashFunction(key);
	table[ind] = insert(table[ind],key,val);
}

void hashtable::displayhash()
{
	for (int i = 0; i < b; ++i)
	{
		preOrder(table[i]); 
	}
}

int hashtable::value(int key)
{
	int ind = hashFunction(key);
	Node* node = search(table[ind],key);
	if(node==NULL){
		cout<<"key is not present\n";
		return -99999;
	}
	return node->val; 
}

int main()
{
	int b;
	cin>>b;
	hashtable h(b);
  int a=0;
  while(a!=5)
  {
  	cin>>a;
  	if(a==1)
  	{
  		int key,val;
  		cin>>key>>val;
  		h.hinsert(key,val);
  	}
  	else if(a==2)
  	{
  		int key;
  		cin>>key;
  		h.deldeteit(key);
  	}
  	else if(a==3)
  	{
  		int key;
  		cin>>key;
  		if(h.value(key)!=-99999)
  		cout<<h.value(key)<<"\n";
  	}
  	else if(a==4)
  	{
  		h.displayhash();
  	}
  }  
  return 0; 
}
