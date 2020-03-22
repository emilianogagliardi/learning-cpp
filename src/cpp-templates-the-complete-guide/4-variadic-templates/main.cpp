#include "print.h"
#include "fold.h"

// An example of use of variadic template
// (as for make_shared, make_unique....)
template <typename T, typename... Args>
T make(Args&&... args) // perfectly forward arguments
{
    return T(args...);
}

template <typename F, typename... Args>
auto call_function(F&& f, Args&&... args)
{
    return f(args...);
}

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
}