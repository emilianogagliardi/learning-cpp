#include "print.h"
#include "variadic_expressions.h"
#include "vt_application_example.h"
#include "variadic_class_templates.h"

#include <array>

int max(int a, int b)
{
    return b < a ? a : b;
}

void use_print()
{
    std::cout << "USE PRINT\n";
    print(1, 2, 1, "ciao", 1.2, "sasso");
    std::cout << "\n";
    print2('a', 1, 2.3, "b", true);
    print3('a', 1, 2.3, "b", true);
    printDoubled(1, 2, 3, std::string("ciao"));
    std::cout << "\n";
    printPlusOne(1, 2, 3, 4);
    std::cout << "\n\n";
}

void use_variadic_expressions()
{
    std::cout << "USE VARIADIC EXPRESSIONS\n";
    // sum with fold
    std::cout << "sum_foldl(1, 2, 3, 2.1)=" << sum_foldl(1, 2, 3, 2.1) << "\n";
    // traverse tree with fold
    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->left->right = new Node(3);
    auto n = traverse(tree, &Node::left, &Node::right);
    std::cout << "correctly traversed: " << (n == tree->left->right) << "\n";
    // example compile time variadic expression
    std::cout << "isHomogeneous(1, 1, 2, 3) = " << isHomogeneous(1, 1, 2, 3) << "\n";
    std::cout << "isHomogeneous('1', 1, 2, 2.1) = " << isHomogeneous('1', 1, 2, 2.1) << "\n";
    // example variadic indices
    std::cout << "print with variadic indices\n";
    int a[] = { 1, 2, 3, 4, 5 };
    printElems(a, 2, 3, 1, 0);
    std::cout << "\n";
    printIdx<2, 3, 1, 0>(a);
    std::cout << "\n\n";
}

void use_make_and_call()
{
    std::cout << "USE MAKE AND CALL\n";
    auto p = make<std::pair<int, int>>(1, 3);
    std::cout << "created pair with make " << p.first << " " <<
        p.second << "\n";
    std::cout << "called function max with call_function " <<
        call_function(max, 2, 1) << "\n\n";
}

void use_variadic_classes()
{
    std::cout << "USE VARIADIC CLASSES\n";
    // example of use of variadic template class
    std::array<int, 3> container{ 1, 2, 3 };
    printElements2(container, Indices<0, 1>{});
    std::cout << "\n";
   
    // example of array with deduction guide
    my_array<int, 3> my_arr{ 1, 2, 3 };
    for (auto i : my_arr) std::cout << i << " ";
    std::cout << "\n";
    // the following gives compile error because of my_array constructor
    // deduction guide
    // my_array<int, 3> my_arr2{ 1, 2, 3 };

    // example of hineritance from variadic template
    // combine hasher and equality for customers in one type:
    using CustomerOP = Overloader<CustomerHash, CustomerEq>;
    std::unordered_set<Customer, CustomerHash, CustomerEq> coll1;
    std::unordered_set<Customer, CustomerOP, CustomerOP> coll2;
}

int main()
{
    use_print();
    use_variadic_expressions();
    use_make_and_call();
    use_variadic_classes();
}