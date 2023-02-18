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
//Solution by Ulf Lundström
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
    int K;
    cin >> K;
    char buff[100005];
    cin >> buff;
    int N = strlen(buff);
    vector<int> cs(N+1);
    cs[0] = 0;
    for (int i = 0; i < N; ++i)
        cs[i+1] = cs[i]+(buff[i]=='1');

    int L=K, c=0, s=0;
    for (int l = K; l < 2*K; ++l) {
        for (int i = 0; i+l <= N; ++i) {
            if ((cs[i+l]-cs[i])*L > c*l) {
                L = l; c = cs[i+l]-cs[i]; s = i;
            }
        }
    }
    cout << s+1 << " " << L << endl;
}
