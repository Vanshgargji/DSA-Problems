class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dash = 0 , right = 0, left = 0;

        for(int i=0; i<moves.size(); i++){
            if(moves[i] == '_') dash++;
            if(moves[i] == 'L') left++;
            if(moves[i] == 'R') right++;
        }

        return dash + abs(right - left);
    }
};