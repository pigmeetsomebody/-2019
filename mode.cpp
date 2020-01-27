//
//  main.cpp
//  mode
//
//  Created by Apple on 2020/1/27.
//  Copyright © 2020 Apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int n,m;
struct count_bit{
    int num;
    int total;
}counts[10];
bool cmp(count_bit a,count_bit b){
    if(a.total != b.total) return a.total > b.total;
    else return a.num < b.num;
}
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> q;
    //vector<count_bit> counts;
    int div = 1;
    
    while(m--){
        for(int i=0;i<10;i++){
            counts[i].num=i;
            counts[i].total=0;
        }
        for(int i=0;i<v.size();i++){
            ++counts[(v[i]/div)%10].total;
        }
        sort(counts,counts+10,cmp);
        cout<<counts[0].num<<endl;
        div*=10;
    }
    return 0;
}
