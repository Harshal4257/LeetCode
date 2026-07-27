class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars(n);
        for(int i = 0; i < n; i++){
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end(), greater<>());  // sort by position descending

        stack<double> st;
        for(auto& [pos, time] : cars){
            if(st.empty() || time > st.top()){
                st.push(time);   // new fleet
            }
            // else: merges into fleet ahead, do nothing
        }
        return st.size();
    }
};