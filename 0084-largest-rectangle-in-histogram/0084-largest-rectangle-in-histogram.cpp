class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // stores indices, heights are increasing bottom to top
        int maxArea = 0;
        
        for(int i = 0; i <= n; i++){
            // treat "virtual bar of height 0" at the end to flush the stack
            int curHeight = (i == n) ? 0 : heights[i];
            
            while(!st.empty() && heights[st.top()] >= curHeight){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};