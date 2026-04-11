class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        vector<int> last(10, -1);

        for(int i=0; i < s.size(); i++){
            last[s[i] - '0'] = i;
        }

        for(int i=0 ; i < s.size(); i++){
            int d = s[i] - '0';
            for(int j=9; j >= d+1; j--){
                if(last[j] > i){
                    swap(s[i], s[last[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};