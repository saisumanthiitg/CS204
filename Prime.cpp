#include<string>
#include<stack>
#include<iostream>
using namespace std;

string subtract_fun(string a,string b)
{

	if(a.length()<b.length()) {return "Error : The output is not a Natural Number.";}	
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;


	int n1 = a.size();
	int n2 = b.size();


	for(int i=0;i< n1;i++)
	{
		if(s1.size()!=0 || a[i]!='0') s1.push(a[i]-'0');
	}
	for(int i = 0; i < n2; ++i)
	{
    if(s2.size()!=0 || b[i]!='0') s2.push(b[i]-'0');
	}


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()-s2.top();
		if(c==1)
		{
			k--;
			c=0;
		}
		if(k<0)
    {
      c=1;
      k+=10;
    }
		ans.push(k);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k--;
			c=0;
		}
    if(k<0)
    {
      c=1;
      k+=10;
    }

		ans.push(k);
		s1.pop();
	}
  while((ans.top()==0)&&(ans.size()!=1)){ans.pop();}


	if(c==1)
	{
    return "Error : The output is not a Natural Number.";
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}
  
  if (out=="") return "0";
  else {return out;}

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

string multiply_func(string a,string b)
{
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;

	int n1=a.size();
	int n2=b.size();
	string x3="0";	
	for(int i=(n2-1);i>=0;i--)
	{
		int bpart=b[i]-'0';
		stack<int> x1;
		stack<int> x2;
		int carry;
		string result;
		for(int u=(n1-1);u>=0;u--)
		{			
			int apart=a[u]-'0';						
			int rem;			
			if(u==(n1-1))
			{
			rem=(apart*bpart)%10;			
			x1.push(rem);
			carry=(apart*bpart)/10;
			}			
			else
			{
			rem=((apart*bpart)+carry)%10;			
			x1.push(rem);			
			carry=((apart*bpart)+carry)/10;}		
		}
		if(carry!=0)
		{x1.push(carry);}		
		while(x1.size()!=0)
		{
			x2.push(x1.top());
			x1.pop();
		}
		for(int t=(n2-1-i);t>0;t--)
		{
			x2.push(0);
		}
		
		while(x2.size()!=0)
		{
			x1.push(x2.top());
			x2.pop();
		}
				
		while(x1.size()!=0)
		{
			string s(1,'0'+x1.top());
			result.append(s);
			x1.pop();
		}
		
		x3=add_fun(x3,result);
		
	}
return x3;
}

int main()
{
string p;
string repeat;
int T;
cin>>T;
string Output="";
for(int z=0;z<T;z++)	
{	
cin>>p;
repeat="2";
int f=1;
string c;
int j=1;
while(subtract_fun(p,multiply_func(repeat,repeat))!="Error : The output is not a Natural Number.")
{
int i=0;
c=subtract_fun(p,repeat);
string g;
while(c!="Error : The output is not a Natural Number.")
{
g=c;
i=1;
if(g=="0"){f=2;break;}
c=subtract_fun(c,repeat);
}

if(g=="0"){f=2;break;}
repeat=add_fun(repeat,"1");
}
if(f==1){Output.append("Prime");Output.append("\n");}
else{Output.append("Not Prime");Output.append("\n");}
}
cout<<Output;
}

