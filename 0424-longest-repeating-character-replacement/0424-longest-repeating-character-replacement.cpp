class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l = 0, r = 0;
        int max_count = 0;
        int max_length = 0;
        while(r < s.size()){
            freq[s[r] - 'A']++;
            max_count = max(max_count, freq[s[r] - 'A']);
            if((r - l + 1 ) - max_count > k){
                freq[s[l] - 'A']--;
                l++;
            }
            max_length = max(max_length, (r - l + 1));
            r++;
        }
        return max_length;
    }
};