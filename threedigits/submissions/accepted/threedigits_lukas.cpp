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
//Solution by Lukáš Poláček (lukasP)
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
int main()
{
    int n; scanf("%d", &n);
    ll p52 = 0, rest = 1;
    rep(i,2,n+1)
    {
        int j = i;
        while (j % 2 == 0)
        {
            j /= 2;
            p52++;
        }
        while (j % 5 == 0)
        {
            j /= 5;
            p52--;
        }
        rest = rest * j % 1000;
    }
    rep(i,0,p52)
        rest = rest * 2 % 1000;
    if (n <= 6)
        printf("%lld\n", rest);
    else
        printf("%03lld\n", rest);
}
