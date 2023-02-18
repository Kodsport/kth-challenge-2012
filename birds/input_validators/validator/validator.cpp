#include "validator.h"

void run() {
    int L = Int(1, 1'000'000'000); Space();
    int D = Int(1, 1'000'000'000); Space();
    int N = Int(0, 20'000); Endl();
    vector<int> B;
    for (int i = 0; i < N; i++) {
        int b = Int(6, L - 6); Endl();
        B.push_back(b);
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N - 1; i++) {
        assert(B[i] + D <= B[i + 1]);
    }
}
