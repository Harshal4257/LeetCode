class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;

        priority_queue<int> maxHeap; // max-heap of frequencies
        for (int f : freq) if (f > 0) maxHeap.push(f);

        queue<pair<int,int>> cooldown; // {remaining count, time it becomes available again}
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0)
                    cooldown.push({count, time + n});
            }

            // bring back any task whose cooldown has expired
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};