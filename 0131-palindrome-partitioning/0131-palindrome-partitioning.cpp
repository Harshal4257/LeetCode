class Solution {
public:

    bool ispalin(string& part) {
        int left = 0, right = part.size() - 1;
        while(left < right) {
            if(part[left] != part[right]) return false;
            left++;
            right--;
        } 
        return true;
    }

    void allpart(string s, vector<vector<string>>& ans, vector<string>& str) {
        if(s.size() == 0) {
            ans.push_back(str);
            return;
        }
        for(int i = 0;i < s.size();i++) {
            string part = s.substr(0, i + 1);

            if(ispalin(part)) {
                str.push_back(part);
                allpart(s.substr(i + 1), ans, str);
                str.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        allpart(s, ans, str);
        return ans;
    }
};
