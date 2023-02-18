/* This is an example solution to the "Lifting Walls" problem from
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
#include <cmath>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int main()
{
    int l, w, n, r; cin >> l >> w >> n >> r;

    int dx[] = {0, 1,  0, -1};
    int dy[] = {1, 0, -1,  0};
    vector<bitset<4> > a(n);
    int res = 4;
    bitset<4> possible;
    rep(i,0,n)
    {
        int x, y; cin >> x >> y;
        rep(k,0,4)
        {
            double s = dx[k] * l / 2., t = dy[k] * w / 2.;
            if (hypot(s - x, t - y) <= r + 1e-9)
                a[i][k] = true;
        }
        if (a[i].count() == 4)
            res = 1;
        possible |= a[i];
    }

    if (possible.count() < 4)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    rep(i,0,n) rep(j,0,i)
    {
        if ((a[i] | a[j]).count() == 4)
            res = min(res, 2);
        rep(k,0,j)
            if ((a[i] | a[j] | a[k]).count() == 4)
                res = min(res, 3);
    }
    cout << res << endl;
}
