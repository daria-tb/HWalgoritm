#include <iostream>
#include <string>
#include "BinaryTree.h"

template <typename T>
void ShowValue(const T& value)
{
    std::cout << value << " ";
}

template <typename T>
void Show(const BinaryTree<T>& tree)
{
    std::cout << "Tree elements: ";
    tree.DoForAllElements(ShowValue<T>);
    std::cout << std::endl;
}

int main()
{
    // Constructors:
    std::cout << "--- Constructors ---\n";
    BinaryTree<int> tree1;
    Show(tree1);

    BinaryTree<int> tree2{ 10, 1, 9, 2, 8, 3 };
    Show(tree2);

    BinaryTree<int> tree3(tree2);
    Show(tree3);

    BinaryTree<int> tree4(std::move(tree3));
    Show(tree4);
    Show(tree3);

    {
        std::cout << "\n--- Operators = ---\n";
        BinaryTree<int> tree1{ 1, 2, 3, 4, 5 };
        BinaryTree<int> tree2{ 10, 20, 30 };
        Show(tree1);
        Show(tree2);

        tree2 = tree1;
        Show(tree1);
        Show(tree2);

        BinaryTree<int> tree3{ 11, 22, 33, 44, 55 };
        BinaryTree<int> tree4{ 100, 200, 300 };
        Show(tree3);
        Show(tree4);

        tree4 = std::move(tree3);
        Show(tree3);
        Show(tree4);
    }

    std::cout << "\n--- Methods ---\n";

    BinaryTree<double> treeDbl{ 1.1, 2.2, 3.3, 4.4, 5.5 };

    if (!treeDbl.IsEmpty())
        std::cout << "Tree isn't empty.\n";

    std::cout << "Size of tree = " << treeDbl.Size() << std::endl;

    treeDbl.Clear();

    if (treeDbl.IsEmpty()) 
    {
        std::cout << "Tree is empty now.\n";

        // 🔧 Тепер вставляємо double у дерево double
        treeDbl.Insert(10.5);
        treeDbl.Insert(2.8);
        treeDbl.Insert(1.2);
        treeDbl.Insert(3.6);
        treeDbl.Insert(7.8);

        std::cout << "Tree elements: ";
        treeDbl.DoForAllElements(ShowValue<double>);
        std::cout << std::endl;

        const double* foundValue = treeDbl.Find(2.8);
        if (foundValue != nullptr)
            std::cout << "Tree has " << *foundValue << std::endl;

        treeDbl.Delete(32.1); // value not in tree
        treeDbl.Delete(2.8);

        std::cout << "Tree elements: ";
        treeDbl.DoForAllElements(ShowValue<double>);
        std::cout << std::endl;

        // Підсумовування:
        double sum = 0.0;
        for (auto iter = treeDbl.Begin(); iter != treeDbl.End(); ++iter)
            sum += *iter;
        std::cout << "Sum = " << sum << std::endl;
    }

    return 0;
}
