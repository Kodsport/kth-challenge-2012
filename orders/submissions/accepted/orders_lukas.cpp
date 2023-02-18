/* This is an example solution to the "Restaurant Orders" problem from
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
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef vector<int> vi;
int main()
{
    int n, m;
    cin >> n;
    vi c(n);
    vi prev(30001, -1);
    prev[0] = 0;
    rep(i,0,n)
    {
        cin >> c[i];
        rep(j,0,prev.size()-c[i])
            if (prev[j] != -1)
        {
            if (prev[j] == n || prev[j + c[i]] != -1)
                prev[j + c[i]] = n;
            else
                prev[j + c[i]] = i;
        }
    }

    cin >> m;
    rep(i,0,m)
    {
        int d; cin >> d;
        if (prev[d] == n)
            cout << "Ambiguous" << endl;
        else if (prev[d] == -1)
            cout << "Impossible" << endl;
        else
        {
            vi res;
            while (d > 0)
            {
                res.push_back(prev[d] + 1);
                d = d - c[prev[d]];
            }
            reverse(res.begin(), res.end());
            rep(j,0,res.size())
            {
                cout << res[j];
                if (j + 1 < res.size())
                    cout << " ";
                else
                    cout << endl;
            }
        }

    }
}
