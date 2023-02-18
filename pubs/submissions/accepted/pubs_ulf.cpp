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
//Solution by Ulf Lundström
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vi> E(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    vector<bool> pub(n,false);
    vector<bool> done(n,false);
    bool imp = false;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (E[i].empty())
            imp = true;
        if (!done[i]) {
            done[i];
            q.push(i);
        }
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int j = 0; j < E[a].size(); ++j) {
                if (!done[E[a][j]]) {
                    pub[E[a][j]] = !pub[a];
                    done[E[a][j]] = true;
                    q.push(E[a][j]);
                }
            }
        }
    }
    if (imp)
        cout << "Impossible";
    else
        for (int i = 0; i < n; ++i)
            cout << (pub[i] ? "pub " : "house ");
    cout << endl;
}

