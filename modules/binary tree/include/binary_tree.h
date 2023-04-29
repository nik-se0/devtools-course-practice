// Copyright 2023 Semenova Veronika

#ifndef MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
#define MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_

struct Node {
    int Value;
    Node* Left;
    Node* Right;
    Node* Parent;

    Node(const int V = 0.0, Node* P = nullptr, 
        Node* L = nullptr, Node* R = nullptr);
    explicit Node(const Node& n);
};

#endif  // MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
