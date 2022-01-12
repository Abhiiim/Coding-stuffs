#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 200005;
vector<ll> BIT(N, 0);
vector<ll> arr(N);

// BIT 1-based index array
// update function calls the index(idx) at which we have to change the value
// diff is the final_value - prev_value at that index
void update(ll idx, ll diff, ll n){
    idx++;
    while (idx <= n){
        BIT[idx] += diff;
        idx += idx & (-idx);
    }
}

// function gives the sum of all the values till k-th index
int getSum(ll k){
    k++;
    ll ans = 0;
    while (k > 0){
        ans += BIT[k];
        k -= k & (-k);
    }
    return ans;
}

// makeTree makes the BIT if initially we have an array
void makeTree(ll n){
    for (int i=0; i<n; i++){
        update(i, arr[i], n);
    }
}

int main()
{
    // ll n = 10;
    // for (ll i=0; i<n; i++){
    //     arr[i] = i+1;
    // }
    // makeTree(10);
    // for (ll i=0; i<=n; i++){
    //     cout << BIT[i] << " ";
    // }
    // cout << endl;
    return 0;
}