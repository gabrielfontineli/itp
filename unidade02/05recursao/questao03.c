#include <stdio.h>
#include <stdbool.h>

#define N 9

// Função para imprimir o Sudoku
void printSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%d", grid[row][col]);
        printf("\n");
    }
}

// Função para verificar se é seguro colocar um número na posição (row, col)
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Verifica a linha, a coluna e a submatriz 3x3
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Função para resolver o Sudoku
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }

    if (isEmpty)
        return true;

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[N][N];

    // Ler a matriz 9x9
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '*')
                grid[row][col] = 0;
            else
                grid[row][col] = ch - '0';
        }

    if (solveSudoku(grid))
        printSudoku(grid);
    else
        printf("Não tem solução!\n");

    return 0;
}
