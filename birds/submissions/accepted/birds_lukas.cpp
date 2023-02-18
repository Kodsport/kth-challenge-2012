/* This is an example solution to the "Birds on Wire" problem from
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
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef vector<int> vi;
int main()
{
    int l, d, n;
    scanf("%d %d %d", &l, &d, &n);
    vi a(n);
    rep(i,0,n) scanf("%d", &a[i]);
    a.push_back(-d + 6);
    a.push_back(l + d - 6);

    sort(a.begin(), a.end());
    int res = 0;
    rep(i,0,n+1)
        res += (a[i + 1] - a[i] - d) / d;
    printf("%d\n", res);
}
