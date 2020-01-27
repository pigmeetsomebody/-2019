//
//  main.cpp
//  Newton_root
//
//  Created by Apple on 2020/1/27.
//  Copyright © 2020 Apple. All rights reserved.
//
//牛顿迭代法

#include <iostream>
#include <cmath>
using namespace std;
const double fraction = 10e-8;
double n,m;
int newton_sqrt(double a,double n){
    double x0=a;
    double temp=((n-1)*x0+a/(pow(x0, n-1)));
    double x1=(1/n)*temp;
    while (fabs(x1-x0)>fraction) {
        x0=x1;
        temp=((n-1)*x0+a/(pow(x0, n-1)));
        x1=(1/n)*temp;
    }
    return (int)x1;
}
int m_sqrt(double a,double n){
    return (int) pow(a,1/n);
}
int main() {
    cin>>n>>m;
   // cout<<newton_sqrt(n, m);
    cout<<m_sqrt(n, m);
    return 0;
}
