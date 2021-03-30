/*
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"

namespace hrs {

	int32_t hrs::partial_permutation(int32_t n) {
		std::vector<int32_t> P(n + 1);
		for (int32_t i = 0; i <= n; ++i) {
			if (i == 0)
				P[i] = 1;
			else
				P[i] = P[i - 1] * i;
		}
		return P[n];
	}

	int32_t hrs::partial_combination(int32_t n, int32_t k) {

		std::vector<std::vector<int32_t>> P(n + 1, std::vector<int32_t>());

		for (int32_t i = 0; i <= n; ++i) {
			P[i].resize(k + 1);
			for (int32_t j = 0, min = std::min(i, k); j <= min; ++j) {
				//Base Cases
				if (j > i)
					P[i][j] = 0;
				else if (j == 0)
					P[i][j] = 1;
				else if (i > 0 and j > 0)
					//calculating value using previously stored value.
					P[i][j] = P[i - 1][j] + j * P[i - 1][j - 1];
			}
		}
		return P[n][k];
	}

	int32_t partial_reflection(int32_t n, int32_t k) {

		std::vector<std::vector<int32_t>> C(n + 1, std::vector<int32_t>());

		for (int32_t i = 0; i <= n; ++i) {
			C[i].resize(k + 1);
			for (int32_t j = 0, min = std::min(i, k); j <= min; ++j) {
				//Base Cases
				if (j == 0 || j == i)
					C[i][j] = 1;

				else
					//calculating value using previously stored value.
					C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
		return C[n][k];
	}
}
