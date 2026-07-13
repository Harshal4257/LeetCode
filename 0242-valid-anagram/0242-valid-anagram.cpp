class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> ana;
        for(char i:s){
            ana[i]++;
        }
        for(char i:t){
            ana[i]--;
        }
        for(auto x:ana){
            if(x.second != 0) return false;
        }
        return true;
    }
};