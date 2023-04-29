//  Copyright 2023 Semenova Veronika

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

class BinaryTree {
  Node* root;
  Node* curr;
   public:
  BinaryTree();
  BinaryTree(const int v);

  Node* FindMin(Node* node = nullptr) const;

  int GetValue() const;
  void Reset();
};

#endif  //  MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
