#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>>graph;
int v;
void add(int s,int d,bool bidir=true){
    graph[s].push_back(d);
    if(bidir==true){
        graph[d].push_back(s);
    }

}
void display(){
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<""<<el<<" ";
        }
        cout<<"\n";
    }

}
int main()
{
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--)
    {
        int s,d;
        cin>>s;
        cin>>d;
        add(s,d);
    }
    display();

}