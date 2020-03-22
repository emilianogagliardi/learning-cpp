#ifndef FOLD_H
#define FOLD_H

template<typename... Args>
auto sum_foldl(Args... s)
{
    return (... + s);
}

// binary tree

struct Node {
    int t;
    Node* left;
    Node* right;
    Node(int t_) : t(t_), left(nullptr), right(nullptr) {}
};

template<typename T, typename... Ts>
Node* traverse(T node, Ts... nodes)
{
    return (node ->* ... ->* nodes);
}

#endif // !FOLD_H
