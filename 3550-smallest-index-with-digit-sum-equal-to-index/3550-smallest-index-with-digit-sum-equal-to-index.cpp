class Solution {
public:
    int sumOfDigits(int element){
        int sum = 0;

        while(element > 0){
            sum += element % 10;
            element /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(sumOfDigits(nums[i]) == i){
                return i;
            }
        }

        return -1;
    }
};