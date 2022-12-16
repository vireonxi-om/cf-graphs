// Problem: Need for Pink Slips
// URL: https://codeforces.com/problemset/problem/1543/C
// Rating: 1900
// Tags: bitmasks, brute force, dfs and similar, implementation, math, probabilities
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double c, m, p, v, ans;
const ll M=1000000007;

void work(double x, double y, double z, double now, int len){
    if(z>0){
        ans+=now*z*len;
    }
    if(x==0 && y==0) return;
    if(x>0){
        if(x-v>1e-8){
            if(y>0) work(x-v, y+v/2, z+v/2, now*x, len+1);
            else work(x-v, y, z+v, now*x, len+1);
        }
        else{
            if(y>0) work(0, y+x/2, z+x/2, now*x, len+1);
            else work(0, y, z+x, now*x, len+1);
        }
    }
    if(y>0){
        if(y-v>1e-8){
            if(x>0) work(x+v/2, y-v, z+v/2, now*y, len+1);
            else work(x, y-v, z+v, now*y, len+1);
        }
        else{
            if(x>0) work(x+y/2, 0, z+y/2, now*y, len+1);
            else work(x, 0, z+y, now*y, len+1);
        }
    }
}

void solve(){
    ans=0;
    scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
    work(c, m, p, 1, 1);
    printf("%.12f\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
