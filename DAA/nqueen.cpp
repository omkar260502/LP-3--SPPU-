#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<int> &solution)
{
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++)
    {
        if (solution[i] == row)
            return false;
    }
    // Check if there is a queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (solution[j] == i)
            return false;
    }
    // Check if there is a queen in the lower diagonal
    for (int i = row, j = col; i < solution.size() && j >= 0; i++, j--)
    {
        if (solution[j] == i)
            return false;
    }
    // The position is safe
    // cout << solution[1] << endl;
    return true;
}

void solveNQueens(int n, int col, vector<int> &solution, int &count)
{
    // Base case: All queens are placed
    if (col == n)
    {
        count++;
        cout << "Solution " << count << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (solution[j] == i)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    // Try to place the queen in each row of the current column
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, solution))
        {
            solution[col] = row;                       // Place the queen
            solveNQueens(n, col + 1, solution, count); // Recur to place the remaining queens
            solution[col] = -1;                        // Remove the queen (backtracking)
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;
    vector<int> solution(n, -1);
    int count = 0;
    solveNQueens(n, 0, solution, count);
    if (count == 0)
        cout << "No solution exists!" << endl;
    else
        cout << "Total number of solutions: " << count << endl;
    // printSolution(solution);
    return 0;
}
