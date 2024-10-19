#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;

int v;
void add(int s,int d,bool bidir=true){
    graph[s].push_back(d);
    if(bidir==true){
        graph[d].push_back(s);
    }

}
bool dfs(int src ,int parent)
{
    visited.insert(src);
    for(auto neighbour:graph[src]){
        if(visited.count(neighbour) && neighbour!=parent)return true;
        if(!visited.count(neighbour)){
            bool res=dfs(neighbour,src);
            if(res==true)return true;
        }
    }

}
bool hascycle()
{
    bool result=false;
    for(int i=0;i<v;i++){
        if(!visited.count(i)){
            result=dfs(i,-1);
            if(result==true)return true;

        }
    }
   
}



int main()
{
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--)
    {
        int s,d;
        cin>>s;
        cin>>d;
        add(s,d);
    }
    bool b=hascycle();
    cout<<b<<" ";
    
   

}