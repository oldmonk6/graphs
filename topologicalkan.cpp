#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<list>
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
void topobfs(){
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
       for(auto neighbour:graph[i]){
        indegree[neighbour]++;
       }
    }
    unordered_set<int>vis;
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
            vis.insert(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto neighbours:graph[node]){
            if(!vis.count(neighbours)){
            indegree[neighbours]--;
            if(indegree[neighbours]==0){
                q.push(neighbours);
                vis.insert(neighbours);
            }
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
        add(s,d,false);
    }
    topobfs();
}