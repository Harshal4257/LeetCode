class Solution {
public:
    void solve(string digits, vector<string>& ans, string output, string mapping[], int idx) {
        if(idx >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int no = digits[idx] - '0';
        string value = mapping[no];

        for(int i = 0;i < value.length();i++) {
            output.push_back(value[i]);
            solve(digits, ans, output, mapping, idx + 1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, ans, output, mapping, 0);
        return ans;
    }
};
