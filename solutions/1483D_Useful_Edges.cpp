// Problem: Useful Edges
// URL: https://codeforces.com/problemset/problem/1483/D
// Rating: 2400
// Tags: dp, graphs, shortest paths
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, yes[610][610];
ll ed[610][610], d[610][610], l[610];
vector<pair<pair<int, int>, ll>> t;

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=600; i++){
        for(int j=1; j<=600; j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=1e18;
        }
    }
    int x, y; ll w;
    for(int i=1; i<=m; i++){
        scanf("%d%d%lld", &x, &y, &w);
        ed[x][y]=w; ed[y][x]=w;
        d[x][y]=min(d[x][y], w);
        d[y][x]=d[x][y];
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j]=min(d[i][j], d[i][k]+d[j][k]);
                d[j][i]=d[i][j];
            }
        }
    }
    int q;
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        scanf("%d%d%lld", &x, &y, &w);
        t.push_back(make_pair(make_pair(x, y), w));
    }
    for(int b=1; b<=n; b++){
        for(int i=1; i<=n; i++) l[i]=1e18;
        for(auto p:t){
            int x=p.first.first, y=p.first.second;
            ll now=d[b][x]-p.second;
            l[y]=min(l[y], now);
            now=d[y][b]-p.second;
            l[x]=min(l[x], now);
        }
        for(int a=1; a<=n; a++){
            if(a==b || ed[a][b]==0) continue;
            for(int k=1; k<=n; k++){
                ll now=-ed[a][b]-d[a][k];
                if(now>=l[k]){
                    yes[a][b]=1;
                    yes[b][a]=1;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(yes[i][j]) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}