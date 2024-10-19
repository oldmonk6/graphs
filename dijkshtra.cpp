//number the graph nodes in the input starting from 1

#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp>>gr;
void addedge(int u,int v,int wt,bool bidir=true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}
unordered_map<int,int>dijkshtra(int src,int n ){//O(vlogv +elogv)
    vector<int>via(n+1);
    unordered_map<int,int>mp;
    unordered_set<int>vis;
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;

    }
    pq.push({0,src});
    mp[src]=0;
    
    while( !pq.empty()){
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
       
        pq.pop();
        for(auto neighbour:gr[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first]>neighbour.second+mp[curr.second]){
                pq.push({neighbour.second+mp[curr.second],neighbour.first});
                via[neighbour.first]=curr.second;
                mp[neighbour.first]=neighbour.second+mp[curr.second];


                
            }
        }



    }
    return mp;


}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addedge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int>sp=dijkshtra(src,n);
    int dest;
    cin>>dest;
    cout<<sp[dest];
    return 0;
}