class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for(int step=0; step<n; step++){
            int right = (startIndex + step) % n;
            int left = (startIndex - step + n) % n;

            if(words[left] == target || words[right] == target){
                return step;
            }
        }
        return -1;
    }
};