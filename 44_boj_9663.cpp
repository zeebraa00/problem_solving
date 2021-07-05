#include <iostream>
#include <cstdio>

using namespace std;

int n;
int cnt = 0;
int ground[15][15] = {0,};

bool check_queen(int row, int col)
{
    for (int i=0; i<n; i++)
    {
        if (ground[row][i] == 1)
        {
            return false;
        }
        if (ground[i][col] == 1)
        {
            return false;
        }
        if (0 <= row-i && row -i < n && 0 <= col-i && col-i < n && ground[row-i][col-i] == 1)
        {
            return false;
        }
        if (0 <= row-i && row -i < n && 0 <= col+i && col+i < n && ground[row-i][col+i] == 1)
        {
            return false;
        }
    }
    return true;
}

void backtracking(int row)
{
    for (int col=0; col<n; col++)
    {
        if (check_queen(row,col))
        {
            if (row == n-1)
            {
                cnt++;
                return;
            }
            ground[row][col] = 1;
            backtracking(row+1);
            ground[row][col] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    backtracking(0);
    printf("%d\n", cnt);
    return 0;
}