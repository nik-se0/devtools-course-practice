// Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>

#include "include/binary_tree.h"

TEST(Semenova_Veronika_Node, Can_create_Node) {
  ASSERT_NO_THROW(Node ed);
}
TEST(Semenova_Veronika_Node,
  Can_create_Node_with_Value) {
  ASSERT_NO_THROW(Node ed(3));
}
TEST(Semenova_Veronika_Node,
  Create_Node_with_Value_correctly) {
  Node ed(3);
  EXPECT_EQ(ed.Value, 3);
}
TEST(Semenova_Veronika_Node,
  Replace_value_Node_correctly) {
  Node ed(3);
  ed.Value = 1;
  EXPECT_EQ(ed.Value, 1);
}
TEST(Semenova_Veronika_Node,
  Can_create_Node_with_parent) {
  Node ed1;
  ASSERT_NO_THROW(Node ed(3, &ed1));
}
TEST(Semenova_Veronika_Node,
  Create_Node_with_parent_correctly) {
  Node ed1(1);
  Node ed(3, &ed1);

  EXPECT_EQ((ed.Parent)->Value, 1);
}
TEST(Semenova_Veronika_Node,
  Can_create_Node_with_neighbor) {
  Node ed1;
  Node ed2(2);
  Node ed3(3);
  ASSERT_NO_THROW(Node ed(3, &ed1, &ed2, &ed3));
}
TEST(Semenova_Veronika_Node,
  Create_Node_with_neighbor_correctly) {
  Node ed1(1);
  Node ed2(2);
  Node ed3(3);
  Node ed(3, &ed1, &ed2, &ed3);

  EXPECT_EQ((ed.Left)->Value, 2);
  EXPECT_EQ((ed.Right)->Value, 3);
}
TEST(Semenova_Veronika_Node,
  Can_create_Node_with_copy_constructor) {
  Node ed1;
  ASSERT_NO_THROW(Node ed(ed1));
}
TEST(Semenova_Veronika_Node,
  Create_Node_with_copy_constructor_correctly) {

  Node ed1(1);
  Node ed2(2);
  Node ed3(3, &ed1, &ed2);

  Node e(ed3);

  EXPECT_EQ(e.Value, 3);
  EXPECT_EQ(e.Left, nullptr);
  EXPECT_EQ(e.Right, nullptr);
  EXPECT_EQ(e.Parent, nullptr);
}

TEST(Semenova_Veronika_Binary_Tree, Can_create_tree) {
  ASSERT_NO_THROW(BinaryTree t);
}
TEST(Semenova_Veronika_Binary_Tree, Can_create_tree_with_Value) {
    ASSERT_NO_THROW(BinaryTree t(3));
}
TEST(Semenova_Veronika_Binary_Tree, Can_not_resert_in_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.Reset());
}
TEST(Semenova_Veronika_Binary_Tree, Can_resert_in_not_empty_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Reset());
}
TEST(Semenova_Veronika_Binary_Tree, Can_not_extract_Value_from_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.GetValue());
}
TEST(Semenova_Veronika_Binary_Tree, Can_extract_Value_from_tree) {
    BinaryTree t(3);
    t.Reset();
    ASSERT_NO_THROW(t.GetValue());
}
TEST(Semenova_Veronika_Binary_Tree, Extract_Value_from_tree_correctly) {
    BinaryTree t(3);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 3);
}
