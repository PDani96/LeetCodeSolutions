#include <vector>

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<int> playerOne;
        vector<int> playerTwo;
        int scoreOne = 0;
        int scoreTwo = 0;
        // track if it is player one's turn, initialize to true
        bool turn = true;

        // loop until only one number is left
        while(nums.size() > 1){
            // check who's turn it is 
            if(turn){
                // check if scoring differential is higher for picking the first number
                if(nums[1] - nums[0] > nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick last number
                    scoreOne += nums[nums.size()-1];
                    playerOne.push_back(nums.back());
                    // remove last number
                    nums.pop_back();
                }
                // check if scoring differential is higher for picking the last number
                else if(nums[1] - nums[0] < nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick first number
                    scoreOne += nums[0];
                    playerOne.push_back(nums.front());
                    // remove first number
                    nums.erase(nums.begin());
                }
                // scoring differential is equal
                else if(nums[1] - nums[0] == nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick highest number
                    if(nums[0] > nums[nums.size()-1]){
                        scoreOne += nums[0];
                        playerOne.push_back(nums.front());
                        nums.erase(nums.begin());
                    }
                    else if(nums[0] < nums[nums.size()-1]){
                        scoreOne += nums[nums.size()-1];
                        playerOne.push_back(nums.back());
                        nums.pop_back();
                    }
                    else if(nums[0] == nums[nums.size()-1]){
                        scoreOne += nums[0];
                        playerOne.push_back(nums.front());
                        nums.erase(nums.begin());
                    }
                }
                // set player one's turn to over
                turn = false;
            }
            else{ // player two's turn
                // check if scoring differential is higher for picking the first number
                if(nums[1] - nums[0] > nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick last number
                    scoreTwo += nums[nums.size()-1];
                    playerTwo.push_back(nums.back());
                    // remove last number
                    nums.pop_back();
                }
                // check if scoring differential is higher for picking the last number
                else if(nums[1] - nums[0] < nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick first number
                    scoreTwo += nums[0];
                    playerTwo.push_back(nums.front());
                    // remove first number
                    nums.erase(nums.begin());
                }
                // scoring differential is equal
                else if(nums[1] - nums[0] == nums[nums.size()-2] - nums[nums.size()-1]){
                    // pick highest number
                    if(nums[0] > nums[nums.size()-1]){
                        scoreTwo += nums[0];
                        playerTwo.push_back(nums.front());
                        nums.erase(nums.begin());
                    }
                    else if(nums[0] < nums[nums.size()-1]){
                        scoreTwo += nums[nums.size()-1];
                        playerTwo.push_back(nums.back());
                        nums.pop_back();
                    }
                    else if(nums[0] == nums[nums.size()-1]){
                        scoreTwo += nums[0];
                        playerTwo.push_back(nums.front());
                        nums.erase(nums.begin());
                    }
                }

                // set player two's turn to over
                turn = true;
            }
        }

        // check who's turn it is when only one number is left and assign remaining number
        if(turn){
            playerOne.push_back(nums.front());
            scoreOne += nums[0];
        }
        else{
            playerTwo.push_back(nums.front());
            scoreTwo += nums[0];
        }

        for(auto num : playerOne){
            cout << num << " ";
        }

        cout << endl;

        for(auto num : playerTwo){
            cout << num << " ";
        }

        // check who's score is higher, return true if player one wins, false if player two wins
        if(scoreOne >= scoreTwo){
            return true;
        }
        else{
            return false;
        }
    }
};