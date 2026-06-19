class Solution {
public:

    bool row_predicate(int target_val, int l, int r){
        if(target_val >= l && target_val <= r){
            return true;
        }

        return false;
    }

    bool search_row(vector<int>& arr, int target){
        int l = 0;
        int r = arr.size() - 1;

        while(l <= r){
            int m = l + (r-l)/2;
            if(target == arr[m]){
                return true;
            }
            else if(target > arr[m]){
                l = m + 1;
            }
            else if(target < arr[m]){
                r = m - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row_low = 0, row_high = m - 1;
        int target_row_index = -1;
        
        while(row_low <= row_high){
            int row_mid = row_low + (row_high - row_low)/2;

            if(row_predicate(target, matrix[row_mid][0], matrix[row_mid][n-1])){
                target_row_index = row_mid;
                break;
            }
            else if(target < matrix[row_mid][0]){
                row_high = row_mid - 1;
            }
            else if(target > matrix[row_mid][n-1]){
                row_low = row_mid + 1;
            }
        }

        if(target_row_index == -1){
            return false;
        }

        return search_row(matrix[target_row_index], target);
    }
};
