#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &arr, int x, int y, int n)
{
    if (x < n && y < n && x >= 0 && y >= 0 && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(vector<vector<int>> &arr, int x, int y, int n, vector<vector<int>> &sol)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n) == true)
    {
        sol[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, sol) == true)
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, sol) == true)
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> sol(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (ratInMaze(arr, 0, 0, n, sol) == true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No Solution exist";
    }
    return 0;
}