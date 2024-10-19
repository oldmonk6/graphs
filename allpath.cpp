#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
vector<vector<int>>result;

int v;
void add(int s,int d,bool bidir=true){
    graph[s].push_back(d);
    if(bidir==true){
        graph[d].push_back(s);
    }
    
}
void dfs(int curr ,int end,vector<int>&path)
{

    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(curr);
    visited.insert(curr);
    for(auto neighbour: graph[curr])
    {
        if( !visited.count(neighbour))
        {
            dfs(neighbour,end,path);
            
        }
    }
    path.pop_back();
    visited.erase(curr);
    return ;

}
bool allpath(int src,int end)
{
    vector<int>v;
    dfs(src,end,v);
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
    // cout<<anypath(x,y);
    allpath(x,y);
    for(auto path:result){
        for(auto el:path)
        {
            cout<<el<<" ";
        }
        cout<<"\n";

    }
   

}