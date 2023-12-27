#include <iostream>
#include<windows.h>
#include <vector>
using namespace std;

int** createMatrix(int rows, int cols) 
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int calculateProductOfNonNegativeRows(int** matrix, int rows, int cols) 
{
    int product = 1;

    for (int i = 0; i < rows; ++i) 
    {
        bool hasNegative = false;
        for (int j = 0; j < cols; ++j) 
        {
            if (matrix[i][j] < 0) 
            {
                hasNegative = true;
                break;
            }
        }

        if (!hasNegative) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                product *= matrix[i][j];
            }
        }
    }

    return product;
}


int calculateMaxSumOfParallelDiagonals(int** matrix, int rows, int cols) 
{
    int maxSum = 0;

    for (int i = 0; i < rows; ++i) 
    {
        int sum = 0;
        for (int j = 0; i + j < rows && j < cols; ++j) 
        {
            sum += matrix[i + j][j];
        }
        if (sum > maxSum) 
        {
            maxSum = sum;
        }
    }

    for (int j = 1; j < cols; ++j) 
    {
        int sum = 0;
        for (int i = 0; i < rows && i + j < cols; ++i) 
        {
            sum += matrix[i][i + j];
        }
        if (sum > maxSum) 
        {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ukrainian");
    int rows, cols;

    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int** matrix = createMatrix(rows, cols);

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cin >> matrix[i][j];
            
        }
    }
    cout << "\nМатриця:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    int product = calculateProductOfNonNegativeRows(matrix, rows, cols);
    int maxSum = calculateMaxSumOfParallelDiagonals(matrix, rows, cols);

    cout << "Добуток елементів у рядках без мінусів: " << product << endl;
    cout << "Максимальна сума елементів в діагоналях, паралельних головній діагоналі: " << maxSum << endl;
   
    deleteMatrix(matrix, rows);

    return 0;
}
