/* This is an example solution to the "Toilet Seat" problem from
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
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int main()
{
    string s; cin >> s;
    vector<bool> state(3, s[0] == 'D');

    vector<int> res(3, 0);
    rep(i,1,s.size())
    {
        bool cur = s[i] == 'D';
        rep(k,0,3)
        {
            if (state[k] != cur)
                res[k]++;
            state[k] = cur;

            if (k < 2)
            {
                if (state[k] != k)
                    res[k]++;
                state[k] = k;
            }
        }
    }

    rep(k,0,3)
        cout << res[k] << endl;
}
