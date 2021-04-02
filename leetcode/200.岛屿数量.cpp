/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<int> fa;

public:
    void init(int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                fa.push_back(i * n + j);
        }
    }

    int find(int x)
    {
        return x == fa[x] ? x : (fa[x] == find(fa[x]));
    }

    // 将前者合并到后者
    inline void merge(int x, int y)
    {
        fa[find(x)] = find(y);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        init(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    for (int k = 0; k < 4; k++)
                    {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1')
                            merge(i * n + j, xx * n + yy);
                    }
                }
            }
        }
        set<int> st;
        for (int i = 0; i < m * n; i++)
            st.insert(fa[i]);
        return st.size();
    }
};
// @lc code=end
