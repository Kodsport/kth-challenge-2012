#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef vector<int> vi;

int main(int argc, char **argv) {
	init_io(argc, argv);

    int K;
    judge_in >> K;
    string S;
    judge_in >> S;

	auto checkAns = [&](istream& is, feedback_function fail) -> int {
        long long f, l;
        is >> f;
        if (!is) fail("eof1");
        is >> l;
        if (!is) fail("eof2");

        if (l < K || l > (ll)S.size()) {
            fail("k outside bounds: %lld vs %lu", l, S.size());
        }
        if (f < 1 || f > (ll)S.size() || f + l - 1 > (ll)S.size()) {
            fail("f outside bounds: %lld vs %lu", f, S.size());
        }

        --f;
        int freq = 0;
        rep(i,(int)f,(int)f+(int)l) {
            freq += S[i] == 0;
        }

		string trailing;
		if (is >> trailing) {
			fail("Trailing output");
		}
		return freq;
	};

	int judgeAns = checkAns(judge_ans, judge_error);
	int userAns = checkAns(cin, wrong_answer);

	if (userAns < judgeAns) {
		wrong_answer("ans too low: %d vs %d", userAns, judgeAns);
	}
	if (userAns > judgeAns) {
		judge_error("ans better than opt: %d vs %d", userAns, judgeAns);
	}

	accept();
}
