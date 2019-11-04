/*DISJOINT SET UNION FIND
Question
 There are n students and m relationships of the form q p,means that q and p are friends
 our task is to find no. of friends of every student.
 (if two students are not directly friends but they have a mutual friend,then they too become friends)
 */



#include <bits/stdc++.h>

using namespace std;

struct sub{
   int par;
    int sz;
};

vector <sub> rel;

int find_(int i){
    if(rel[i].par!=i)
        rel[i].par=find_(rel[i].par);
  return rel[i].par;
}

void uni(int x,int y){
    if(x==y)
       return;
    int x_root=find_(x);
    int y_root=find_(y);
    if(rel[x_root].sz < rel[y_root].sz){
        rel[x_root].par=y_root;
        rel[y_root].sz+=rel[x_root].sz;
    }
    else{
        rel[y_root].par=x_root;
        rel[x_root].sz+=rel[y_root].sz;
    }
}

int main()
{
    int i,n,m;
    cin >>n >>m;

    rel.clear();
    rel.resize(n+1);
    for(i=1;i<=n;i++){
        rel[i].par=i;
        rel[i].sz=1;
    }

    for(i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        uni(find_(p),find_(q));
    }
    for(i=1;i<=n;i++){
        cout<< rel[find_(i)].sz-1 <<" ";
    }

    return 0;
}
