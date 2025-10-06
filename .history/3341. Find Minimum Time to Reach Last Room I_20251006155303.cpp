class Solution
{
public:
  vector<int> dir = {0, 1, 0, -1, 0};

  bool isValid(int x, int y, int r, int c)
  {
    return (x >= 0 && x < r && y >= 0 && y < c);
  }

  int minTimeToReach(vector<vector<int>> &moveTime)
  {
    int r = moveTime.size(), c = moveTime[0].size();

    vector<vector<int>> mn(r, vector<int>(c, INT_MAX));
    vector<vector<bool>> vis(r, vector<bool>(c, false));

    using T = tuple<int, int, int>; // t, x, y
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.push({0, 0, 0});
    mn[0][0] = 0;

    while (!pq.empty())
    {
      auto [t, x, y] = pq.top();
      pq.pop();

      if (vis[x][y])
        continue;
      vis[x][y] = true;

      for (int i = 0; i < 4; i++)
      {
        int nx = x + dir[i];
        int ny = y + dir[i + 1];
        if (!isValid(nx, ny, r, c))
          continue;

        int nt = max(mn[x][y], moveTime[nx][ny]) + 1;
        if (nt < mn[nx][ny])
        {
          mn[nx][ny] = nt;
          pq.push({nt, nx, ny});
        }
      }
    }

    return mn[r - 1][c - 1];
  }
};
