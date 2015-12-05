/*
Problem Link: https://www.acmicpc.net/problem/1149 
Easy DP problem
*/
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <algorithm>
#include <limits.h> 
using namespace std; 
 
int main()
{
    int n; 
    cin >> n; 
    vector< vector<int> > grid(n, vector<int>(3)); 
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int m; 
            cin >> m; 
            grid[i][j] = m; 
        }
    }
 
    for (int y = n-2; y >= 0; --y)
    {
        for (int x = 0; x < 3; ++x)
        {
            if (x == 0)
            {
                grid[y][x] += min(grid[y+1][1], grid[y+1][2]); 
            }
            else if (x == 1)
            {
                grid[y][x] += min(grid[y+1][0], grid[y+1][2]);  
            }
            else if (x == 2)
            {
                grid[y][x] += min(grid[y+1][1], grid[y+1][0]);  
            }
        }
    }
    
    int minval = grid[0][0];
    for (int i = 1; i < 3; ++i)
    {
        if (minval > grid[0][i])
        {
            minval = grid[0][i]; 
        }
    }
    cout << minval << endl;
    return 0; 
}

