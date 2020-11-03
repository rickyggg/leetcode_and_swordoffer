class Solution {
public:
	vector<int> printNumbers(int n) {
		if (n == 0) return {};
		vector<int> res;
		for (int i = 1, max = pow(10, n); i < max; i++)
			res.push_back(i);
		return res;
	}
};
