class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int insertInd = 0;

        // instead of finding inserting index from starting find it from end otherwise you will not get a correct index 
        for(int i=n-1; i>=0; i--){  
            if(newInterval[0] > intervals[i][0]){
                insertInd = i + 1;
                break;
            } else if(newInterval[0] == intervals[i][0]){
                if(newInterval[1] > intervals[i][1]){
                    insertInd = i + 1;
                } else {
                    insertInd = i;
                }

                break;
            }
        }

        intervals.insert(intervals.begin() + insertInd, newInterval);

        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){

            // if(intervals[i][0] <= intervals[i-1][1]){  mistake: instead of comparing it with the end of last pair compare it with the end of last merged pair

            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end);
            } else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});
        return ans;
        
    }
};