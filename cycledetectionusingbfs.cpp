#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
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
bool bfs(int src )
{
    queue<int>q;
    vector<int>par(v,-1);
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(visited.count(neighbour) && par[curr]!=neighbour)return true;
            if(!visited.count(neighbour)){
                visited.insert(neighbour);
                par[neighbour]=curr;
                q.push(neighbour);
            }
        }
    }

}
bool hascycle()
{
    bool result=false;
    for(int i=0;i<v;i++){
        if(!visited.count(i)){
            result=bfs(i);
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
    cout<<b;
   

}