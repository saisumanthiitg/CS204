#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vecotr<long long>
int flag=0;

class Edge  
{  
    public: 
    int src, dest;  
};

class Graph  
{  
    public: 
    int V, E;  
    Edge* edge;  
    Graph(int V, int E);
};

class subset  
{  
    public: 
    int parent;  
    int rank;  
};  

int find(subset subsets[], int i)  
{   
   	if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}

void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
   
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  

    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}

Graph::Graph(int V, int E)  
{   
    this->V = V;  
    this->E = E;  
  	edge = new Edge[E];  
}  

void Iscycle(Graph g )  
{  
    int V = g.V;  
    Edge result[V]; 
    int e = 0;   
    int i = 0;  

    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
    while (i < g.E)  
    {  
        Edge next_edge = g.edge[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }   
        else{
        	flag=1;
        	break;
        }
    }    
}  

int main()
{
	int v,e;
	cin>>v>>e;
	Graph g(v,e);
	f(i,0,e)
	{
		int x,y;
		cin>>x>>y;
		g.edge[i].src = x;
		g.edge[i].dest = y;
	}
	flag=0;
	Iscycle(g);
	if(flag)
		cout<<"Graph has a cycle\n";
	else
		cout<<"Graph does not have a cycle\n";

}
