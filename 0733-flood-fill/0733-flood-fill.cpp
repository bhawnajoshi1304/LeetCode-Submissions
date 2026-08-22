class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return (i < n && j < m && i >= 0 && j >= 0);
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int c, int n, int m) {
        int color = image[sr][sc];
        image[sr][sc] = c;
        if (c != color) {
            vector<int> dx =
                            {
                                0,
                                -1,
                                1,
                                0,
                            },
                        dy = {
                            -1,
                            0,
                            0,
                            1,
                        };
            for (int i = 0; i < 4; i++) {
                if (isValid(sr + dx[i], sc + dy[i], n, m) &&
                    image[sr + dx[i]][sc + dy[i]] == color) {
                    dfs(image, sr + dx[i], sc + dy[i], c, n, m);
                }
            }
        }
            image[sr][sc] = c;
        }
        vector<vector<int>> floodFill(vector<vector<int>> & image, int sr,
                                      int sc, int color) {
            int n = image.size(), m = image[0].size();
            dfs(image, sr, sc, color, n, m);

            return image;
        }
    };