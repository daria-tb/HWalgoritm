//Сортування вставками
#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>  
void InsertionSort(T arr[], int size);

int main() 
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);
    Show(arr, SIZE);

    InsertionSort(arr, SIZE); 
    Show(arr, SIZE);

    return 0;
}

void Initialize(int arr[], int size) 
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 100;
    }
}

void Show(const int arr[], int size) 
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>  
void InsertionSort(T arr[], int size)  
{  
    for (int i = 1; i < size; i++)  
    {  
        int key = arr[i];  

        int j;  
        for (j = i - 1; j >= 0 && arr[j] > key; j--)  
            arr[j + 1] = arr[j];  

        arr[j + 1] = key;  
    }  
}