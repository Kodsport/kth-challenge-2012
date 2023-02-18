/* This is an example solution to the "Spam" problem from
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
//Time complexity O(20n), using binary search
#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <cstring>
using namespace std;

vector<int> a, b;
int n, k, resz, resd;
double f(int i, double m)
{
    return b[i] - m * i;
}
bool check(double m)
{
    double mi = 1e10;
    for (int i = k; i <= n; i++)
    {
        if (f(i-k, m) < mi)
        {
            mi = f(i-k, m);
            resz = i-k;
        }
        if (f(i, m) >= mi)
        {
            resd = i-resz;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &k);
    char c[100010];
    scanf("%s", c);
    n = strlen(c);

    a = vector<int>(n);
    b = vector<int>(n + 1, 0);
    for (int i = 0; i < n; i++)
        a[i] = c[i] - '0';
    partial_sum(a.begin(), a.end(), b.begin() + 1);

    double z = 0, k = 1, m;
    for (int i = 0; i < 20; i++)
    {
        m = (z + k) / 2;
        if (!check(m))
            k = m;
        else
            z = m;
    }
    check(z);
    cout << resz + 1 << " " << resd << endl;
}
