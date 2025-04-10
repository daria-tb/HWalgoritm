#pragma once

#include <initializer_list>
#include <functional>

template <typename T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void DoForNode(const Node* node, std::function<void(const T&)> function) const;
    void RemoveSubTree(Node* node);
    Node* Delete(Node* node, const T& value);
    Node* FindMinimum(Node* node);
    size_t Size(const Node* node) const;
    void CopyTree(Node*& tree1, Node* const& tree2);

public:
    BinaryTree() = default;
    BinaryTree(std::initializer_list<T> initList);
    BinaryTree(const BinaryTree& other);
    BinaryTree(BinaryTree&& other) noexcept;
    ~BinaryTree();

    BinaryTree& operator=(const BinaryTree& other);
    BinaryTree& operator=(BinaryTree&& other) noexcept;

    void DoForAllElements(std::function<void(const T&)> function) const;
    bool Insert(const T& value);
    void Clear();
    void Delete(const T& value);
    const T* Find(const T& value) const;
    bool IsEmpty() const;
    size_t Size() const;

    class ConstIterator 
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = const T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        ConstIterator(Node* current, Node* root) : current_(current), root_(root) {}

        reference operator*() const { return current_->data; }
        pointer operator->() const { return &(operator*()); }

        ConstIterator& operator++() 
        {
            if (current_->right) 
            {
                current_ = FindMinimum(current_->right);
            } 
            else 
            {
                Node* parent = nullptr;
                Node* temp = root_;
                while (temp && temp != current_) 
                {
                    parent = temp;
                    if (current_->data < temp->data) 
                        temp = temp->left;
                    else 
                        temp = temp->right;
                }
                if (parent && current_->data < parent->data) 
                    current_ = parent;
                else 
                    current_ = nullptr;
            }
            return *this;
        }

        ConstIterator operator++(int) 
        {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ConstIterator& other) const { return current_ == other.current_; }
        bool operator!=(const ConstIterator& other) const { return !(*this == other); }

    private:
        Node* current_;
        Node* root_;
        static Node* FindMinimum(Node* node);
    };

    ConstIterator Begin() const 
    {
        Node* current = root;
        while (current && current->left) 
        {
            current = current->left;
        }
        return ConstIterator(current, root);
    }

    ConstIterator End() const 
    {
        return ConstIterator(nullptr, root);
    }
};

template <typename T>
void BinaryTree<T>::DoForNode(const Node* node, std::function<void(const T&)> function) const
{
    if (node != nullptr)
    {
        DoForNode(node->left, function);
        function(node->data);
        DoForNode(node->right, function);
    }
}

template <typename T>
void BinaryTree<T>::RemoveSubTree(Node* node)
{
    if (node != nullptr)
    {
        RemoveSubTree(node->left);
        RemoveSubTree(node->right);
        delete node;
    }
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::Delete(Node* node, const T& value)
{
    if (node == nullptr)
        return nullptr;

    if (value < node->data)
        node->left = Delete(node->left, value);
    else if (value > node->data)
        node->right = Delete(node->right, value);
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            node = temp;
        }
        else
        {
            Node* temp = FindMinimum(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
    }
    return node;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::FindMinimum(Node* node)
{
    Node* current = node;
    while (current != nullptr && current->left != nullptr)
        current = current->left;
    return current;
}

template <typename T>
size_t BinaryTree<T>::Size(const Node* node) const
{
    return node == nullptr ? 0 : Size(node->left) + 1 + Size(node->right);
}

template <typename T>
void BinaryTree<T>::CopyTree(Node*& tree1, Node* const& tree2)
{
    if (tree2 == nullptr)
        return;

    tree1 = new Node(tree2->data);
    CopyTree(tree1->left, tree2->left);
    CopyTree(tree1->right, tree2->right);
}

template <typename T>
BinaryTree<T>::BinaryTree(std::initializer_list<T> initList)
{
    for (const T& value : initList)
        Insert(value);
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) : root(nullptr)
{
    CopyTree(this->root, other.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept : root(other.root)
{
    other.root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    RemoveSubTree(root);
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other)
{
    if (this != &other)
    {
        RemoveSubTree(root);
        root = nullptr;
        CopyTree(root, other.root);
    }
    return *this;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) noexcept
{
    if (this != &other)
    {
        RemoveSubTree(root);
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
void BinaryTree<T>::DoForAllElements(std::function<void(const T&)> function) const
{
    DoForNode(root, function);
}

template <typename T>
bool BinaryTree<T>::Insert(const T& value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return true;
    }

    Node* current = root;
    while (current != nullptr)
    {
        if (value == current->data)
        {
            return false;
        }
        else if (value < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = new Node(value);
                return true;
            }
            current = current->left;
        }
        else
        {
            if (current->right == nullptr)
            {
                current->right = new Node(value);
                return true;
            }
            current = current->right;
        }
    }
    return false;
}

template <typename T>
void BinaryTree<T>::Clear()
{
    RemoveSubTree(root);
    root = nullptr;
}

template <typename T>
void BinaryTree<T>::Delete(const T& value)
{
    root = Delete(root, value);
}

template <typename T>
const T* BinaryTree<T>::Find(const T& value) const
{
    const Node* current = root;
    while (current != nullptr)
    {
        if (value > current->data)
            current = current->right;
        else if (value < current->data)
            current = current->left;
        else
            return &current->data;
    }
    return nullptr;
}

template <typename T>
bool BinaryTree<T>::IsEmpty() const
{
    return root == nullptr;
}

template <typename T>
size_t BinaryTree<T>::Size() const
{
    return Size(root);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::ConstIterator::FindMinimum(Node* node) 
{
    Node* current = node;
    while (current && current->left) 
    {
        current = current->left;
    }
    return current;
}
