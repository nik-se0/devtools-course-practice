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
  explicit BinaryTree(const int v);

  Node* FindMin(Node* node = nullptr) const;
  Node* FindNext(Node* node) const;

  Node* Find(int k) const;
  void Insert(int k);

  int GetValue() const;
  void Reset();
  void SetNext();
};

#endif  //  MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_H_
