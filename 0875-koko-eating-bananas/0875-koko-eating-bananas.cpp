class Solution {
public:
    int findmax(vector<int>& piles){
        int maxn = INT_MIN;
        for(auto& i:piles) maxn = max(maxn, i);
        return maxn;
    }
    long long calculatetotalhrs(vector<int>& piles, int mid){
        long long totalh = 0;
        for(int i=0;i<piles.size();i++){
            totalh += ceil((double)piles[i] / (double)mid);
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmax(piles);
        while(low <= high){
            int mid = (low + high) / 2;
            long long totalh = calculatetotalhrs(piles, mid);
            if(totalh <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
