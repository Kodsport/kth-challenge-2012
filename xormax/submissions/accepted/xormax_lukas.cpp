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
//Solution by Lukáš Poláček (lukasP)
#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef vector<int> vi;
int main()
{
    int n;
    scanf("%d", &n);
    int l = 60;
    bitset<100098> w[l];
    rep(i,0,n)
    {
        ll a;
        scanf("%lld", &a);
        rep(j,0,l)
            w[l - j - 1][i] = (a & (1LL << j));
    }
    rep(p,0,l) w[p][n + p] = 1;

    int v = n + l;
    vi val(l);
    rep(p,0,l)
    {
        int u = -1;
        rep(i,0,v) if (w[p][i])
        {
            u = i;
            break;
        }

        if (u < n)
            val[p] = 1;
        else
            rep(i,n,n+p)
                val[p] ^= w[p][i];
        w[p][n + p] = val[p];
        rep(j,p+1,l)
            if (w[j][u])
                w[j] = w[j] ^ w[p];
    }

    ll res = 0;
    rep(p,0,l)
        res = 2 * res + val[p];
    cout << res << endl;
}
