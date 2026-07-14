class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_count = 0;

        for(int i:st){
            if(!st.count(i-1)){
                int curnum = i;
                int count = 1;
                while(st.count(curnum+1)){
                    curnum++;
                    count++;
                }
                max_count = max(max_count,count);
            }
        }
        return max_count;
    }
};