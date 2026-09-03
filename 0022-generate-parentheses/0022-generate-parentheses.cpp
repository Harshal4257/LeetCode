class Solution {
public:
    vector<string> ans;
    string combin;

    void solve(int open, int close, int n) {
        if (combin.size() == 2 * n) {
            ans.push_back(combin);
            return;
        }

        if (open < n) {
            combin.push_back('(');
            solve(open + 1, close, n);
            combin.pop_back();
        }

        if (close < open) {
            combin.push_back(')');
            solve(open, close + 1, n);
            combin.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        combin.clear();
        solve(0, 0, n);
        return ans;
    }
};