class Solution {
public:
    void findCombinations(vector<int> &nums, vector<int> &combination, vector<vector<int>> &res, int i, int k, int remSum, int count){
        if(remSum == 0 && count == k){
            res.push_back(combination);
            return;
        }

        if(remSum < 0 || count == k || i == nums.size()){
            return ;
        }

        combination.push_back(nums[i]);
        findCombinations(nums, combination, res, i+1, k, remSum - nums[i], count+1);
        combination.pop_back();

        findCombinations(nums, combination, res, i+1, k, remSum, count);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5 , 6, 7, 8, 9};

        vector<vector<int>> res;
        vector<int> combination;

        findCombinations(nums, combination, res, 0, k, n, 0);
        
        return res;

    }
};