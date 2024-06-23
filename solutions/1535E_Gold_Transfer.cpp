// Problem: Gold Transfer
// URL: https://codeforces.com/problemset/problem/1535/E
// Rating: 2200
// Tags: binary search, data structures, dp, greedy, interactive, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q, t, a[310000], c[310000], p[25][310000];


int main(){
    scanf("%d%d%d", &q, &a[0], &c[0]);
    int u, w, tot;
    for(int i=1; i<=q; i++){
        scanf("%d", &t);
        if(t==1){
            scanf("%d%d%d", &p[0][i], &a[i], &c[i]);
            for(int j=1; j<=20; j++){
                p[j][i]=p[j-1][p[j-1][i]];
            }

        }
        else{
            scanf("%d%d", &u, &tot);
            w=tot;
            ll cost=0, wt;
            while(w){
                int k=20, v=u;
                while(k>=0){
                    if(a[p[k][v]]) v=p[k][v];
                    k--;
                }
                wt=min(a[v], w);
                cost+=(ll)wt*c[v];
                a[v]-=wt;
                w-=wt;
                if(v==u) break;
            }
            printf("%d %lld\n", tot-w, cost);
            fflush(stdout);
        }
    }
    return 0;
}


