#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Segment Tree Implementation

const ll N = 200005;
vector<ll> tree(4*N);
vector<ll> arr(N);
ll n;

// Function for contructing initial segment tree
// For constructiong segment tree we have to call constructST(0, n-1, 0);
// seg_start = 0: Start index of segment, seg_end = n-1: End Index of segment
ll constructST(ll seg_start, ll seg_end, ll i){
    if (seg_start == seg_end){
        tree[i] = arr[seg_start];
        return arr[seg_start];
    }
    ll mid = (seg_start + seg_end)/2;
    tree[i] = constructST(seg_start, mid, 2*i+1) + constructST(mid+1, seg_end, 2*i+2);
    return tree[i];
}

// Function for sum in given Range queries
ll getSumRec(ll qs, ll qe, ll ss, ll se, ll i){
    if (se < qs || ss > qe) return 0;
    if (qs <= ss && qe >= se) return tree[i];
    ll mid = (ss + se)/2;
    return getSumRec(qs, qe, ss, mid, 2*i+1) + getSumRec(qs, qe, mid+1, se, 2*i+2);
}

ll getSum(ll query_start, ll query_end){
    return  getSumRec(query_start, query_end, 0, n-1, 0);
}

// Function for updating the value at a particular index
void updateRec(ll idx, ll diff, ll ss, ll se, ll i){
    if (idx < ss || idx > se) return;
    tree[i] += diff;
    if (se > ss){
        ll mid = (ss + se)/2;
        updateRec(idx, diff, ss, mid, 2*i+1);
        updateRec(idx, diff, mid+1, se, 2*i+2);
    }
}

void update(ll idx, ll new_val){
    ll diff = new_val - arr[idx];
    arr[idx] = new_val;
    updateRec(idx, diff, 0, n-1, 0);
}

int main()
{
    // n = 6;
    // for (ll i=0; i<n; i++){
    //     arr[i] = 10*(i+1);
    // }
    // constructST(0, n-1, 0);
    // for (ll i=0; i<4*n; i++){
    //     cout << tree[i] << " ";
    // }
    // cout << endl;
    // cout << getSum(2,5) << endl;
    return 0;
}
