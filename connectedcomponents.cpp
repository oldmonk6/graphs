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
void dfs(int node){
    visited.insert(node);
    for(auto neighbor:graph[node]){
        if(!visited.count(neighbor)){
            dfs(neighbor);
        }
    }

}
int connectedcomp(){
    int result=0;
    for(int i=0;i<v;i++){
        if(visited.count(i)==0){
            result++;
            dfs(i);
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
   cout<<connectedcomp()<<endl;

}