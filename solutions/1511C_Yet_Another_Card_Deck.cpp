// Problem: Yet Another Card Deck
// URL: https://codeforces.com/problemset/problem/1511/C
// Rating: 1100
// Tags: brute force, data structures, implementation, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, t[3100000];
set<pair<int, int>> s;

void upd(int a, int b, int pos, int val, int p){
    if(a==b){ t[pos]=val; return;}
    int mid=(a+b)/2;
    if(p<=mid){
        upd(a, mid, pos*2, val, p);
        t[pos]=t[pos*2]+t[pos*2+1];
    }
    else{
        upd(mid+1, b, pos*2+1, val, p);
        t[pos]=t[pos*2]+t[pos*2+1];
    }
}

int find(int l, int r, int a, int b, int pos){
    if (l==a && r==b) return t[pos];
    int mid=(a+b)/2;
    if(l>mid) return find(l, r, mid+1, b, pos*2+1);
    else if(r<=mid) return find(l, r, a, mid, pos*2);
    else return find(l, mid, a, mid, pos*2)+find(mid+1, r, mid+1, b, pos*2+1);
}

int main(){
    scanf("%d%d", &n, &q);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        upd(1, n+q, 1, 1, q+i);
        s.insert(make_pair(num, q+i));
    }
    for(int i=q; i>=1; i--){
        scanf("%d", &num);
        auto it=s.lower_bound(make_pair(num, 0));
        int pos=(*it).second;
        int ans=find(1, pos, 1, n+q, 1);
        printf("%d ", ans);
        s.erase(it);
        s.insert(make_pair(num, i));
        upd(1, n+q, 1, 0, pos);
        upd(1, n+q, 1, 1, i);
    }
    printf("\n");
}