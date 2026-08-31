class MedianFinder {
    priority_queue<int> lower;                              // max-heap, holds smaller half
    priority_queue<int, vector<int>, greater<int>> upper;    // min-heap, holds larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        // rebalance so sizes differ by at most 1
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size() + 1) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if (lower.size() == upper.size())
            return (lower.top() + upper.top()) / 2.0;
        return lower.size() > upper.size() ? lower.top() : upper.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */