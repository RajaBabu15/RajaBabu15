#include <string>
#include <vector>
#include <iostream>
using namespace std;

void findstart(vector<vector<char>> &board, int n, int m, char ch,
               vector<pair<int, int>> &start)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == ch)
            {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                start.push_back(p);
            }
        }
    }
}

int hasPathHelper(vector<vector<char>> &board, int n, int m, int startx,
                  int starty, int x, int y, char ch, int **visited,
                  bool begin = true)
{
    if (startx == x && starty == y && begin == false)
    {
        return 1;
    }
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || i == x && j == y || i - x == j - y || i - x + i - y == 0)
                continue;
            if (board[i][j] == ch && i == startx && j == starty)
            {
                return 1;
            }
            if (board[i][j] == ch && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                int smallOutput = hasPathHelper(board, n, m, startx, starty, i, j, ch,
                                                visited, false);
                visited[i][j] = 0;
                if (smallOutput == -1)
                    return -1;
                if (smallOutput >= 1)
                {
                    return 1 + smallOutput;
                }
            }
        }
    }
    return -1;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        vector<pair<int, int>> starting;
        findstart(board, n, m, ch, starting);
        int **visited = new int *[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < starting.size(); i++)
        {
            pair<int, int> start = starting[i];
            visited[start.first][start.second] = 1;
            int smallOutput = hasPathHelper(board, n, m, start.first, start.second,
                                            start.first, start.second, ch, visited);
            visited[start.first][start.second] = 0;

            if (smallOutput >= 4)
                return 1;
        }
    }
    return 0;
}