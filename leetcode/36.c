#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define COLS 9
#define ROWS 9

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            if (board[i][j] == '.')
                continue;

            for (int z = j + 1; z < boardColSize[i]; z++)
            {
                if (board[i][j] == board[i][z])
                    return false;
            }
        }
    }

    for (int j = 0; j < boardColSize[0]; j++)
    {
        for (int i = 0; i < boardSize; i++)
        {
            if (board[i][j] == '.')
                continue;

            for (int z = i + 1; z < boardSize; z++)
            {
                if (board[i][j] == board[z][j])
                    return false;
            }
        }
    }

    for (int boxRow = 0; boxRow < 9; boxRow += 3)
    {
        for (int boxCol = 0; boxCol < 9; boxCol += 3)
        {
            for (int i = boxRow; i < boxRow + 3; i++)
            {
                for (int j = boxCol; j < boxCol + 3; j++)
                {
                    if (board[i][j] == '.')
                        continue;

                    for (int x = i; x < boxRow + 3; x++)
                    {
                        for (int y = (x == i ? j + 1 : boxCol);
                             y < boxCol + 3; y++)
                        {
                            if (board[i][j] == board[x][y])
                                return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main()
{

    int boardSize = 9;

    int *boardColSize = (int *)malloc(boardSize * sizeof(int));
    for (int i = 0; i < boardSize; i++)
    {
        boardColSize[i] = 9;
    }

    char **board = (char **)malloc(boardSize * sizeof(char *));
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = (char *)malloc(9 * sizeof(char));
    }

    char temp[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '1', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = temp[i][j];
        }
    }

    bool result = isValidSudoku(board, boardSize, boardColSize);

    printf("%s\n", result ? "true" : "false");

    for (int i = 0; i < boardSize; i++)
    {
        free(board[i]);
    }
    free(board);
    free(boardColSize);

    return 0;
}