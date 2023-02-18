#include "validator.h"

void run() {
    string S = Line();
    assert(2 <= S.size() && S.size() <= 1000);
    for (char c : S) assert(c == 'U' || c == 'D');
}
