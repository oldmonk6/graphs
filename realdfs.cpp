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
bool dfs(int curr ,int end,vector<int>&ls)
{
    if(curr==end){
        
        ls.push_back(curr);
        return true;
    }
    ls.push_back(curr);
    visited.insert(curr);
    for(auto neighbour: graph[curr])
    {
        if( !visited.count(neighbour))
        {
            
            bool result=dfs(neighbour,end,ls);
            if(result)return true;
            
        }
    }
    return false;
   

}
bool anypath(int src,int end,vector<int>&ls)
{
    return dfs(src,end,ls);
}



int main()
{
    cin>>v;
    graph.resize(v,list<int>());
    vector<int>ls;
    
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
    cout<<anypath(x,y,ls)<<endl;
    for(auto ele:ls){
        cout<<ele<< ' ';
    }
   

}