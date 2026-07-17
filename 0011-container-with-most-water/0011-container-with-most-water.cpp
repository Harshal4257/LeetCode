class Solution {
public:
    int maxArea(vector<int>& height) {
        int marea = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int width = right - left;
            int heit  = min(height[left],height[right]);
            int area  = width * heit;
            marea = max(marea,area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else left++;
        }
        return marea;
    }
};