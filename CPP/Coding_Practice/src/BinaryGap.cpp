#include <algorithm>
using namespace std;

inline int BinGap(int N) {
	int longest_gap = 0;
	int current_gap = 0;
	bool has_one = false;
	while (N > 0) {
		if (N % 2 == 0) {
			if (has_one) {
				current_gap++;
			}
		}
		else {
			has_one = true;
			if (current_gap != 0) {
				longest_gap = max(longest_gap, current_gap);
				current_gap = 0;
			}
		}
		N /= 2;
	}
	return longest_gap;
}