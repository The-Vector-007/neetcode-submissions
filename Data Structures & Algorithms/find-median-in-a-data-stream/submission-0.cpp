class MedianFinder {
public:

    priority_queue<int> lower; //lower half - max heap - to access greatest of lower half
    priority_queue<int, vector<int>, greater<int>> upper; // upper half min heap - to access smallest of upper half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(lower.empty()){
            lower.push(num);
            return;
        }

        int lowerTop = lower.top();

        if(num <= lowerTop){
            lower.push(num);
        }
        else{
            upper.push(num);
        }

        if(lower.size() > upper.size() + 1){
            upper.push(lower.top());
            lower.pop();
        }

        if(upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }

    }
    
    double findMedian() {
        int sz = upper.size() + lower.size();

        if(sz & 1){
            return (double)(lower.top());
        }

        return (double)(upper.top() + lower.top()) / 2.0;
    }
};
