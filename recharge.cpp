#include <bits/stdc++.h>	
#include<string>
using namespace std;

struct node
{
int user;
int recharge;
struct node* left;
struct node* right;
};

node* create_node(void)
{
node* p=(node*)malloc(1*sizeof(node));
return p;
}

/*node* bpcl(node* child, node* extra)
{
(*((*child).parent)).left=extra;
(*extra).left=child;
return child;
} 

node* bpcr(node* child, node* extra)
{
(*((*child).parent)).right=extra;
(*extra).right=child;
return child;
}*/

node* updated_root(node* root, int u, int r)
{
node* current_parent;
int i;
node* current=root;
while(1)
{
if(current==NULL)
{
current=create_node();
(*current).user=u;
(*current).recharge=r;
if(i=1)
(*current_parent).right=current;
if(i=0)
(*current_parent).left=current;
break;
}
else
{
if(u>(*current).user)
{
current_parent=current;
current=(*current).right;
i=1;
}
else if(u<(*current).user)
{
current_parent=current;
current=(*current).left;
i=0;
}
else if(u==(*current).user)
{
(*current).recharge=(*current).recharge+r;
break;
}
}
}
return root;
}



/*int search_user(int u, node* root)
{
node* current=root;
while(1)
{
if(current==NULL)
{
return 0;
}
else
{
if((*current).user<u)
{
current=(*current).right;
}
else if((*current).user>u)
{
current=(*current).left;
}
else if((*current).user==u)
{
return (*current).recharge;
}
}
}
}

node* updated_recharges(node* root,int u, int re)
{
node* current_parent;
int i;
node* current=root;
int r=search_user(u, root);

if(r==0)
{
while(1)
{
if(current==NULL)
{
current=create_node();
(*current).user=u;
(*current).recharge=r;
if(i=1)
(*current_parent).right=current;
if(i=0)
(*current_parent).left=current;
break;
}
else
{
if(r>(*current).recharge)
{
current_parent=current;
current=(*current).right;
i=1;
}
else if(r<(*current).recharge)
{
current_parent=current;
current=(*current).left;
i=0;
}
else if((r==(*current).recharge)&&(u!=(*current).user))
{
current_parent=current;
current=(*current).left;
}
}
}
}




while(1)
{
if(current==NULL)
{
current=create_node();
(*current).user=u;
(*current).recharge=r;
if(i=1)
(*current_parent).right=current;
if(i=0)
(*current_parent).left=current;
break;
}
else
{
if(r>(*current).recharge)
{
current_parent=current;
current=(*current).right;
i=1;
}
else if(r<(*current).recharge)
{
current_parent=current;
current=(*current).left;
i=0;
}
else if((r==(*current).recharge)&&(u=(*current).user))
{
(*current).recharge=(*current).recharge+r;
break;
}
else if((r==(*current).recharge)&&(u!=(*current).user))
{
current_parent=current;
current=(*current).left;
}
}
}
return root;
}*/

int max_recharge(node* root,int m)
{
node* current;
current=root;
if((*current).recharge>m)
m=(*current).recharge;
if((*current).left!=NULL)
m=max_recharge((*current).left,m);
if((*current).right!=NULL)
m=max_recharge((*current).right,m);
return m;
}

int main()
{
int i;
int max=0;
string s="";
node* root=(node*)malloc(1*sizeof(node));
node* recharge_root=(node*)malloc(1*sizeof(node));
int n;
int u;
int r;
cin>>n;
cin>>i;
if(i==2)
s.append("No Data Available\n");
if(i==1)
{
cin>>u>>r;
(*root).user=u;
(*root).recharge=r;
(*recharge_root).user=u;
(*recharge_root).recharge=r;
}
for(int j=0; j<n-1; j++)
{
cin>>i;
if(i==1)
{
cin>>u;
cin>>r;
root=updated_root(root,u,r);
}
if(i==2)
{
max=max_recharge(root,max);
s.append(std::to_string(max));
}
}
cout<<s;
}
