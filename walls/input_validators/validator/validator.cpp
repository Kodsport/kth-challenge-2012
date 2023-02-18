#include "validator.h"

void run() {
    int L = Int(1, 30); Space();
    int W = Int(1, 30); Space();
    int N = Int(1, 30); Space();
    int R = Int(1, 30); Endl();
    set<pair<int, int>> pos;
    for (int i = 0;i < N; i++) {
        int X = Int(-100, 100); Space();
        int Y = Int(-100, 100); Endl();
        pos.emplace(X, Y);
    }
    assert(pos.size() == N);
}
