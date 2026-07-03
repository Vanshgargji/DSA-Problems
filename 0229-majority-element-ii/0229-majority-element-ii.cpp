class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;

        for(auto &num : nums){
            if(cnt1 == 0 && num != ele2){
                ele1 = num;
                cnt1++;
            }
            else if(cnt2 == 0 && num != ele1){
                ele2 = num;
                cnt2++;
            }
            else if(num == ele1){
                cnt1++;
            }
            else if(num == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(auto &i : nums){
            if(ele1 == i) cnt1++;
            else if(ele2 == i) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3 && ele1 != ele2) ans.push_back(ele2);

        return ans;
    }
};