class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c:t) mp[c]++;

        int n = s.size(), m = t.size();
        int minlength = INT_MAX, startInd = -1;
        int l = 0, r = 0;
        int count = 0;

        while(r < n){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == m){
                if((r - l + 1) < minlength){
                    minlength = r - l + 1;
                    startInd = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return (startInd == -1 ? "" : s.substr(startInd, minlength));
    }
};