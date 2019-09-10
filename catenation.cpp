#include <bits/stdc++.h>	
#include<stack>
#include<iostream>
#include<string>
using namespace std;

struct node
{
string m;
node* left;
node* right;
};

bool compare(node* a, node* b)
{
return (((*a).m+(*b).m)>((*b).m+(*a).m));
}


void swap(string* a, string* b)
{
string t;
t=*a;
*a=*b;
*b=t;
}

string add_fun(string a,string b)
{
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;


	if(a.size()>=b.size())
	{
		int n1 = a.size();
		int n2 = b.size();
		for(int i=0;i< n1;i++)
		{
			s1.push(a[i]-'0');
		}
		for(int i = 0; i < n2; ++i)
		{
			s2.push(b[i]-'0');
		}
	}
	else
	{
		int n1 = b.size();
		int n2 = a.size();
		for(int i=0;i<n1;i++)
		{
			s1.push(b[i]-'0');
		}
		for(int i = 0; i <n2; ++i)
		{
			s2.push(a[i]-'0');
		}
	}


	int n1 = s1.size();
	int n2 = s2.size();


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()+s2.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();
	}

	if(c==1)
	{
		ans.push(1);
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}
	return out;

}


node* insert(node* root, string s)
{
node* current= root;
node* current_parent=root;
node* np=(node*)malloc(1*sizeof(node));
(*np).m=s;
int i=-1;
while(1)
{
if(current==NULL)
{
if(i==1)
{
(*current_parent).right=np;
return root;
}
if(i==0)
{
(*current_parent).left=np;
return root;
}
}
else if(compare(current,np))
{
current_parent=current;
current=(*current).right;
i=1;
}
else if(!compare(current,np))
{
current_parent=current;
current=(*current).left;
i=0;
}
}
}

string inorder_traversal(node* root)
{
string u="";
if((*root).left!=NULL)
u=u+inorder_traversal((*root).left);
u=u+(*root).m;
if((*root).right!=NULL)
u=u+inorder_traversal((*root).right);
return u;
}

int main()
{
node* root;
root=(node*)malloc(1*sizeof(node));
string s;
string output="Output\n";
string n;
string k;
string unit="0";
cin>>n;
string unit_2="1";
while(unit<n)
{
unit_2="1";
(*root).left=NULL;
(*root).right=NULL;
cin>>k;
cin>>s;
(*root).m=s;
while(unit_2<k)
{
cin>>s;
root=insert(root,s);
unit_2=add_fun(unit_2,"1");
}
output=output+"\n"+inorder_traversal(root);
unit=add_fun(unit,"1");
}
cout<<output;
}
