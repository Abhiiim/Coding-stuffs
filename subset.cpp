#include<bits/stdc++.h>
using namespace std;
typedef long long ll;                 

// Finding Subsets of a set
void subsetsUtil(vector<ll>& A, vector<vector<ll>>& res,vector<ll>& subset, ll index)
{
    res.push_back(subset);
    for (ll i = index; i < A.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(A[i]);
 
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
    return;
}
 
// below function returns the subsets of vector A.
vector<vector<ll> > subsets(vector<ll>& A)
{
    vector<ll> subset;
    vector<vector<ll> > res;
 
    // keeps track of current element in vector A;
    ll index = 0;
    subsetsUtil(A, res, subset, index);
 
    return res;
}

int main()
{
    return 0;
}