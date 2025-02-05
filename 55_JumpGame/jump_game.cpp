#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;

    bool canJump(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return canJumpHelper(nums, 0);
    }

    bool canJumpHelper(vector<int>& nums, int index){
        if(index >= nums.size()-1){
            return memo[index] = true;
        }
        if(nums[index] == 0){
            return memo[index] = false;
        }
        if(memo[index] != -1){
            return memo[index];
        }

        for(int i = 1; i <= nums[index]; i++){
            if(canJumpHelper(nums, index + i)){
                return memo[index] = true;
            }
        }

        return memo[index] = false;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> test1 = {2, 3, 1, 1, 4};
    vector<int> test2 = {3, 2, 1, 0, 4};
    vector<int> test3 = {0}; // Edge case: Single-element array

    cout << "Test 1: " << (solution.canJump(test1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solution.canJump(test2) ? "true" : "false") << endl;
    cout << "Test 3: " << (solution.canJump(test3) ? "true" : "false") << endl;

    return 0;
}
