// Problem: Two Houses
// URL: https://codeforces.com/problemset/problem/1498/E
// Rating: 2200
// Tags: brute force, graphs, greedy, interactive, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[510];
set<pair<int, pair<int, int>>> s;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            s.insert(make_pair(-abs(a[i]-a[j]), make_pair(i, j)));
        }
    }
    char b[10];
    bool can=false;
    for(auto x: s){
        int i=x.second.first, j=x.second.second;
        if(a[i]>=a[j]) printf("? %d %d\n", i, j);
        else printf("? %d %d\n", j, i);
        fflush(stdout);
        scanf("%s", &b);
        if(b[0]=='Y'){
            can=true;
            printf("! %d %d\n", i, j);
            fflush(stdout);
            break;
        }
    }
    if(!can) printf("! %d %d\n", 0, 0);
    return 0;
}


