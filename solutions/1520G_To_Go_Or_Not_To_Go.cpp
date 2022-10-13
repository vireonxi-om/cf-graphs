// Problem: To Go Or Not To Go?
// URL: https://codeforces.com/problemset/problem/1520/G
// Rating: 2200
// Tags: brute force, dfs and similar, graphs, greedy, implementation, shortest paths
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll w, a[2100][2100], b[2100][2100];
queue<pair<int, int>> q;

ll bfs(int x, int y){
    ll result=-1;
    q.push(make_pair(x, y));
    if(a[x][y]>0) result=a[x][y];
    while(!q.empty()){
        int x1=q.front().first, y1=q.front().second;
        q.pop();
        for(int i=x1-1; i<=x1+1; i+=2){
            int j=y1;
            if(i<1 || i>n) continue;
            if(b[i][j]!=-1 || a[i][j]==-1) continue;
            b[i][j]=b[x1][y1]+w;
            q.push(make_pair(i, j));
            if(a[i][j]) result==-1 ? result=b[i][j]+a[i][j] : result=min(result, b[i][j]+a[i][j]);
        }
        for(int j=y1-1; j<=y1+1; j+=2){
            int i=x1;
            if(j<1 || j>m) continue;
            if(b[i][j]!=-1 || a[i][j]==-1) continue;
            b[i][j]=b[x1][y1]+w;
            q.push(make_pair(i, j));
            if(a[i][j]) result==-1 ? result=b[i][j]+a[i][j] : result=min(result, b[i][j]+a[i][j]);
        }
    }
    return result;
}

int main(){
    scanf("%d%d%lld", &n, &m, &w);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%lld", &a[i][j]);
            b[i][j]=-1;
        }
    }
    b[1][1]=0;
    ll st=bfs(1, 1);
    ll tot=b[n][m], ans=-1;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) b[i][j]=-1;
    b[n][m]=0;
    ll fi=bfs(n, m);
    if(tot!=-1) ans=tot;
    if(st!=-1 && fi!=-1) ans==-1? ans=st+fi : ans=min(ans, st+fi);
    printf("%lld\n", ans);
    return 0;
}


