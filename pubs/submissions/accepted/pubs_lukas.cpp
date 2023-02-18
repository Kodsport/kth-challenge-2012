/* This is an example solution to the "Pub-lic Good" problem from
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
#include <queue>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef vector<int> vi;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vi> g(n);
    rep(i,0,m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i,0,n) if (g[i].empty())
    {
        printf("Impossible\n");
        return 0;
    }

    queue<int> q;
    vector<bool> seen(n, false), col(n, false);
    rep(i,0,n) if (!seen[i])
    {
        seen[i] = true;
        for (q.push(i); !q.empty(); q.pop())
        {
            int u = q.front();
            trav(j,g[u])
                if (!seen[*j])
            {
                q.push(*j);
                col[*j] = !col[u];
                seen[*j] = true;
            }
        }
    }

    rep(i,0,n)
    {
        if (col[i])
            printf("house");
        else
            printf("pub");
        if (i + 1 < n)
            printf(" ");
        else
            printf("\n");
    }
}
