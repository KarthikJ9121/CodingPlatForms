class Solution {
public:
    void dfs(int sr, int sc, int iniColor, int newColor, 
    vector<vector<int>> &image, vector<vector<int>> &ans, int dx[], int dy[])
    {
        int n = image.size();
        int m = image[0].size();

        ans[sr][sc] = newColor;
        for(int i = 0; i < 4; i++)
        {
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == iniColor && ans[nx][ny] != newColor)
                dfs(nx, ny, iniColor, newColor, image, ans, dx, dy);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};

        dfs(sr, sc, iniColor, newColor, image, ans, dx, dy);

        return ans;
    }
};
