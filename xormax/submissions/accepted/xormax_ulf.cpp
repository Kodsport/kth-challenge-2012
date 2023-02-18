/* This is an example solution to the "Xor Maximization" problem from
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
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll res = 0;
    for (int b = 62; b >= 0; --b) {
        sort(a.begin(),a.end());
        if (a[a.size()-1] >= 1ll<<b) {
            if (!(res & 1ll<<b))
                res ^= a[a.size()-1];
            for (int i = a.size()-2; i>=0 && a[i] >= 1ll<<b; --i)
                a[i] ^= a[a.size()-1];
            a.pop_back();
            if (a.empty())
                break;
        }
    }
    cout << res << endl;
}


