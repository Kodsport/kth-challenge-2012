#include "validator.h"

void run() {
    int K = Int(1, 100); Endl();
    string s = Line();
    assert(K <= s.size() && s.size() <= 100'000);
    for (char c : s) assert(c == '0' || c == '1');
}
