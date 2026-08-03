class Solution {
public:
    int findmax(vector<int>& piles){
        int maxn = INT_MIN;
        for(auto& i : piles) maxn = max(maxn, i);
        return maxn;
    }

    long long calculatetotalhrs(vector<int>& piles, int mid, int h){
        long long totalh = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            totalh += (piles[i] + mid - 1) / mid;  // integer ceil, no floating point
            if (totalh > h) return totalh;         // early exit once infeasible
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmax(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;      // overflow-safe midpoint
            long long totalh = calculatetotalhrs(piles, mid, h);
            if(totalh <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};