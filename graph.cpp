//
//  main.cpp
//  graph
//
//  Created by Apple on 2020/1/27.
//  Copyright © 2020 Apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct in_edge{
    int from;
    int weight;
};
struct out_edge{
    int to;
    int weight;
};
struct node{
    vector<in_edge> in_degree;
    vector<out_edge> out_degree;
    int in_edges;
    int out_edges;
    int cost;
    int ftime;
    int gtime;
}nodes[100002];
int n,m;
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nodes[i].cost;
    }
    for(int i=0;i<m;i++){
        int from,to;
        cin>> from >> to;
        in_edge ie={from,nodes[from].cost};
        out_edge oe = {to,nodes[from].cost};
        nodes[from].out_degree.push_back(oe);
        nodes[to].in_degree.push_back(ie);
        ++nodes[to].in_edges;
        ++nodes[from].out_edges;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(nodes[i].out_degree.size()<1){
            int from = i,to = n+1;
            in_edge ie={from,nodes[from].cost};
            out_edge oe = {to,nodes[from].cost};
            nodes[from].out_degree.push_back(oe);
            nodes[to].in_degree.push_back(ie);
            ++nodes[to].in_edges;
            ++nodes[from].out_edges;
        }
        if(nodes[i].in_edges<1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int s = q.front(); q.pop();
        vector<out_edge> od = nodes[s].out_degree;
        for(int i=0;i<od.size();i++){
            int t = od[i].to;
            if(--nodes[t].in_edges==0) q.push(t);
            if(nodes[s].ftime+od[i].weight>nodes[t].ftime) nodes[t].ftime = nodes[s].ftime+od[i].weight;
        }
    }
//    for(int i=1;i<=n+1;i++){
//        cout<<i<<": "<<nodes[i].ftime<<endl;
//    }
    nodes[n+1].gtime = nodes[n+1].ftime;
    int max_time = nodes[n+1].ftime;
    for(int i=n+1;i>0;i--){
        nodes[i].gtime = max_time;
    }
    while(!q.empty()) q.pop();
    q.push(n+1);
    while(!q.empty()){
        int t = q.front(); q.pop();
        vector<in_edge> id = nodes[t].in_degree;
        for(int i=0;i<id.size();i++){
            int s = id[i].from , w = id[i].weight;
            if(--nodes[s].out_edges == 0) q.push(s);
            if(nodes[t].gtime-w<nodes[s].gtime) nodes[s].gtime = nodes[t].gtime-w;
        }
    }
    long long res=1;
    for(int i=1;i<=n+1;i++){
        //cout<<i<<": "<<nodes[i].gtime<<endl;
        res=((nodes[i].gtime-nodes[i].ftime+1)*res)%1000000007;
    }
    cout<<res<<endl;
    return 0;
}
