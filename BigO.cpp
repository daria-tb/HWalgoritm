#include <iostream>
using namespace std;

// 1. Линейная временная сложность: большая сложность O(n)
/* Линейная временная сложность означает, 
что время выполнения алгоритма линейно растет с размером входных данных.

Например, рассмотрим алгоритм, который просматривает массив, 
чтобы найти определенный элемент : */
bool findElement(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}
/* /usr/lib/x86_64-linux-gnu/crt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status */

/* 2. Логарифмическая временная сложность: большая сложность O(log n)
Логарифмическая временная сложность означает, 
что время выполнения алгоритма пропорционально логарифму размера входных данных.

Например, алгоритм бинарного поиска имеет логарифмическую временную сложность: */
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
/* /usr/lib/x86_64-linux-gnu/crt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status */
// Квадратична складність O(n^2)
void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}
/* 3. Квадратическая временная сложность: большая сложность O(n^2 )
Квадратичная временная сложность означает, 
что время выполнения алгоритма пропорционально квадрату размера входных данных.

Например, простой алгоритм пузырьковой сортировки имеет квадратичную временную сложность: */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/* 4. Кубическая сложность времени: большая сложность O(n^3 )

Кубическая сложность времени означает, 
что время выполнения алгоритма пропорционально кубу размера входных данных.

Например, наивный алгоритм умножения матриц имеет кубическую временную сложность: */
void multiply(int mat1[][3], int mat2[][3], int res[][3], int N)
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}
/* 5. Полиномиальная сложность времени: большая сложность O(n^k )

Полиномиальная временная сложность относится к временной сложности алгоритма, 
которая может быть выражена как полиномиальная функция входного размера n . 
В нотации Big O алгоритм имеет полиномиальную временную сложность, 
если его временная сложность равна O(n^k ) , где k — константа, представляющая степень полинома.

Алгоритмы с полиномиальной сложностью времени обычно считаются эффективными, 
поскольку время выполнения растет с разумной скоростью по мере увеличения размера входных данных. 
Распространенными примерами алгоритмов с полиномиальной сложностью времени 
являются линейная сложность времени O(n) , 
квадратичная сложность времени O(n^2 ) и кубическая сложность времени O(n^3 ) . */

/* 6. Экспоненциальная временная сложность: большая сложность O(2^n )
Экспоненциальная временная сложность означает, 
что время выполнения алгоритма удваивается с каждым добавлением входного набора данных.

Например, задача генерации всех подмножеств множества имеет экспоненциальную временную сложность: */
void generateSubsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i & (1 << j)) 
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

/* 7. Факториальная временная сложность: большая сложность O(n!)
Факториальная временная сложность означает, 
что время выполнения алгоритма растет факториально с размером входных данных. 
Это часто наблюдается в алгоритмах, которые генерируют все перестановки набора данных.

Вот пример алгоритма факториальной временной сложности, который генерирует все перестановки массива: */

void permute(int* a, int l, int r)
{
    if (l == r) 
    {
        for (int i = 0; i <= r; i++) 
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (int i = l; i <= r; i++) 
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]); // backtrack
        }
    }
}

int main()
{
    // Пример для функции findElement
    int arr[] = {1, 2, 3, 4, 5};
    int key = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findElement(arr, n, key)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    // Пример для функции binarySearch
    int sortedArr[] = {1, 3, 5, 7, 9};
    int x = 7;
    int result = binarySearch(sortedArr, 0, 4, x);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    // Пример для функции bubbleSort
    int unsortedArr[] = {64, 34, 25, 12, 22, 11, 90};
    int arrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    bubbleSort(unsortedArr, arrSize);
    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << unsortedArr[i] << " ";
    }
    cout << endl;

    // Пример для функции multiply (умножение матриц)
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMat[3][3];
    multiply(mat1, mat2, resultMat, 3);
    cout << "Matrix multiplication result:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << resultMat[i][j] << " ";
        }
        cout << endl;
    }

    // Пример для функции generateSubsets
    int set[] = {1, 2, 3};
    cout << "Subsets of the set: ";
    generateSubsets(set, 3);

    // Пример для функции permute (перестановки массива)
    int arrPerm[] = {1, 2, 3};
    cout << "Permutations of the array: ";
    permute(arrPerm, 0, 2);

    return 0;
}

//findElement — ищет элемент в массиве за время O(n).
//binarySearch — выполняет бинарный поиск в отсортированном массиве за время O(log n).
//bubbleSort — сортирует массив методом пузырька с временной сложностью O(n^2).
//multiply — умножает две матрицы размером 3x3, сложность O(n^3).
//generateSubsets — генерирует все подмножества множества с экспоненциальной сложностью O(2^n).
//permute — генерирует все перестановки массива с факториальной сложностью O(n!).