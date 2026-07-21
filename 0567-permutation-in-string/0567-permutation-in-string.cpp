class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;
        vector<int> s1count(26,0), s2count(26,0);
        for(int i = 0;i < n1;i++){
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }
        if(s1count == s2count) return true;
        for(int right = n1;right < n2;right++){
            s2count[s2[right] - 'a']++;
            s2count[s2[right - n1] - 'a']--;

            if(s1count == s2count) return true;
        }
    return false;
    }
};
