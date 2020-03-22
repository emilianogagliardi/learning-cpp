#include "print.h"
#include "fold.h"

int main()
{
    // print
    print(1, 2, 1, "ciao", 1.2, "sasso");
    std::cout << "\n";
    print2('a', 1, 2.3, "b", true);
    print3('a', 1, 2.3, "b", true);
    std::cout << "\n";
    // sum with fold
    std::cout << sum_foldl(1, 2, 3, 2.1) << "\n";
    // traverse tree with fold
    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->left->right = new Node(3);
    auto n = traverse(tree, &Node::left, &Node::right);
    std::cout << "\n" << (n == tree->left->right) << "\n";
}