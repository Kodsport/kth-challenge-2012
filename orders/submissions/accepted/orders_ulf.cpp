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
//Solution by Ulf Lundström
#include <iostream>
#include <vector>
using namespace std;

int M = 30002;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    vector<int> p(M,-1);
    p[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + c[i] < M; ++j) {
            if (p[j] >= 0) {
                if (p[j+c[i]] >= 0)
                    p[j+c[i]] = -2;
                else if (p[j+c[i]] == -1)
                    p[j+c[i]] = i;
            } else if (p[j] == -2) {
                p[j+c[i]] = -2;
            }
        }
    }

    int m, s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (p[s] == -1) {
            cout << "Impossible" << endl;
        } else if (p[s] == -2) {
            cout << "Ambiguous" << endl;
        } else {
            vector<int> v;
            while (s) {
                v.push_back(p[s]);
                s = s-c[p[s]];
            }
            for (int i = v.size()-1; i > 0; --i)
                cout << v[i]+1 << " ";
            cout << v[0]+1 << endl;
        }
    }
}
