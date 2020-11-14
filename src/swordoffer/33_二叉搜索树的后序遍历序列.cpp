class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> s;// 单调栈,其中的元素单调递增
        // 表示上一个根节点的元素，这里可以把postorder的最后一个元素root看成无穷大节点的左孩子l
        int pre_elem = INT_MAX;
        //逆向遍历（根->右->左）
        for(int i = postorder.size() - 1; i >= 0; --i) {
            // 左子树元素必须要小于单调栈中的根和右子树元素，否则就不是二叉搜索树
            if (postorder[i] > pre_elem) return false;
            while (!s.empty() && postorder[i] < s.top()) {
                // 数组元素小于单调栈的元素了，发生递减，说明左子树出现
                // 需要找到这个左子树的父节点，递增栈中第一个比其大的元素就是他的父节点
                // 一边寻找一边弹出比它大（比它的父节点也大）的右子树
                pre_elem = s.top();
                s.pop();
            }
            // 如果找到了符合要求的父节点，将父节点也弹出，自己入栈，继续构造单调栈
            s.push(postorder[i]);
        }
        return true;
    }
    bool verifyPostorder1(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }
    bool verify(vector<int> &postorder, int begin, int end){
        if (begin >= end) return true;
        int root = postorder[end];
        int l = begin;
        while (l < end && postorder[l] < root)
            ++l;
        int r = l;
        while (r < end && postorder[r] > root)
            ++r;
        if (r != end) return false;
        return verify(postorder, begin, l - 1) && verify(postorder, l, end - 1);
    }
};
