class Solution {
public:
    void findCombinations(vector<int> &candidates, vector<int> &combination, vector<vector<int>> &res, int remSum, int i){
        if(remSum == 0){
            res.push_back(combination);
            return;
        }

        if(remSum < 0 || i == candidates.size()){
            return;
        }

        combination.push_back(candidates[i]);
        findCombinations(candidates, combination, res, remSum - candidates[i], i+1);
        combination.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }

        findCombinations(candidates, combination, res, remSum, i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());

        findCombinations(candidates, combination, res, target, 0);

        return res;
        
    }
};