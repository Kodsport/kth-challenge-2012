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
//Solution by Ulf Lundström
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

const int inf = 1000000;
vector<int> A;

int rec(int mask, int depth) {
    if (depth > 4)
        return inf;
    if (mask == 15)
        return depth;
    int res = inf;
    for (int i = 0; i < A.size(); ++i)
        res = min(res, rec(mask|A[i],depth+1));
    return res;
}

int main() {
    int L,W,N,R,x,y;
    cin >> L >> W >> N >> R;
    A = vector<int>(N,0);
    int x0[4] = {-L, L, 0, 0};
    int y0[4] = {0, 0, -W, W};
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        for (int j = 0; j < 4; ++j)
            A[i] += (1<<j)*((2*x-x0[j])*(2*x-x0[j])+(2*y-y0[j])*(2*y-y0[j]) <= 2*R*2*R);
    }
    int res = rec(0,0);
    if (res == inf)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
}
