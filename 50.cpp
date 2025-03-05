//Алгоритм це певна послідовність дій для виконання певної програми
//Найти елемент масиву
#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
bool LinearSearch(const T arr[], int size, const T key);

int main() 
{
    srand(static_cast<unsigned>(time(nullptr))); // Ініціалізація генератора випадкових чисел

    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);  // Ініціалізація масиву
    Show(arr, SIZE);        // Виведення масиву

    std::cout << "Enter value that you want to find: ";
    int value;
    std::cin >> value;

    //алгоритм лінійного пошуку але логічніше чеоез функцію
/*     for (int i = 0; i < SIZE; ++i) 
    {
    if (value == arr[i]) 
    {
        std::cout << "The array has your value!\n";
        break;
    }
    } */
    //--------------
/* bool isFound = false;

for (int i = 0; i < SIZE; ++i) 
{
    if (value == arr[i]) 
    {
        isFound = true;
        break; // Вихід з циклу після знаходження значення
    }
}

if (isFound) 
{
    std::cout << "The array has your value!\n";
} else {
    std::cout << "The array doesn't have your value :(\n";
} */

    if (LinearSearch(arr, SIZE, value)) 
    {
        std::cout << "The array has your value!\n";
    } else 
    {
        std::cout << "The array doesn't have your value :(\n";
    }
    return 0;
}

void Initialize(int arr[], int size) 
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 100;  // Заповнюємо масив випадковими числами від 0 до 99
    }
}

void Show(const int arr[], int size) 
{
    if (arr == nullptr)
        return;

    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";  // Виводимо елементи масиву
    }
    std::cout << std::endl;
}
//фунеція лінійного пошук

/* void LinearSearch(const int arr[], int size, int key) {
    bool isFound = false;

    for (int i = 0; i < size; ++i) 
    {
        if (key == arr[i]) 
        {
            isFound = true;
            break; // Вихід з циклу, якщо значення знайдено
        }
    }

    if (isFound) 
    {
        std::cout << "The array has your value!\n";
    } else {
        std::cout << "The array doesn't have your value :(\n";
    }
} */

//універсальна функ
template <typename T>
bool LinearSearch(const T arr[], int size, const T key) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (key == arr[i]) 
        {
            return true; // Повертаємо true, якщо значення знайдено
        }
    }
    return false; // Повертаємо false, якщо значення не знайдено
}