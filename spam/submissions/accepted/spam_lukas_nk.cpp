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
//Time complexity O(n * k)

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
int main()
{
    int n, k;
    scanf("%d", &k);
    char c[100010];
    scanf("%s", c);
    n = strlen(c);

    vector<bool> a(n);
    for (int i = 0; i < n; i++)
        a[i] = c[i] - '0';

    int resz = 1, resd = k;
    ll bestu = 0, bestd = 1;
    for (int i = 0; i < n - k + 1; i++)
        for (int j = i, s = 0; j < i + 2 * k - 1 && j < n; j++)
        {
            s += a[j];
            if (j - i >= k - 1 && s * bestd > bestu * (j - i + 1))
            {
                bestu = s;
                bestd = j - i + 1;
                resz = i;
                resd = j - i + 1;
            }
        }
    printf("%d %d\n", resz + 1, resd);
}
