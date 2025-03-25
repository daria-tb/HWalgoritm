#include <iostream> //швидке сортування
#include <cstdlib>
#include <ctime>
/* 1. Взяти центральний елемент

2. В циклі найти елемент справа від центрального, який менший за нього

3. В циклі найти елемент зліва від центрального, який більший за нього

4. Поміняти місцями найдені значення, якщо їх індекси не перетнулись.

5. Виконати дії 2-4 поки індекси не перетнулись.

6. Рекурсивно виконати дії 1-5 для лівої частини масиву, якщо правий індекс не дійшов до початку

7. Рекурсивно виконати дії 1-5 для правої частини масиву, якщо лівий індекс не дійшов до кінця */
using namespace std;

template <typename T>
void QuickSort(T arr[], int first, int last)
{
    if (first >= last) return;

    T middle = arr[(first + last) / 2];
    int i = first, j = last;

    while (i <= j) 
    {
        while (arr[i] < middle) i++;
        while (arr[j] > middle) j--;

        if (i <= j) 
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (first < j) QuickSort(arr, first, j); // Виправлена рекурсія
    if (i < last) QuickSort(arr, i, last);   // Виправлена рекурсія
}

template <typename T>
void Initialize(T arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 100;
    }
}

template <typename T>
void Show(const T arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int SIZE1 = 10, SIZE2 = 20;
    int arr1[SIZE1];
    long arr2[SIZE2];

    Initialize(arr1, SIZE1);
    Initialize(arr2, SIZE2);

    cout << "arr1 before sorting: ";
    Show(arr1, SIZE1);

    cout << "arr2 before sorting: ";
    Show(arr2, SIZE2);

    QuickSort(arr1, 0, SIZE1 - 1);
    QuickSort(arr2, 0, SIZE2 - 1);

    cout << "arr1 after sorting: ";
    Show(arr1, SIZE1);

    cout << "arr2 after sorting: ";
    Show(arr2, SIZE2);

    return 0;
}
