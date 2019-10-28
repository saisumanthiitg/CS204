#include<bits/stdc++.h>
using namespace std;
int main()
{
int m,n;
int i,j;
int a,b;
cin >>n>>m;
int v[n];

for(i=0;i<n;i++)
{
v[i]=0;
}

int e[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		e[i][j]=0;
	}

}

for(i=0;i<m;i++)
{
cin >>a>>b;
e[a-1][b-1]=1;
e[b-1][a-1]=1;
}

for(i=0;i<n;i++)
{
if(v[i]==0)
{
v[i]=1;
queue <int> q; 
    q.push(i); 
  
    // Run while there are vertices in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (e[u][u] == 1) 
        {cout<<"no"<<"\n";return 0;}  
  
        // Find all non-colored adjacent vertices 


	for(int x=0;x<n;x++)
	{
		if(e[u][x] && v[x]==0)
		{
			v[x]=(-1)*v[u];
			q.push(x);
		}
		else if(e[u][x] && v[x]==v[u])
		{
			cout << "no"<<"\n";return 0;
		}
	}

    } 
}

}
cout<<"yes"<<"\n";

return 0;

}
