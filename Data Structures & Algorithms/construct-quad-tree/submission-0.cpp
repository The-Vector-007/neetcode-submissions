/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    pair<bool, int> isHomogeneous(vector<pair<int, int>> coordinates, vector<vector<int>>& grid){
        auto [rowStart, rowEnd] = coordinates[0];
        auto [columnStart, columnEnd] = coordinates[1];

        int baselineVal = grid[rowStart][columnStart];

        for(int row = rowStart; row <= rowEnd; row++){
            for(int column = columnStart; column <= columnEnd; column++){
                if(grid[row][column] != baselineVal){
                    return {false, -1};
                }
            }
        }

        return {true, baselineVal};
    }

    Node* buildQuadTree(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<vector<int>>& grid){

        if(rowStart > rowEnd || columnStart > columnEnd){
            return nullptr;
        }

        vector<pair<int, int>> coordinates = {{rowStart, rowEnd}, {columnStart, columnEnd}};

        auto [ok, val] = isHomogeneous(coordinates, grid);

        if(ok){
            return new Node(val, true);
        }
        
        return new Node(
            1,
            false,
            buildQuadTree(rowStart, (rowEnd + rowStart)/2, columnStart, (columnEnd + columnStart)/2, grid),
            buildQuadTree(rowStart, (rowEnd + rowStart)/2, (columnEnd + columnStart)/2 + 1, columnEnd, grid),
            buildQuadTree((rowEnd + rowStart)/2 + 1, rowEnd, columnStart, (columnEnd + columnStart)/2, grid),
            buildQuadTree((rowEnd + rowStart)/2  + 1, rowEnd, (columnEnd + columnStart)/2 + 1, columnEnd, grid)
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return nullptr;
        }

        int n = grid.size();
        int m = grid[0].size();

        Node* root = buildQuadTree(0, n-1, 0, m-1, grid);

        return root;
    }
};