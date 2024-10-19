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
bool dfs(int curr ,int end)
{
    if(curr==end)return true;
    visited.insert(curr);
    for(auto neighbour: graph[curr])
    {
        if( !visited.count(neighbour))
        {
            bool result=dfs(neighbour,end);
            if(result)return true;
        }
    }
    return false;

}
bool anypath(int src,int end)
{
    return dfs(src,end);
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
    int x,y;
    cin>>x>>y;
    cout<<anypath(x,y);
   

}