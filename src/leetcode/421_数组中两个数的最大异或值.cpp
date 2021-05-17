struct Tree {
    Tree *next[2];
    bool isEnd;
    Tree () {
        for (int i = 0; i < 2; i++) {
            next[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
public:
    Tree root;

    void insert(int x) {
        Tree *cur = &root;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (cur->next[u] == nullptr)
                cur->next[u] = new Tree();
            cur = cur->next[u];
        }
    }

    int search(int x) {
        Tree *cur = &root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (cur->next[!u]) {
                cur = cur->next[!u];
                res = res * 2 + !u;
            } else {
                cur = cur->next[u];
                res = res * 2 + u;
            }
        }
        res ^= x;
        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            insert(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            res = max(res, search(nums[i]));
        }
        return res;
    }
};

