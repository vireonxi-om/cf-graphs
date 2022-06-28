// Problem: Peaceful Rooks
// URL: https://codeforces.com/problemset/problem/1465/C
// Rating: 1700
// Tags: dfs and similar, dsu, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, fa[110000];

int findroot(int x){
    return x==fa[x] ? x : fa[x]=findroot(fa[x]);
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) fa[i]=i;
    int result=m;
    for(int i=1; i<=m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(x==y) result--;
        else {
            int rx=findroot(x), ry=findroot(y);
            if(rx==ry) result++;
            else{
                fa[rx]=ry;
            }
        }
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}