/* 
Що таке асоціативний контейнер?
Огляд файлів main.cpp і Person.h
Схема роботи класу set
Параметри шаблону set
Псевдоніми-члени set
Конструктори set
Деструктор set
Методи
Функції
Приклад використання set
О-нотація set
Схема роботи класу multiset
Різниця в методах
О-нотація multiset 
*/
#include <iostream>
#include <set>      // Заголовок для std::set та std::multiset
#include <string>   // Заголовок для std::string
#include <memory>   // Заголовок для std::unique_ptr

// Клас Person для демонстрації використання set з власним класом
class Person 
{
public:
    // Конструктор за замовчуванням
    Person() : age(1), name("Unknown") 
    {
        std::cout << "Default constructor\n";
    }
    // Конструктор з параметрами
    Person(int age, const std::string& name) : age(age), name(name) 
    {
        std::cout << "2param constructor\n";
    }
    // Конструктор копіювання
    Person(const Person& other) : age(other.age), name(other.name) 
    {
        std::cout << "Copy constructor\n";
    }
    // Конструктор переміщення
    Person(Person&& other) noexcept : age(other.age), name(std::move(other.name)) 
    {
        std::cout << "Move constructor\n";
    }
    // Оператор присвоєння копіюванням
    Person& operator=(const Person& other) 
    {
        std::cout << "copy operator=\n";
        age = other.age;
        name = other.name;
        return *this;
    }
    // Оператор присвоєння переміщенням
    Person& operator=(Person&& other) noexcept 
    {
        std::cout << "move operator=\n";
        age = other.age;
        name = std::move(other.name);
        return *this;
    }
    // Деструктор
    ~Person() 
    {
        std::cout << "Destructor\n";
    }
    // Метод для виведення інформації про особу
    void ShowInfo() const 
    {
        std::cout << "(age = " << age << ", name = " << name << ")\n";
    }
    // Методи для отримання віку та імені
    int GetAge() const { return age; }
    std::string GetName() const { return name; }
    // Оператор порівняння для використання в std::set
    bool operator<(const Person& other) const 
    {
        return age < other.age;
    }
private:
    int age;
    std::string name;
};

// Функція для виведення елементів set
void ShowSet(const std::set<int>& mySet) 
{
    std::cout << "Set elements: ";
    for (const auto& element : mySet) 
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Функція для виведення елементів multiset
void ShowMultiset(const std::multiset<int>& myMultiset) 
{
    std::cout << "Multiset elements: ";
    for (const auto& element : myMultiset) 
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Функція для демонстрації конструкторів set
void Constructors() 
{
    std::cout << "-- CONSTRUCTORS -----\n";
    // 1. Конструктор за замовчуванням
    std::set<int> set1;
    ShowSet(set1);
    // 2. Конструктор з ініціалізацією списком
    std::set<int> set2({ 5, 2, 8 });
    ShowSet(set2);
    // 3. Конструктор копіювання
    std::set<int> set3(set1);
    ShowSet(set3);
    // 4. Конструктор переміщення
    std::set<int> set4(std::move(set2));
    ShowSet(set4);
    // 5. Конструктор з діапазоном ітераторів
    std::set<int> set5({ 1, 2, 3, 4, 5 });
    ShowSet(set5);
}

// Функція для демонстрації деструктора set
void Destructor() 
{
    std::cout << "-- DESTRUCTOR -----\n";
    std::set<Person> setPersons;
    setPersons.insert(Person(25, "John"));
    setPersons.insert(Person(30, "Alice"));
    // Деструктори Person будуть викликані автоматично при виході з області видимості
}

// Функція для демонстрації методів set
void Methods() 
{
    std::cout << "-- METHODS -----\n";
    std::set<int> mySet{ 5, 2, 8, 1, 9 };
    ShowSet(mySet);
    // 1. insert
    mySet.insert(3);
    ShowSet(mySet);
    // 2. erase
    mySet.erase(2);
    ShowSet(mySet);
    // 3. find
    auto it = mySet.find(8);
    if (it != mySet.end()) 
    {
        std::cout << "Found: " << *it << std::endl;
    }
    // 4. count
    std::cout << "Count of 5: " << mySet.count(5) << std::endl;
    // 5. size
    std::cout << "Size: " << mySet.size() << std::endl;
    // 6. empty
    std::cout << "Empty: " << mySet.empty() << std::endl;
    // 7. clear
    mySet.clear();
    ShowSet(mySet);
}

// Функція для демонстрації глобальних операторів та функцій set
void GlobalOperatorsAndFunctions() 
{
    std::cout << "-- GLOBAL OPERATORS AND FUNCTIONS -----\n";
    std::set<int> set1{ 1, 2, 3 };
    std::set<int> set2{ 3, 4, 5 };
    std::swap(set1, set2);
    ShowSet(set1);
    ShowSet(set2);
}

// Функція для демонстрації псевдонімів контейнера set
void ContainerAliases() 
{
    std::cout << "-- CONTAINER ALIASES -----\n";
    // Отримання типу значення set
    std::set<int>::value_type value = 10;
    // Отримання типу константного посилання
    std::set<int>::const_reference ref = value;
    // Оголошення ітератора
    std::set<int>::iterator it;
    std::cout << "Value: " << value << ", Ref: " << ref << std::endl;
}

// Функція для демонстрації використання set з власним класом
void OwnClassInSet() 
{
    std::cout << "-- OWN CLASS IN SET -----\n";
    // Створення set з об'єктами Person
    std::set<Person> personSet;
    personSet.insert(Person(25, "John"));
    personSet.insert(Person(30, "Alice"));
    for (const auto& person : personSet) 
    {
        person.ShowInfo();
    }
}

// Функція для демонстрації використання set з розумними вказівниками
void PointersInSet() 
{
    std::cout << "-- POINTERS IN SET -----\n";
    // Створення set з std::unique_ptr<Person>
    std::set<std::unique_ptr<Person>, std::function<bool(const std::unique_ptr<Person>&, const std::unique_ptr<Person>&)>> personPtrSet(
        [](const std::unique_ptr<Person>& a, const std::unique_ptr<Person>& b) {
            return a->GetAge() < b->GetAge();
        }
    );
    personPtrSet.insert(std::make_unique<Person>(25, "John"));
    personPtrSet.insert(std::make_unique<Person>(30, "Alice"));
    for (const auto& personPtr : personPtrSet) 
    {
        personPtr->ShowInfo();
    }
}

// Функція для демонстрації O-нотації set
void ONotation() 
{
    std::cout << "-- O NOTATION -----\n";
    std::cout << "Insert: O(log n)\n";
    std::cout << "Erase: O(log n)\n";
    std::cout << "Find: O(log n)\n";
}

// Функція для демонстрації методів multiset
void MultisetMethods() 
{
    std::cout << "-- MULTISET METHODS -----\n";
    std::multiset<int> myMultiset{ 5, 2, 8, 2, 9 };
    ShowMultiset(myMultiset);
    // 1. count
    std::cout << "Count of 2: " << myMultiset.count(2) << std::endl;
    // 2. equal_range
    auto range = myMultiset.equal_range(2);
    for (auto it = range.first; it != range.second; ++it) 
    {
        std::cout << "Found: " << *it << std::endl;
    }
}

// Функція для демонстрації O-нотації multiset
void MultisetONotation() 
{
    std::cout << "-- MULTISET O NOTATION -----\n";
    std::cout << "Insert: O(log n)\n";
    std::cout << "Erase: O(log n)\n";
    std::cout << "Find: O(log n)\n";
    std::cout << "Count: O(log n) + k (k = found elements)\n";
}

int main() 
{
    Constructors();
    Destructor();
    Methods();
    GlobalOperatorsAndFunctions();
    ContainerAliases();
    OwnClassInSet();
    PointersInSet();
    ONotation();
    MultisetMethods();
    MultisetONotation();
    return 0;
}
