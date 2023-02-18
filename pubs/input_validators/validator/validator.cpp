#include "validator.h"

void run() {
    int N = Int(1, 10'000); Space();
    int M = Int(0, 100'000); Endl();

    set<pair<int, int>> ed;
    for (int i = 0; i < M; i++) {
        int x = Int(1, N); Space();
        int y = Int(1, N); Endl();
        assert(x != y);
        ed.emplace(min(x, y), max(x, y));
    }
    assert(ed.size() == M);
}
