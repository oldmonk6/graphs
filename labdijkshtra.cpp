#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp>>gr;
unordered_map<string,int>nodetoindex;
unordered_map<int,string>indextonode;
void add(string u,string v,int wt, bool bidir=true){
    int uid=nodetoindex[u];
    int vid=nodetoindex[v];
    gr[uid].push_back({vid,wt});
    if(bidir)gr[vid].push_back({uid,wt});

}
unordered_map<int,int>dijk(int src,int n,vector<int>&parent){
    unordered_map<int,int>mp;
    unordered_set<int>vis;
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,src});
    parent[src]=-1;
    while(!pq.empty()){
        pp curr=pq.top();
        if(vis.count(curr.second)){
        pq.pop();
        continue;
        }
        vis.insert(curr.second);
          for (auto neighbour : gr[curr.second]) {
            if (!vis.count(neighbour.first) && mp[neighbour.first] > neighbour.second + mp[curr.second]) {
                pq.push({neighbour.second + mp[curr.second], neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second + mp[curr.second];
            }
        }
    }
    return mp;
}
vector<int> getPath(int dest, vector<int>& parent) {
    vector<int> path;
    for (int i = dest; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}
    int main(){
        int v;
        cout<<"enter the vertices:"<<endl;
        cin>>v;
        int e;
        cout<<"enter the edges:"<<endl;
        cin>>e;
        gr.resize(v,list<pp>());
        cout<<"enter the cities"<<endl;
        vector<int>parent(v+1);
        for(int i=0;i<v;i++){
            string nodename;
            cin>>nodename;
            nodetoindex[nodename]=i;
            indextonode[i]=nodename;

        }
        cout<<"enter the edges"<<endl;
        while(e--){
            string u, n;
         int wt;
         cin >> u >> n>> wt;
         add(u, n, wt);
        }
          string srcNode;
          cout<<"enter the source node";
    cin >> srcNode;
    int src = nodetoindex[srcNode];

    unordered_map<int, int> sp = dijk(src, v,parent);
     cout<<"enter the dest node";

    string destNode;
    cin >> destNode;
    int dest = nodetoindex[destNode];
     cout << "Shortest distance from " << srcNode << " to " << destNode << " is: " << sp[dest] << endl;
     if (sp[dest] == INT_MAX) {
        cout << "No path from " << src << " to " << dest << endl;
    } else {
        cout << "Shortest distance: " << sp[dest] << endl;
        vector<int> path = getPath(dest, parent);
        cout << "Path: ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
    }


        
    
  
    



