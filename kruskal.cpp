#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int find(vector<int>&parent,int x){
    return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);
}
void union1(vector<int>&parent,vector<int>&rank,int a ,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;

    }else{
        rank[b]++;
        parent[a]=b;
    }
}
struct edge{
    int src;
    int dest;
    int wt;
};
bool cmp(edge e1,edge e2){
    return e1.wt <e2.wt;
}
 ll kruskal(vector<edge>&input,int n,int e){
    sort(input.begin(),input.end(),cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int edgecount=0;
    int i=0;
    ll ans=0;
    while(edgecount<n-1){
        edge curr=input[i];
        int srcpar=find(parent,curr.src);
        int despar=find(parent,curr.dest);
        if(srcpar!=despar){
            union1(parent,rank,srcpar,despar);
            ans+=curr.wt;
            edgecount++;
            
        }
        i++;


    }
    return ans;
 }
int main(){
    int n,e;
    cin>>n>>e;
    vector<edge>v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskal(v,n,e);
    return 0;

}