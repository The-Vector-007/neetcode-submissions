class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int x : nums)
            this->pq.push(x);
    }
    
    int add(int val) {
        this->pq.push(val);

        while(this->pq.size() > this->k){
            this->pq.pop();
        }

        return this->pq.top();
    }
};
