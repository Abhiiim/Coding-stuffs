#include<bits/stdc++.h>
using namespace std;
typedef long long ll;                 

const ll N = 200005;
vector<bool> prime(N, true);  

// Sieve of Erastosthenes
void sieve(){ 
    ll p = 2;
    prime[0] = prime[1] = false;
    while(p*p <= N){
        if (prime[p] == 1){
            for(ll i=p * p; i <= N ; i += p){
                prime[i] = 0;
            }
        }
        p += 1;
    }
}

int main()
{
    return 0;
}