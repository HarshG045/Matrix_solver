#include <stdio.h>
#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowA, int colA, int rowB, int colB);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
int determinant(int matrix[MAX][MAX], int n);
void cofactor(int matrix[MAX][MAX], int temp[MAX][MAX], int p, int q, int n);
int inverseMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int n);
int findRank(int matrix[MAX][MAX], int rows, int cols);
void getMinor(int matrix[MAX][MAX], int minor[MAX][MAX], int row, int col, int n);
void scalarMultiplyMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols, int scalar);
void rowSwap(int matrix[MAX][MAX], int rows, int cols, int row1, int row2);
void columnSwap(int matrix[MAX][MAX], int rows, int cols, int col1, int col2);
void extractDiagonal(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
int isIdentityMatrix(int matrix[MAX][MAX], int n);
int isSymmetricMatrix(int matrix[MAX][MAX], int rows, int cols);
int traceMatrix(int matrix[MAX][MAX], int n);
int isDiagonalMatrix(int matrix[MAX][MAX], int n);
void rowEchelonForm(int matrix[MAX][MAX], int rows, int cols);
void getCofactorMatrix(int matrix[MAX][MAX], int cofactor[MAX][MAX], int rows, int cols);
int isSquareMatrix(int matrix[MAX][MAX], int rows, int cols);
void calculateEigenvaluesEigenvectors(int matrix[MAX][MAX], int n);
void solveSystemOfLinearEquations(int matrix[MAX][MAX], int n);

int main()
{
    int choice;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB, scalar;

    while (1)
    {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Determinant of Matrix\n");
        printf("6. Inverse of Matrix\n");
        printf("7. Rank of Matrix\n");
        printf("8. Scalar Multiplication\n");
        printf("9. Row Swap\n");
        printf("10. Column Swap\n");
        printf("11. Extract Diagonal\n");
        printf("12. Check Identity Matrix\n");
        printf("13. Check Symmetric Matrix\n");
        printf("14. Trace of Matrix\n");
        printf("15. Check Diagonal Matrix\n");
        printf("16. Row Echelon Form (REF)\n");
        printf("17. Minor of a Matrix\n");
        printf("18. Cofactor Matrix\n");
        printf("19. Check Square Matrix\n");
        printf("20. Eigenvalues\n");
        printf("21. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // pranav
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter dimensions of matrix B (rows cols): ");
            scanf("%d %d", &rowsB, &colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                printf("Matrix dimensions must match for addition.\n");
                break;
            }
            printf("Enter matrix B:\n");
            inputMatrix(B, rowsB, colsB);

            addMatrices(A, B, result, rowsA, colsA);
            printf("Resultant Matrix after Addition:\n");
            printMatrix(result, rowsA, colsA);
            break;

        case 2: // pranav
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter dimensions of matrix B (rows cols): ");
            scanf("%d %d", &rowsB, &colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                printf("Matrix dimensions must match for subtraction.\n");
                break;
            }
            printf("Enter matrix B:\n");
            inputMatrix(B, rowsB, colsB);

            subtractMatrices(A, B, result, rowsA, colsA);
            printf("Resultant Matrix after Subtraction:\n");
            printMatrix(result, rowsA, colsA);
            break;

        case 3: // pranav
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter dimensions of matrix B (rows cols): ");
            scanf("%d %d", &rowsB, &colsB);
            if (colsA != rowsB)
            {
                printf("Matrix dimensions must match for multiplication.\n");
                break;
            }
            printf("Enter matrix B:\n");
            inputMatrix(B, rowsB, colsB);

            multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
            printf("Resultant Matrix after Multiplication:\n");
            printMatrix(result, rowsA, colsB);
            break;

        case 4: // pranav
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            transposeMatrix(A, result, rowsA, colsA);
            printf("Transposed Matrix:\n");
            printMatrix(result, colsA, rowsA);
            break;

        case 5: // satej
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Determinant is only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            int det = determinant(A, rowsA);
            printf("Determinant of matrix A: %d\n", det);
            break;

        case 6: // satej
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Inverse is only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            if (inverseMatrix(A, result, rowsA))
            {
                printf("Inverse of matrix A:\n");
                printMatrix(result, rowsA, colsA);
            }
            else
            {
                printf("Matrix A is singular and does not have an inverse.\n");
            }
            break;

        case 7: // satej
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            int rank = findRank(A, rowsA, colsA);
            printf("Rank of matrix A: %d\n", rank);
            break;

        case 8: // yash
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter scalar value: ");
            scanf("%d", &scalar);

            scalarMultiplyMatrix(A, result, rowsA, colsA, scalar);
            printf("Matrix after Scalar Multiplication:\n");
            printMatrix(result, rowsA, colsA);
            break;

        case 9: // yash
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter row numbers to swap (1-based): ");
            int row1, row2;
            scanf("%d %d", &row1, &row2);
            rowSwap(A, rowsA, colsA, row1 - 1, row2 - 1);
            printf("Matrix after Row Swap:\n");
            printMatrix(A, rowsA, colsA);
            break;

        case 10: // yash
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter column numbers to swap (1-based): ");
            int col1, col2;
            scanf("%d %d", &col1, &col2);
            columnSwap(A, rowsA, colsA, col1 - 1, col2 - 1);
            printf("Matrix after Column Swap:\n");
            printMatrix(A, rowsA, colsA);
            break;

        case 11: // yash
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            extractDiagonal(A, result, rowsA, colsA);
            printf("Diagonal elements of the matrix:\n");
            printMatrix(result, rowsA, colsA);
            break;

        case 12: // aadi
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Identity matrix check is only for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            if (isIdentityMatrix(A, rowsA))
            {
                printf("Matrix A is an Identity Matrix.\n");
            }
            else
            {
                printf("Matrix A is not an Identity Matrix.\n");
            }
            break;

        case 13: // aadi
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Symmetric matrix check is only for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            if (isSymmetricMatrix(A, rowsA, colsA))
            {
                printf("Matrix A is Symmetric.\n");
            }
            else
            {
                printf("Matrix A is not Symmetric.\n");
            }
            break;

        case 14: // aadi
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Trace is only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            int trace = traceMatrix(A, rowsA);
            printf("Trace of matrix A: %d\n", trace);
            break;

        case 15: // aadi
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Diagonal matrix check is only for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            if (isDiagonalMatrix(A, rowsA))
            {
                printf("Matrix A is a Diagonal Matrix.\n");
            }
            else
            {
                printf("Matrix A is not a Diagonal Matrix.\n");
            }
            break;

        case 16: // harsh
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            rowEchelonForm(A, rowsA, colsA);
            printf("Matrix in Row Echelon Form:\n");
            printMatrix(A, rowsA, colsA);
            break;

        case 17: // harsh
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Minor is only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            printf("Enter row and column to get minor (1-based): ");
            int row, col;
            scanf("%d %d", &row, &col);

            int minor[MAX][MAX];
            getMinor(A, minor, row - 1, col - 1, rowsA);
            printf("Minor of element (%d, %d):\n", row, col);
            printMatrix(minor, rowsA - 1, colsA - 1);
            break;

        case 18: // shivam
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Cofactor matrix is only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);

            int cofactor[MAX][MAX];
            getCofactorMatrix(A, cofactor, rowsA, colsA);
            printf("Cofactor matrix of A:\n");
            printMatrix(cofactor, rowsA, colsA);
            break;

        case 19: // shivam
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (isSquareMatrix(A, rowsA, colsA))
            {
                printf("Matrix A is a square matrix.\n");
            }
            else
            {
                printf("Matrix A is not a square matrix.\n");
            }
            break;
        case 20: // shivam
            printf("Enter dimensions of matrix A (rows cols): ");
            scanf("%d %d", &rowsA, &colsA);
            if (rowsA != colsA)
            {
                printf("Eigenvalues and Eigenvectors are only defined for square matrices.\n");
                break;
            }
            printf("Enter matrix A:\n");
            inputMatrix(A, rowsA, colsA);
            calculateEigenvaluesEigenvectors(A, rowsA);
            break;

        case 21:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowA, int colA, int rowB, int colB)
{
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int determinant(int matrix[MAX][MAX], int n)
{
    if (n == 1)
    {
        return matrix[0][0];
    }
    int det = 0;
    int temp[MAX][MAX];
    for (int p = 0; p < n; p++)
    {
        cofactor(matrix, temp, 0, p, n);
        det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * determinant(temp, n - 1);
    }
    return det;
}

void cofactor(int matrix[MAX][MAX], int temp[MAX][MAX], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int inverseMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int n)
{
    int det = determinant(matrix, n);
    if (det == 0)
    {
        return 0;
    }
    int temp[MAX][MAX];
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cofactor(matrix, temp, i, j, n);
            result[j][i] = sign * determinant(temp, n - 1) / det;
            sign = -sign;
        }
    }
    return 1;
}

int findRank(int matrix[MAX][MAX], int rows, int cols)
{
    int rank = 0;
    int temp[MAX][MAX];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }

    for (int row = 0; row < rows; row++)
    {
        int pivot_col = -1;
        for (int col = rank; col < cols; col++)
        {
            for (int i = row; i < rows; i++)
            {
                if (temp[i][col] != 0)
                {
                    if (i != row)
                    {
                        rowSwap(temp, rows, cols, row, i);
                    }
                    pivot_col = col;
                    break;
                }
            }
            if (pivot_col != -1)
                break;
        }
        if (pivot_col == -1)
            break;

        for (int i = 0; i < rows; i++)
        {
            if (i != row && temp[i][pivot_col] != 0)
            {
                int factor = temp[i][pivot_col] / temp[row][pivot_col];
                for (int j = pivot_col; j < cols; j++)
                {
                    temp[i][j] -= factor * temp[row][j];
                }
            }
        }
        rank++;
    }
    return rank;
}

void rowSwap(int matrix[MAX][MAX], int rows, int cols, int row1, int row2)
{
    for (int i = 0; i < cols; i++)  
    {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void columnSwap(int matrix[MAX][MAX], int rows, int cols, int col1, int col2)
{
    for (int i = 0; i < rows; i++)
    {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void scalarMultiplyMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols, int scalar)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void extractDiagonal(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    int min_dim = rows < cols ? rows : cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < min_dim; i++)
    {
        result[i][i] = matrix[i][i];
    }
}

int isIdentityMatrix(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

int isSymmetricMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
    {
        return 0;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int traceMatrix(int matrix[MAX][MAX], int n)
{
    int trace = 0;
    for (int i = 0; i < n; i++)
    {
        trace += matrix[i][i];
    }
    return trace;
}

int isDiagonalMatrix(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void rowEchelonForm(int matrix[MAX][MAX], int rows, int cols)
{
    int lead = 0;
    for (int r = 0; r < rows; r++)
    {
        if (lead >= cols)
        {
            return;
        }
        int i = r;
        while (matrix[i][lead] == 0)
        {
            i++;
            if (i == rows)
            {
                i = r;
                lead++;
                if (lead == cols)
                {
                    return;
                }
            }
        }
        if (i != r)
        {
            rowSwap(matrix, rows, cols, r, i);
        }

        int val = matrix[r][lead];
        for (int j = 0; j < cols; j++)
        {
            matrix[r][j] /= val;
        }
        for (int i = 0; i < rows; i++)
        {
            if (i != r)
            {
                int factor = matrix[i][lead];
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] -= factor * matrix[r][j];
                }
            }
        }
        lead++;
    }
}

void getCofactorMatrix(int matrix[MAX][MAX], int cofactor1[MAX][MAX], int rows, int cols)
{
    if (rows != cols)
        return;
    int n = rows;
    int temp[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cofactor(matrix, temp, i, j, n);
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            cofactor1[i][j] = sign * determinant(temp, n - 1);
        }
    }
}

int isSquareMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    return (rows == cols);
}

void getMinor(int matrix[MAX][MAX], int minor[MAX][MAX], int row, int col, int n)
{
    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == row)
            continue;
        minorCol = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == col)
                continue;
            minor[minorRow][minorCol] = matrix[i][j];
            minorCol++;
        }
        minorRow++;
    }
}

void calculateEigenvaluesEigenvectors(int matrix[MAX][MAX], int n)
{
    if (n == 2)
    {
        int a = matrix[0][0], b = matrix[0][1], c = matrix[1][0], d = matrix[1][1];
        int trace = a + d;
        int det = a * d - b * c;

        int discriminant = trace * trace - 4 * det;

        if (discriminant < 0)
        {
            printf("The eigenvalues are complex numbers. Eigenvalue calculation in this program only supports real numbers.\n");
        }
        else
        {

            int eigenvalue1 = (trace + discriminant) / 2;
            int eigenvalue2 = (trace - discriminant) / 2;

            printf("Eigenvalues for 2x2 matrix: %d and %d\n", eigenvalue1, eigenvalue2);
        }
    }
    else if (n == 3)
    {

        printf("Eigenvalue calculation for 3x3 matrices is not fully implemented.\n");
    }
    else
    {
        printf("Eigenvalue and Eigenvector calculations for this matrix size are not supported.\n");
    }
}

// void solveSystemOfLinearEquations(int matrix[MAX][MAX], int n)
// {

//     float augmented[MAX][MAX], temp;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n + 1; j++)
//         {
//             augmented[i][j] = matrix[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (augmented[i][i] == 0)
//         {
//             for (int k = i + 1; k < n; k++)
//             {
//                 if (augmented[k][i] != 0)
//                 {
//                     for (int j = 0; j <= n; j++)
//                     {
//                         temp = augmented[i][j];
//                         augmented[i][j] = augmented[k][j];
//                         augmented[k][j] = temp;
//                     }
//                     break;
//                 }
//             }
//         }

//         for (int j = i + 1; j < n; j++)
//         {
//             if (augmented[j][i] != 0)
//             {
//                 temp = augmented[j][i] / augmented[i][i];
//                 for (int k = i; k <= n; k++)
//                 {
//                     augmented[j][k] -= augmented[i][k] * temp;
//                 }
//             }
//         }
//     }

//     float solution[MAX];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         solution[i] = augmented[i][n];
//         for (int j = i + 1; j < n; j++)
//         {
//             solution[i] -= augmented[i][j] * solution[j];
//         }
//         solution[i] /= augmented[i][i];
//     }

//     printf("Solution of the system of equations:\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("x%d = %.2f\n", i + 1, solution[i]);
//     }
// }
// case 21://shivam
//     printf("Enter dimensions of the augmented matrix (n x n+1): ");
//     scanf("%d", &rowsA);
//     colsA = rowsA + 1;
//     printf("Enter augmented matrix (including constants on the last column):\n");
//     inputMatrix(A, rowsA, colsA);
//     solveSystemOfLinearEquations(A, rowsA);
//     break;
// printf("21. Solve System of Linear Equations\n");
