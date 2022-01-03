#include<bits/stdc++.h>
using namespace std;
typedef long long ll;                 

// KRUSKAL'A ALGORITHM
// DISJOINT SET UNION (UNION-FIND STRUCTURE)

// Initializing size and link array
const ll N = 200005;
vector<ll> link(N), len(N);
void initialize(){
    for (ll i=0;i<N;i++){
        link[i] = i;
        len[i] = 1;
    }
}

// finding the root for a given element 
ll root(ll x){
    while (x != link[x]){
        x = link[x];
    }
    return x;
}

// Taking union of two component that are not connected
void unite(ll a, ll b){
    a = root(a), b = root(b);
    if (a == b)
        return;
    if (len[a] < len[b])
        swap(a, b);
    len[a] += b;
    link[b] = a; 
}

// Defining a function kruskal for finding the weight of minimum spanning tree
// Using Kruskal's Algorithm
ll kruskal(vector<tuple<ll,ll,ll>> adj){
    sort(adj.begin(),adj.end(),[](auto &A, auto &B){
        return get<2>(A) < get<2>(B);
    });
    ll res = 0;
    for (ll i=0;i<adj.size();i++){
        ll a,b,w;
        tie(a,b,w) = adj[i];
        if (root(a) != root(b)){
            unite(a,b);
            res += w;
        }
    }
    return res;
}

int main(){
    
    return 0;
}