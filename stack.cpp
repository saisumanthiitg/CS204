#include<string>
#include<stack>
#include<iostream>
using namespace std;

int main()
{
stack <char> s;
char c;
int n;
string out="";
cin>>n;
cin>>c;
s.push(0);
if(c==')'||c=='}'||c==']'||c=='>')
{
out.append("NO\n");
cout<<out;
return 0;
}
for(int i=0; i<n; i++)
{


while(c!='\n')
{
if(c=='('||c=='{'||c=='['||c=='<')
{
s.push(c);
}

else
{
if(c==')')
{
if(s.top()=='(')
{
s.pop();

}
else
{
s.push(c);

}
}

if(c=='}')
{
if(s.top()=='{')
{
s.pop();

}
else
{
s.push(c);

}
}

if(c==']')
{
if(s.top()=='[')
{
s.pop();

}
else
{
s.push(c);

}
}


if(c=='>')
{
if(s.top()=='<')
{
s.pop();

}
else
{
s.push(c);

}
}

if(c=='|')
{
if(s.size()==0)
s.push(c);
else
{
if(s.top()=='|')
{
s.pop();

}
else
{
s.push(c);

}
}
}
}

c=getchar();


}

if(c=='\n')
{
if(s.size()==1)
{
out.append("YES\n");
}
else
{
out.append("NO\n");
}

while(s.size()!=1)
{
s.pop();
}

}
if(i!=n-1)
c=getchar();
}
cout<<s.top();
cout<<out;
return 0;
}


