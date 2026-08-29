class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x,y;
        for(int i = 0;i < stones.size();i++) pq.push(stones[i]);
        while(pq.size() > 1) {
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();

            if(x == y) continue;
            else if(x < y) pq.push(y-x);
            else continue;
        }
        return pq.empty() ? 0 : pq.top(); 
    }
};