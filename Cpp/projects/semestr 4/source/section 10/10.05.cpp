#include <memory>
#include <iostream>

template <typename T>
struct Node {
    std::shared_ptr<Node> left_child = nullptr;
    std::shared_ptr<Node> right_child = nullptr;
    std::weak_ptr<Node> parent; 
    T data;
    ~Node() {
        std::cout << "Destroying node with data: " << data << std::endl;
    }
};

int main() {
    auto root = std::make_shared<Node<int>>();
    root->data = 0;

    auto n1 = std::make_shared<Node<int>>();
    n1->data = 1;
    n1->parent = root;
    root->left_child = n1;

    auto n2 = std::make_shared<Node<int>>();
    n2->data = 2;
    n2->parent = root;
    root->right_child = n2;

    auto n3 = std::make_shared<Node<int>>();
    n3->data = 3;
    n3->parent = n1;
    n1->left_child = n3;

    std::cout << "Root data: " << root->data << std::endl;

    return 0;
}


