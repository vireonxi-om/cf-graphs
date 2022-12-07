// Problem: 3-Coloring
// URL: https://codeforces.com/problemset/problem/1504/D
// Rating: 1700
// Tags: constructive algorithms, games, graphs, interactive
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110][110];
set<pair<int, int>> s1, s2;

int main(){
    scanf("%d", &n);
    for(int i=2; i<=2*n; i+=2){
        for(int j=max(1, i-n); j<=min(i-1, n); j++){
            s1.insert(make_pair(j, i-j));
        }
    }
    for(int i=3; i<2*n; i+=2){
        for(int j=max(1, i-n); j<=min(i-1, n); j++){
            s2.insert(make_pair(j, i-j));
        }
    }
    bool yes1=false, yes2=false;
    int num, c, x, y;
    while(!yes1 || !yes2){
        scanf("%d", &num);
        if(!yes1 && !yes2){
            if(num==1){
                c=2;
                x=(*s2.begin()).first; y=(*s2.begin()).second;
                s2.erase(s2.begin());
            }
            else{
                c=1;
                x=(*s1.begin()).first; y=(*s1.begin()).second;
                s1.erase(s1.begin());
            }
        }
        else if(yes1){
            x=(*s2.begin()).first; y=(*s2.begin()).second;
            s2.erase(s2.begin());
            if(num==2) c=3;
            else c=2;
        }
        else{
            x=(*s1.begin()).first; y=(*s1.begin()).second;
            s1.erase(s1.begin());
            if(num==1) c=3;
            else c=1;
        }
        printf("%d %d %d\n", c, x, y);
        fflush(stdout);
        if(s1.empty()) yes1=true;
        if(s2.empty()) yes2=true;
    }
}
