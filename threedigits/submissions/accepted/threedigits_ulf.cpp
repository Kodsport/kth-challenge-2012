/* This is an example solution to the "Three Digits" problem from
 * KTH Challenge 2012, held on March 3, 2012.
 *
 * The solution is provided as-is, is not documented, and may be
 * generally difficult to read.
 *
 * This work by KTH CSC (http://www.csc.kth.se/) is licensed under a Creative
 * Commons Attribution-Share Alike 2.5 Sweden License
 * (http://creativecommons.org/licenses/by-sa/2.5/se/deed.en).  You are free to
 * redistribute it as you like as long as this license information is not
 * removed.
 */
//Solution by Ulf Lundström
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<bool> prime(N+1,true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i < N+1; ++i) {
        if (prime[i]) {
            for (int j = i*i; j<N+1; j+=i) {
                prime[j] = false;
            }
        }
    }
    prime[5] = false;
    ll res = 1;
    const ll M = 1000;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) {
            ll p = 0;
            for (ll k = i; k <= N; k*=i)
                p += (N/k);
            if (i==2)
                for (int k = 5; k <= N; k*=5)
                    p -= (N/k);
            ll e = i%M;
            for (ll k = 1; k<=p; k*=2) {
                if (p&k)
                    res = res*e%M;
                e = e*e%M;
            }
        }
    }
    if (N < 7)
        printf("%ld\n",res);
    else
        printf("%03ld\n",res);
}
