#include <iostream>
#include <ctime>
using namespace std;

template <typename T> void foo(T** arr, const int row, const int col);

int main()
{
    setlocale(LC_ALL, "rus");

    //1

    //int n=3, m=3;// коли-во строк и столбцов
    //int arr1[3][3]{
    // { 1, 2, 3}, 
    // { 6, 7, 8},
    // { 1, 2, 3},
    //};
    //int arr2[3][3];
    //int count = 0;
    //    cout << "Исходный массив: " << endl;
    //    for (int i = 0; i < n; i++)
    //    {
    //        for (int j = 0; j < m; j++)
    //            cout << arr1[i][j] << " ";
    //        cout << endl;
    //    }
    //    int k = 0;
    //    for (int i = 0; i < n; i++)
    //    {
    //      int arr[3]{ 0 };
    //        for (int j = 0; j < n; j++) {
    //                arr[j] = arr1[i][j];
    //        }
    //        for (int q = i; q < n; q++)
    //        {
    //            for (int j = 0; j < n; j++) {
    //               
    //                if (arr[j] == arr1[q][j])
    //                {
    //                    count++;
    //                }
    //            }
    //            if (count != 3) {
    //                for (int j = 0; j < m; j++)
    //                    arr2[k][j] = arr1[q][j];
    //                k++;
    //            }
    //            count = 0;
    //        }
    //        /*if ((i + 1) % 2 == 0)
    //        {
    //            for (int j = 0; j < m; j++)
    //                arr2[k][j] = arr1[i][j];
    //            k++;
    //        }*/
    //    }
    //    cout << "\nМассив после удаления четеых строк:" << endl;
    //    for (int i = 0; i < k; i++)4
    //    {
    //        for (int j = 0; j < m; j++)
    //            cout << arr2[i][j] << " ";
    //        cout << endl;
    //    }
    //   
  
    //2
    const int ROWS = 4, COLS = 7;

    int** array = new int* [ROWS];
    for (int i = 0; i < 4; i++)
    {
        array[i] = new int[COLS];
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] = rand() % 89 + 10;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }

    foo(array, ROWS, COLS);

    cout << endl;

    int tmpCols;
    if (COLS % 2 == 1)
    {
        tmpCols = COLS / 2 + 1;
    }
    else
    {
        tmpCols = COLS / 2;
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < tmpCols; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }

    delete[] array;
}

template <typename T> void foo(T** arr, const int row, const int col)
{
    int tmpCol;
    if (col % 2 == 1)
    {
        tmpCol = col / 2 + 1;
    }
    else
    {
        tmpCol = col / 2;
    }

    T** tmpArr = new T * [row];
    for (int i = 0; i < row; i++)
    {
        tmpArr[i] = new T[tmpCol];
    }

    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j % 2 != 1)
            {
                tmpArr[i][k] = arr[i][j];
                k++;
            }
        }
        k = 0;
    }

    delete[] arr;
    arr = new T * [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new T[tmpCol];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < tmpCol; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }

    delete[] tmpArr;
}
