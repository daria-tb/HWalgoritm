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
#include <set>
#include <string>
#include <memory>

class Person {
public:
    Person() : age(1), name("Unknown") { std::cout << "Default constructor\n"; }
    Person(int age, const std::string& name) : age(age), name(name) { std::cout << "2param constructor\n"; }
    Person(const Person& other) : age(other.age), name(other.name) { std::cout << "Copy constructor\n"; }
    Person(Person&& other) noexcept : age(other.age), name(std::move(other.name)) { std::cout << "Move constructor\n"; }
    Person& operator=(const Person& other) { std::cout << "copy operator=\n"; age = other.age; name = other.name; return *this; }
    Person& operator=(Person&& other) noexcept { std::cout << "move operator=\n"; age = other.age; name = std::move(other.name); return *this; }
    ~Person() { std::cout << "Destructor\n"; }
    void ShowInfo() const { std::cout << "(age = " << age << ", name = " << name << ")\n"; }
    int GetAge() const { return age; }
    std::string GetName() const { return name; }
    // Додаємо оператор порівняння
    bool operator<(const Person& other) const {
        return age < other.age;
    }
private:
    int age;
    std::string name;
};

void ShowSet(const std::set<int>& mySet) {
    std::cout << "Set elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void ShowMultiset(const std::multiset<int>& myMultiset) {
    std::cout << "Multiset elements: ";
    for (const auto& element : myMultiset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void Constructors() {
    std::cout << "-- CONSTRUCTORS -----\n";
    std::set<int> set1;
    ShowSet(set1);
    std::set<int> set2({ 5, 2, 8 }); // Використовуємо один тип set
    ShowSet(set2);
    std::set<int> set3(set1);
    ShowSet(set3);
    std::set<int> set4(std::move(set2));
    ShowSet(set4);
    std::set<int> set5({ 1, 2, 3, 4, 5 });
    ShowSet(set5);
}

void Destructor() {
    std::cout << "-- DESTRUCTOR -----\n";
    std::set<Person> setPersons;
    setPersons.insert(Person(25, "John"));
    setPersons.insert(Person(30, "Alice"));
}

void Methods() {
    std::cout << "-- METHODS -----\n";
    std::set<int> mySet{ 5, 2, 8, 1, 9 };
    ShowSet(mySet);
    mySet.insert(3);
    ShowSet(mySet);
    mySet.erase(2);
    ShowSet(mySet);
    auto it = mySet.find(8);
    if (it != mySet.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
    std::cout << "Count of 5: " << mySet.count(5) << std::endl;
    std::cout << "Size: " << mySet.size() << std::endl;
    std::cout << "Empty: " << mySet.empty() << std::endl;
    mySet.clear();
    ShowSet(mySet);
}

void GlobalOperatorsAndFunctions() {
    std::cout << "-- GLOBAL OPERATORS AND FUNCTIONS -----\n";
    std::set<int> set1{ 1, 2, 3 };
    std::set<int> set2{ 3, 4, 5 };
    std::swap(set1, set2);
    ShowSet(set1);
    ShowSet(set2);
}

void ContainerAliases() {
    std::cout << "-- CONTAINER ALIASES -----\n";
    std::set<int>::value_type value = 10;
    std::set<int>::const_reference ref = value;
    std::set<int>::iterator it; 
    std::cout << "Value: " << value << ", Ref: " << ref << std::endl;
}

void OwnClassInSet() {
    std::cout << "-- OWN CLASS IN SET -----\n";
    std::set<Person> personSet; // Використовуємо стандартний компаратор (operator<)
    personSet.insert(Person(25, "John"));
    personSet.insert(Person(30, "Alice"));
    for (const auto& person : personSet) {
        person.ShowInfo();
    }
}

void PointersInSet() {
    std::cout << "-- POINTERS IN SET -----\n";
    std::set<std::unique_ptr<Person>, std::function<bool(const std::unique_ptr<Person>&, const std::unique_ptr<Person>&)>> personPtrSet(
        [](const std::unique_ptr<Person>& a, const std::unique_ptr<Person>& b) {
            return a->GetAge() < b->GetAge();
        }
    );
    personPtrSet.insert(std::make_unique<Person>(25, "John"));
    personPtrSet.insert(std::make_unique<Person>(30, "Alice"));
    for (const auto& personPtr : personPtrSet) {
        personPtr->ShowInfo();
    }
}

void ONotation() {
    std::cout << "-- O NOTATION -----\n";
    std::cout << "Insert: O(log n)\n";
    std::cout << "Erase: O(log n)\n";
    std::cout << "Find: O(log n)\n";
}

void MultisetMethods() {
    std::cout << "-- MULTISET METHODS -----\n";
    std::multiset<int> myMultiset{ 5, 2, 8, 2, 9 };
    ShowMultiset(myMultiset);
    std::cout << "Count of 2: " << myMultiset.count(2) << std::endl;
    auto range = myMultiset.equal_range(2);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Found: " << *it << std::endl;
    }
}

void MultisetONotation() {
    std::cout << "-- MULTISET O NOTATION -----\n";
    std::cout << "Insert: O(log n)\n";
    std::cout << "Erase: O(log n)\n";
    std::cout << "Find: O(log n)\n";
    std::cout << "Count: O(log n) + k (k = found elements)\n";
}

int main() {
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