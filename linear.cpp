#include <iostream>
//Оптимізувати алгоритм лінійного пошуку на випадок впорядкованого масиву

void LinearSearch(const int arr[], int size, int key) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == key) 
        {
            std::cout << "The array has your value!\n";
            return; //вихід з ф-ї, якщо значення знайдено
        }
        if (arr[i] > key) 
        {
            break; //якщо зустрілося більше значенн -> виходимо
        }
    }
    std::cout << "The array doesn't have your value :(\n";
}

int main() 
{
    int arr[] = {1, 3, 5, 7, 9, 11, 15};  //впорядкований масив
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    std::cout << "Enter a number to search: ";
    std::cin >> key;

    LinearSearch(arr, size, key);

    return 0;
}