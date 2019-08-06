#include <bits/stdc++.h>	
#include<string>
using namespace std;

class point
{
public:
int x,y;
point *tail;
};

void Addfirst(int x, int y, point **p)
{
point *ne;
ne=(point*)malloc(1*sizeof(point));
(*ne).x=x;
(*ne).y=y;
(*ne).tail=*p;
*p=ne;
//cout<<(**p).x<<","<<(**p).y<<" Hi "<<(**p).tail<<"\n";
}

int DelFirst(point **p)
{
if(*p==NULL)
{
return 0;
}
else
{
*p=(**p).tail;
return 1;
}
}

int Del(int x, int y, point **p)
{
point *prevo;
prevo=*p;
point *prev;
while(((*prevo).x!=x)&&((*prevo).y!=y))
{
prev=prevo;
if((*prevo).tail!=NULL)
{prevo=(*prevo).tail;}
else
{return -1;}
}
if(prevo==*p)
{
int i=DelFirst(p);
return i-1;
}
(*prev).tail=(*prevo).tail;
return 0;
}

string search(float d, point **p)
{
point *u;
u=*p;
string s="";
while(u!=NULL)
{
if((((*u).x)*((*u).x)+((*u).y)*((*u).y))<=(d*d))
{
s=s+"("+std::to_string((*u).x)+","+std::to_string((*u).y)+")";
}
u=(*u).tail;
}
return s;
}

string find(int x, int y, point **p)
{
point *u;
u=*p;
string s="";
if(u==NULL)
{
s=s+"Empty List";
}
while((*u).tail!=NULL)
{
if(((*u).x==x)&&((*u).y==y))
{
s=s+"TRUE";
break;
}
u=(*u).tail;
}
if(((*u).tail==NULL)&&(((*u).x==x)&&((*u).y==y)))
{
s=s+"TRUE";
}
else
s=s+"FALSE";
return s;
}

string length(point **p)
{
int i=0;
point *u;
u=*p;
string s="";
while(u!=NULL)
{
u=(*u).tail;
i++;
}
s=s+std::to_string(i);
return s;
}

int main()
{
int n;
cin>>n;
int q;
point *head;
head=NULL;
int x,y;
float d;
point *u;
string output="";
for(int i=0; i<n; i++)
{
cin>>q;
switch(q)
{
case 1:
 cin>>x;
 cin>>y;
 Addfirst(x,y,&(head));
 break;
case 2:
 DelFirst(&(head));
 break;
case 3:
 cin>>x>>y;
 Del(x,y,&(head));
 break;
case 4:
 cin>>d;
 output=output+search(d,&(head))+"\n";
 break;
case 5:
 cin>>x>>y;
 output=output+find(x,y,&(head))+"\n";
 break;
case 6:
 output=output+length(&(head))+"\n";
 break;
default:
 cout<<"Invalid Input";
}
u=head;
//cout<<(*head).x<<","<<(*head).y<<" Hi "<<(*head).tail;
/*while(u!=NULL)
{
cout<<"("<<(*u).x<<","<<(*u).y<<")"<<"\n";
u=((*u).tail);
}*/
}
cout<<output;
return 0;
}











