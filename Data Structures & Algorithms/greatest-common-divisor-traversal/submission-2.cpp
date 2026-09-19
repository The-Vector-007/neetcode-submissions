class Solution {
public:

    vector<int> primeFac(int n) {
        vector<int> res;

        // Check for factor 2
        if (n % 2 == 0) {
            res.push_back(2);
            while (n % 2 == 0) n /= 2;
        }

        // Check for odd prime factors
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                res.push_back(i);
                while (n % i == 0) n /= i;
            }
        }

        // If remaining n is a prime number > 2
        if (n > 2) res.push_back(n);

        return res;
    }

    vector<int> parent, sz;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb) return;

        if(sz[rb] > sz[ra]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        parent = vector<int>(n);
        sz = vector<int>(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        unordered_map<int, int> owner;
        for(int i = 0; i < n; i++){
            
            if(nums[i] == 1) continue;

            vector<int> uniqueFactors = primeFac(nums[i]);
            for(int uF: uniqueFactors){
                if(!owner.count(uF)){
                    owner[uF] = i;
                }
                else{
                    int currIndex = i;
                    int lastIndex = owner[uF];
                    unite(currIndex, lastIndex);
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << i << " : " << parent[i] << endl;
        }

        cout << endl;

        for(int i = 0; i < n; i++){
            cout << i << " : " << sz[i] << endl;
        }

        if(*max_element(sz.begin(), sz.end()) != n){
            return false;
        }


        return true;
    }
};