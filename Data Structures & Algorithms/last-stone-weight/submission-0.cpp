class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int stone : stones)
            maxHeap.push(stone);

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(abs(x - y));
        }

        return maxHeap.size() ? maxHeap.top() : 0;
    }
};
