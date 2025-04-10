
/* // Конструктори класу std::map:
// 1. map()
//    - Можливо реалізувати: Створення порожнього контейнера map з використанням компаратора та алокатора за замовчуванням.

// 2. map(const map& other)
//    - Можливо реалізувати: Створення копії іншого контейнера map. Потрібно скопіювати всі елементи та налаштування (компаратор, алокатор).

// 3. map(map&& other)
//    - Можливо реалізувати: Створення контейнера map шляхом переміщення вмісту іншого контейнера map. Це ефективніше, ніж копіювання.

// 4. map(const Predicate& predicate)
//    - Можливо реалізувати: Створення порожнього контейнера map з використанням заданого компаратора (`Predicate`) та алокатора за замовчуванням.

// 5. map(const Allocator& allocator)
//    - Можливо реалізувати: Створення порожнього контейнера map з використанням компаратора за замовчуванням та заданого алокатора (`Allocator`).

// 6. map(const Predicate& predicate, const Allocator& allocator)
//    - Можливо реалізувати: Створення порожнього контейнера map з використанням заданого компаратора (`Predicate`) та алокатора (`Allocator`).

// 7. map(const map& other, const Allocator& allocator)
//    - Можливо реалізувати: Створення копії іншого контейнера map з використанням заданого алокатора (`Allocator`). Компаратор успадковується від `other`.

// 8. map(map&& other, const Allocator& allocator)
//    - Можливо реалізувати: Створення контейнера map шляхом переміщення вмісту іншого контейнера map з використанням заданого алокатора (`Allocator`). Компаратор успадковується від `other`.

// 9. map(Iterator first, Iterator end)
//    - Можливо реалізувати: Створення контейнера map з елементів в діапазоні `[first, end)`. Використовується компаратор та алокатор за замовчуванням.

// 10. map(Iterator first, Iterator end, const Predicate& predicate)
//    - Можливо реалізувати: Створення контейнера map з елементів в діапазоні `[first, end)` з використанням заданого компаратора (`Predicate`) та алокатора за замовчуванням.

// 11. map(Iterator first, Iterator end, const Allocator& allocator)
//    - Можливо реалізувати: Створення контейнера map з елементів в діапазоні `[first, end)` з використанням компаратора за замовчуванням та заданого алокатора (`Allocator`).

// 12. map(Iterator first, Iterator end, const Predicate& predicate, const Allocator& allocator)
//    - Можливо реалізувати: Створення контейнера map з елементів в діапазоні `[first, end)` з використанням заданого компаратора (`Predicate`) та алокатора (`Allocator`).

// 13. map(std::initializer_list<value_type> list)
//    - Можливо реалізувати: Створення контейнера map зі списку ініціалізації. Використовується компаратор та алокатор за замовчуванням.

// 14. map(std::initializer_list<value_type> list, const Predicate& predicate)
//    - Можливо реалізувати: Створення контейнера map зі списку ініціалізації з використанням заданого компаратора (`Predicate`) та алокатора за замовчуванням.

// 15. map(std::initializer_list<value_type> list, const Allocator& allocator)
//    - Можливо реалізувати: Створення контейнера map зі списку ініціалізації з використанням компаратора за замовчуванням та заданого алокатора (`Allocator`).

// 16. map(std::initializer_list<value_type> list, const Predicate& predicate, const Allocator& allocator)
//    - Можливо реалізувати: Створення контейнера map зі списку ініціалізації з використанням заданого компаратора (`Predicate`) та алокатора (`Allocator`).

// Конструктори класу std::multimap:
// (Аналогічно до std::map, всі конструктори можливо реалізувати з тією ж логікою, але без унікальності ключів)
// 1. multimap()
// 2. multimap(const multimap& other)
// 3. multimap(multimap&& other)
// 4. multimap(const Predicate& predicate)
// 5. multimap (const Allocator& allocator)
// 6. multimap(const Predicate& predicate, const Allocator& allocator)
// 7. multimap(const multimap& other, const Allocator& allocator)
// 8. multimap(multimap&& other, const Allocator& allocator)
// 9. multimap (Iterator first, Iterator end)
// 10. multimap(Iterator first, Iterator end, const Predicate& predicate)
// 11. multimap(Iterator first, Iterator end, const Allocator& allocator)
// 12. multimap(Iterator first, Iterator end, const Predicate& predicate, const Allocator& allocator)
// 13. multimap(std::initializer_list<value_type> list)
// 14. multimap(std::initializer_list<value_type> list, const Predicate& predicate)
// 15. multimap(std::initializer_list<value_type> list, const Allocator& allocator)
// 16. multimap(std::initializer_list<value_type> list, const Predicate& predicate, const Allocator& allocator)

// Деструктори:
// - За замовчуванням при додаванні нових елементів в любий контейнер, пам'ять під них виділяється на купі
//   завдяки алокатору за замовчуванням std::allocator. А в деструкторі цих контейнерів ця пам'ять автоматично
//   звільняється. Контейнери map і multimap не виключення.
// - Реалізація: Деструктор зазвичай не потребує явного визначення, оскільки стандартний алокатор (`std::allocator`)
//   автоматично звільняє всю виділену пам'ять для елементів контейнера при знищенні об'єкта.

// Методи:
std::cout << "Methods\n";

// 1. Allocator get_allocator() const noexcept
//    - Опис: повертає алокатор, який прив'язаний до контейнера.
//    - Можливо реалізувати: Потрібно зберігати об'єкт алокатора як член класу і повертати його.

// 2. Value& at(const Key& key)
//    - Опис: повертає посилання на значення за указаним ключем. Якщо такого ключа не існує кидає виключення std::out_of_range.
//    - Можливо реалізувати: Потрібно знайти елемент з заданим ключем. Якщо знайдено, повернути посилання на його значення.
//      Якщо не знайдено, згенерувати виключення `std::out_of_range`.

// 3. Iterator begin() noexcept
//    - Опис: повертає ітератор/константний ітератор на перший елемент контейнера.
//    - Можливо реалізувати: Потрібно реалізувати власний клас ітератора, який вказує на перший елемент внутрішньої структури даних, що зберігає елементи (наприклад, на початок збалансованого дерева).

// 4. Iterator end() noexcept
//    - Опис: повертає ітератор/константний ітератор на кінець контейнера (елемент, що йде після останнього).
//    - Можливо реалізувати: Потрібно реалізувати власний клас ітератора, який вказує на фіктивний елемент, що сигналізує про кінець контейнера.

// 5. ConstIterator cbegin() const noexcept
//    - Опис: повертає константний ітератор на перший елемент контейнера.
//    - Можливо реалізувати: Аналогічно `begin()`, але повертає ітератор, який не дозволяє змінювати елементи.

// 6. ConstIterator cend() const noexcept
//    - Опис: повертає константний ітератор на кінець контейнера.
//    - Можливо реалізувати: Аналогічно `end()`, але повертає константний ітератор.

// 7. ReverseIterator rbegin() noexcept
//    - Опис: повертає ітератор/константний ітератор на обернений перший елемент контейнера (фактично останній елемент).
//    - Можливо реалізувати: Потрібно реалізувати обернений ітератор, який починає з кінця внутрішньої структури даних.

// 8. ReverseIterator rend() noexcept
//    - Опис: повертає ітератор/константний ітератор на обернений кінець контейнера (елемент, що йде перед першим).
//    - Можливо реалізувати: Потрібно реалізувати обернений ітератор, який закінчується перед початком внутрішньої структури даних.

// 9. ConstReverseIterator crbegin() const noexcept
//    - Опис: повертає константний ітератор на обернений перший елемент контейнера.
//    - Можливо реалізувати: Аналогічно `rbegin()`, але повертає константний обернений ітератор.

// 10. ConstReverseIterator crend() const noexcept
//     - Опис: повертає константний ітератор на обернений кінець контейнера.
//     - Можливо реалізувати: Аналогічно `rend()`, але повертає константний обернений ітератор.

// 11. bool empty() const noexcept
//     - Опис: повертає true, якщо контейнер пустий.
//     - Можливо реалізувати: Потрібно перевірити, чи містить внутрішня структура даних хоча б один елемент.

// 12. size_t size() const noexcept
//     - Опис: повертає кількість елементів контейнера.
//     - Можливо реалізувати: Потрібно зберігати лічильник кількості елементів та повертати його.

// 13. size_t max_size() const noexcept
//     - Опис: повертає максимально допустимий розмір елементів у контейнері.
//     - Можливо реалізувати: Це залежить від доступної пам'яті та реалізації контейнера. Зазвичай повертається деяке велике значення.

// 14. void clear() noexcept
//     - Опис: очищає контейнер від елементів.
//     - Можливо реалізувати: Потрібно видалити всі елементи з внутрішньої структури даних та скинути лічильник розміру.

// 15. std::pair<iterator, bool> insert(const std::pair<Key, Value>& value)
//     - Опис: вставляє новий елемент в контейнер. Для `std::map` повертає ітератор на вставлений (або вже існуючий) елемент та булеве значення, що вказує, чи була вставка успішною. Для `std::multimap` булеве значення завжди true.
//     - Можливо реалізувати: Потрібно знайти правильне місце для вставки у внутрішній структурі даних (з урахуванням компаратора) та вставити новий елемент. Для `std::map` також потрібно перевірити унікальність ключа.

// 16. template <typename... Args>
//     std::pair<iterator, bool> emplace (Args&&... args)
//     - Опис: конструює новий елемент безпосередньо в контейнері.
//     - Можливо реалізувати: Аналогічно `insert()`, але елемент конструюється на місці, що може бути ефективнішим.

// 17. template <typename... Args>
//     iterator emplace_hint(const_iterator hint, Args&&... args)
//     - Опис: конструює новий елемент в контейнері, використовуючи ітератор як підказку того, біля якого місця вставити елемент.
//     - Можливо реалізувати: Аналогічно `emplace()`, але з підказкою для оптимізації вставки.

// 18. iterator erase (iterator position)
//     - Опис: видаляє елемент за вказаним ітератором.
//     - Можливо реалізувати: Потрібно знайти елемент за ітератором та видалити його з внутрішньої структури даних, оновивши лічильник розміру.

// 19. size_t erase(const Key& key);
//     - Опис: видаляє всі елементи з заданим ключем. Повертає кількість видалених елементів.
//     - Можливо реалізувати: Потрібно знайти всі елементи з заданим ключем та видалити їх.

// 20. void swap(std::map& other)
//     - Опис: міняє вміст двох контейнерів місцями.
//     - Можливо реалізувати: Потрібно обміняти внутрішні структури даних, алокатори та компаратори двох контейнерів.

// 21. size_t count(const Key& key) const
//     - Опис: рахує кількість значень, які прив'язані до конкретного ключа. В контейнері `std::map` завжди повертає або 0 (значить немає такого ключа), або 1 (значить ключ існує). В класі `std::multimap` повертає 0 (значить немає такого ключа) або любе число значень, які прив'язані до цього ключа.
//     - Можливо реалізувати: Потрібно знайти всі елементи з заданим ключем та повернути їх кількість.

// 22. iterator find(const Key& key)
//     - Опис: шукає елемент по заданому ключу. Якщо елемент існує, то повертає ітератор на нього. Інакше повертає ітератор `end()`.
//     - Можливо реалізувати: Потрібно знайти елемент з заданим ключем у внутрішній структурі даних.

// 23. iterator lower_bound(const Key& key)
//     - Опис: повертає ітератор, який указує на ПЕРШИЙ елемент, який НЕ МЕНШИЙ за елемент за заданим ключем. В контейнері `std::map` має мало сенсу, так як повертає або ітератор на елемент по ключу, або `end()`. Використовується в основному в контейнері `std::multimap` для того, щоб отримати початковий елемент діапазону елементів, які прив'язані до указаного ключа.
//     - Можливо реалізувати: Потрібно знайти першу позицію у внутрішній структурі даних, де можна вставити елемент з заданим ключем без порушення порядку.


// 24. iterator upper_bound(const Key& key)
//     - Опис: повертає ітератор, який указує на ПЕРШИЙ елемент, який БІЛЬШИЙ за елемент за заданим ключем. В контейнері `std::map` має мало сенсу, так як повертає або ітератор на елемент, який є наступним до того, який указаний по ключу, або `end()`. Використовується в основному в контейнері `std::multimap` для того, щоб отримати елемент, який свідчить про кінець елементів, які прив'язані до указаного ключа.
//     - Можливо реалізувати: Потрібно знайти першу позицію у внутрішній структурі даних, де елемент з заданим ключем вже не може бути вставлений без порушення порядку (тобто перший елемент, більший за заданий ключ).

// 25. std::pair<iterator, iterator> equal_range(const Key& key)
//     - Опис: повертає пару з двох ітераторів. Перший - це той, який повертає метод `lower_bound`. Другий - це той, який повертає метод `upper_bound`. Використовується тоді, коли треба викликати `lower_bound` і `upper_bound`. Працює швидше, чим виклик цих методів поокремо.
//     - Можливо реалізувати: Потрібно одночасно знайти нижню та верхню межі для заданого ключа, що може бути оптимізовано за одну прохід внутрішньою структурою даних.

// 26. key_compare key_comp() const
//     - Опис: повертає функтор, який використовується для порівнювання ключів (завдяки якому сортується контейнер).
 */
#include <iostream>
#include <map>
#include <string>

// Клас, який демонструє роботу з std::map та std::multimap для зберігання номерів телефонів
class PhoneDirectory 
{
public:
    using FullName = std::string;
    using PhoneNumber = std::string;
    using PhoneMap = std::map<FullName, PhoneNumber>;
    using PhoneMultiMap = std::multimap<FullName, PhoneNumber>;

private:
    PhoneMap phoneBook;
    PhoneMultiMap duplicatePhoneBook;

public:
    PhoneDirectory() 
    {
        std::cout << "Конструктор PhoneDirectory\n";
    }

    PhoneDirectory(const PhoneDirectory& other)
        : phoneBook(other.phoneBook), duplicatePhoneBook(other.duplicatePhoneBook) 
        {
        std::cout << "Копіюючий конструктор\n";
    }

    PhoneDirectory& operator=(const PhoneDirectory& other) 
    {
        if (this != &other) 
        {
            phoneBook = other.phoneBook;
            duplicatePhoneBook = other.duplicatePhoneBook;
        }
        return *this;
    }

    ~PhoneDirectory() 
    {
        std::cout << "Деструктор PhoneDirectory\n";
    }

    // Додавання людини з унікальним іменем до map
    void addPerson(const FullName& name, const PhoneNumber& phone) 
    {
        phoneBook[name] = phone;  // перезапише номер, якщо ім’я вже є
    }

    // Додавання людини з можливими дублями імені до multimap
    void addPersonMultiple(const FullName& name, const PhoneNumber& phone) 
    {
        duplicatePhoneBook.insert({name, phone});  // дозволяє дублікати
    }

    // Отримання номера телефону за ім'ям
    PhoneNumber getPhoneNumber(const FullName& name) 
    {
        return phoneBook[name]; // створить пустий запис, якщо не знайде
    }

    // Виведення всіх записів з map
    void printPhoneBook() const 
    {
        std::cout << "Map (унікальні імена):\n";
        for (const auto& pair : phoneBook) 
        {
            std::cout << "Ім'я: " << pair.first << " | Телефон: " << pair.second << '\n';
        }
    }

    // Виведення всіх записів з multimap
    void printDuplicatePhoneBook() const 
    {
        std::cout << "Multimap (можливі дублікати імен):\n";
        for (const auto& pair : duplicatePhoneBook) 
        {
            std::cout << "Ім'я: " << pair.first << " | Телефон: " << pair.second << '\n';
        }
    }
};

int main() 
{
    PhoneDirectory directory;

    // Додавання до map
    directory.addPerson("Іван Петренко", "+380501112233");
    directory.addPerson("Марія Іваненко", "+380671234567");
    directory.addPerson("Іван Петренко", "+380931234567"); // перезаписує попередній

    // Додавання до multimap
    directory.addPersonMultiple("Олена Коваль", "+380501111111");
    directory.addPersonMultiple("Олена Коваль", "+380502222222"); // обидва залишаються

    // Вивід
    directory.printPhoneBook();
    directory.printDuplicatePhoneBook();

    // Отримання номера за ім’ям
    std::cout << "Телефон Івана Петренка: " << directory.getPhoneNumber("Іван Петренко") << '\n';

    return 0;
}