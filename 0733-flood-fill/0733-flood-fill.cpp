class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // edge case
        if(color == image[sr][sc]){
            return image;
        }

        int r = image.size();
        int c = image[0].size();

        int originalColor = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int, int>> q;

        q.push({sr, sc});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            // left up right down
            int drow[] = {0, -1, 0, +1};
            int dcol[] = {-1, 0, +1, 0};

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < r && ncol >= 0 && ncol < c && image[nrow][ncol] == originalColor){
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};