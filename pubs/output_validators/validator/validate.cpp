#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
typedef vector<int> vi;

int main(int argc, char **argv) {
	init_io(argc, argv);

	int N, M;
	judge_in >> N >> M;

	vector<pair<int ,int>> eds;
	rep(i,0,M) {
		int a, b;
		judge_in >> a >> b;
		--a, --b;
	}

	auto checkAns = [&](istream& is, feedback_function fail) -> bool {
        vector<int> col(N);
        bool possible = true;
        rep(i,0,N) {
            string tok;
            is >> tok;
            if (!is) fail("eof1");
            for (char& c : tok) c = tolower(c);
            if (i == 0 && tok == "impossible") {
                possible = true;
                break;
            }
            if (tok == "pub") col[i] = 0;
            else if (tok == "house") col[i] = 1;
            else {
                fail("invalid color for house %d", i);
            }
        }

        for (auto [x, y] : eds) {
            cout << x << " " << y << endl;
            if (col[x] == col[y]) fail("edge %d %d has same color", x, y);
        }

		string trailing;
		if (is >> trailing) {
			fail("Trailing output");
		}
		return possible;
	};

	bool judgeAns = checkAns(judge_ans, judge_error);
	bool userAns = checkAns(cin, wrong_answer);

	if (!userAns && judgeAns) {
		wrong_answer("judge had solution, team did not");
	}
	if (userAns && !judgeAns) {
		judge_error("team had solution, judge did not");
	}

	accept();
}
