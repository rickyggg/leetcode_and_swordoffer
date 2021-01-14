class ds {
public:
    vector<int> f;
    ds(int n) {
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = -1;
    }
    int find(int a) {
        if (f[a] < 0)
            return a;
        else 
            return f[a] = find(f[a]);
    }
    void _union(int a, int b) {
        int i = find(a);
        int j = find(b);
        if (f[j] <= f[i]) {
            f[j] += f[i];
            f[i] = j;
        } else {
            f[i] += f[j];
            f[j] = i;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        ds s(n + 1);
        for (auto &v : edges) {
            if (s.find(v[0]) == s.find(v[1]))
                return {v[0], v[1]};
            s._union(v[0], v[1]);
        }
        return {-1, -1};
    }
};
