#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        // get number of rows
        int rows = findHeight(root) + 1;
        // get number of columns
        int cols = pow(2, rows) - 1;

        // define result vector with 'm' rows of vectors containing 'n' columns of blank strings
        vector<vector<string>> res(rows, vector<string>(cols, ""));

        fillMatrix(root, 0, 0, cols-1, res);

        return res;
    }

    int findHeight(TreeNode* root) {
        if(root == nullptr){
            return -1;
        } else {
            int leftHeight = findHeight(root->left);
            int rightHeight = findHeight(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }

    void fillMatrix(TreeNode* node, int row, int left, int right, vector<vector<string>>& res){
        if(node == nullptr){
            return;
        }

        int mid = left + (right-left)/2;

        res[row][mid] = to_string(node->val);
        
        fillMatrix(node->left, row + 1, left, mid-1, res);
        fillMatrix(node->right, row + 1, mid+1, right, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution sol;
    vector<vector<string>> result = sol.printTree(root);

    for (const auto& row : result) {
        for (const auto& cell : row) {
            cout << (cell.empty() ? " " : cell) << " ";
        }
        cout << endl;
    }

    return 0;
}