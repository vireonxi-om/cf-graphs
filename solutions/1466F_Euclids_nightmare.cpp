// Problem: Euclid's nightmare
// URL: https://codeforces.com/problemset/problem/1466/F
// Rating: 2100
// Tags: bitmasks, dfs and similar, dsu, graphs, greedy, math, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, cnt, fa[510000];
vector<int> ans;

int find(int i){
    if(fa[i]!=i) fa[i]=find(fa[i]);
    return fa[i];
}

int pow(int a, int b){
    int result=1;
    while(b--){
        result*=a;
        result%=1000000007;
    }
    return result;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m+1; i++) fa[i]=i;
    int num, u, v;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        if(num==1){
            scanf("%d", &u);
            int fau=find(u), fav=find(m+1);
            if(fau!=fav){
                ans.push_back(i);
                fa[fau]=fav;
            }
        }
        else{
            scanf("%d%d", &u, &v);
            int fau=find(u), fav=find(v);
            if(fau==fav) continue;
            else{
                fa[fav]=fau;
                ans.push_back(i);
            }
        }
    }
    int t=ans.size();
    cnt=pow(2, t);
    printf("%d %d\n", cnt, t);
    for(auto x:ans) printf("%d ", x);
    printf("\n");
}