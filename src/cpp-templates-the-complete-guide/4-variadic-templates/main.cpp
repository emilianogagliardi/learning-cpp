#include "print.h"
#include "variadic_expressions.h"
#include "vt_application_example.h"
#include "variadic_class_templates.h"

#include <array>

int max(int a, int b)
{
    return b < a ? a : b;
}

int main()
{
    // print
    print(1, 2, 1, "ciao", 1.2, "sasso");
    std::cout << "\n";
    print2('a', 1, 2.3, "b", true);
    print3('a', 1, 2.3, "b", true);
    printDoubled(1, 2, 3, std::string("ciao"));
    std::cout << "\n";
    printPlusOne(1, 2, 3, 4);
    std::cout << "\n";
    // sum with fold
    std::cout << sum_foldl(1, 2, 3, 2.1) << "\n";
    // traverse tree with fold
    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->left->right = new Node(3);
    auto n = traverse(tree, &Node::left, &Node::right);
    std::cout << "\n" << (n == tree->left->right) << "\n";
    // use make function
    auto p = make<std::pair<int, int>>(1, 3);
    std::cout <<"\ncreated pair with make " << p.first << " " << 
        p.second << "\n";
    std::cout << "\ncalled function max with call_function " << 
        call_function(max, 2, 1) << "\n";
    // example compile time variadic expression
    std::cout << "\nisHomogeneous(1, 1, 2, 3) = " << isHomogeneous(1, 1, 2, 3);
    std::cout << "\nisHomogeneous('1', 1, 2, 2.1) = " << isHomogeneous('1', 1, 2, 2.1) << "\n";
    // example variadic indices
    int a[] = { 1, 2, 3, 4, 5 };
    printElems(a, 2, 3, 1, 0);
    std::cout << "\n";
    printIdx<2, 3, 1, 0>(a);
    std::cout << "\n";
    std::array<int, 3> container{ 1, 2, 3 };
    printElements2(container, Indices<0, 1>{});
}