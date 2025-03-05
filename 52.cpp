//Сортування бульбашкою
#include <iostream>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
void BubbleSort(T arr[], int size);

int main() 
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);
    Show(arr, SIZE);

    // Сортування 
/*     for (int i = 0; i < SIZE - 1; i++) 
        for (int j = SIZE - 1; j > i; j--) 
            if (arr[j] > arr[j - 1]) //по спаданню
                std::swap(arr[j], arr[j - 1]); */

    BubbleSort(arr, SIZE);

    Show(arr, SIZE);

    return 0;
}

void Initialize(int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % 100;
    }
}

void Show(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void BubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
        for (int j = size - 1; j > i; j--) 
            if (arr[j] < arr[j - 1])  //по зростанню
                std::swap(arr[j], arr[j - 1]);
}