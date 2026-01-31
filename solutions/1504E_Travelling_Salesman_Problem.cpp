// Problem: Travelling Salesman Problem
// URL: https://codeforces.com/problemset/problem/1504/E
// Rating: 2200
// Tags: binary search, data structures, dp, graphs, greedy, shortest paths, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
multiset<pair<int, int>> s;

int main(){
    scanf("%d", &n);
    int a, c;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a, &c);
        s.insert(make_pair(a, c));
    }
    int now=(*s.begin()).first;
    ll ans=0;
    for(auto x: s){
        ans+=x.second;
        if(now<x.first) ans+=x.first-now;
        now=max(now, x.first+x.second);
    }
    printf("%lld\n", ans);
    return 0;
}