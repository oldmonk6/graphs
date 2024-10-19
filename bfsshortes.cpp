#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
#include<climits>
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
void bfs(int curr ,vector<int>&dist)
{
    queue<int>q;
    
    visited.clear();
    visited.insert(curr);
    
    q.push(curr);
    while(!q.empty())
    {
        int start=q.front();
        q.pop();
        dist.push_back(start);
        
        for(auto neighbour:graph[start])
        {
            if(!visited.count(neighbour))
            {
                q.push(neighbour);
                visited.insert(neighbour);
                
                
            }
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
    int x;
    cin>>x;
    // cout<<anypath(x,y);
    vector<int>dist;
    bfs(x,dist);
    for(auto ele:dist){
        cout<<ele<<" ";
    }

}