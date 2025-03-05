//сортування вибірково
#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
void SelectionSort(T arr[], int size);

int main() 
{
    srand(static_cast<unsigned>(time(nullptr))); // Ініціалізація генератора випадкових чисел

    const int SIZE = 10;
    int arr[SIZE];

    const int SIZE2 = 10;
    int arr2[SIZE2];

    Initialize(arr, SIZE);
    Show(arr, SIZE);

    Initialize(arr2, SIZE2);
    Show(arr2, SIZE2);

    SelectionSort(arr, SIZE);
    SelectionSort(arr2, SIZE2);
/* std::swap(arr[0], arr[1]);

    for (int i = 0 ; i < SIZE - 1; i++)
        for (int j = i + 1 j < SIZE; j++)
            if (arr[j] < arr[i])
                std::swap(arr[j], arr[i]); */
                
    Show(arr, SIZE);
    Show(arr2, SIZE2);
    return 0;
}

void Initialize(int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 10;  // Заповнюємо масив випадковими числами від 0 до 9
    }
}

void Show(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << " ";  // Виводимо елементи масиву
    }
    std::cout << std::endl;  // Перехід на новий рядок після виведення масиву
}

//алгоритм сортування
template <typename T>
void SelectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
        for (int j = i + 1; j < size; j++) 
            if (arr[j] < arr[i])
                std::swap(arr[j], arr[i]);
}