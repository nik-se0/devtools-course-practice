// Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>

#include "include/binary_tree.h"
#include <vector>

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
  Can_create_Node_with_descendant) {
  Node ed1;
  Node ed2(2);
  Node ed3(3);
  ASSERT_NO_THROW(Node ed(3, &ed1, &ed2, &ed3));
}
TEST(Semenova_Veronika_Node,
  Create_Node_with_descendant_correctly) {
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

TEST(Semenova_Veronika_Binary_Tree, Ñan_insert_node_in_empty_tree) {
    BinaryTree t;
    ASSERT_NO_THROW(t.Insert(2));
}
TEST(Semenova_Veronika_Binary_Tree, Insert_node_in_empty_tree_correctly) {
    BinaryTree t;
    t.Insert(2);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 2);
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_insert_node_in_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Insert(2));
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_find_value_in_empty_tree) {
    BinaryTree t;
    ASSERT_NO_THROW(t.Find(2));
}
TEST(Semenova_Veronika_Binary_Tree, Find_value_in_empty_tree_correctly) {
    BinaryTree t;
    EXPECT_EQ(t.Find(2), nullptr);
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_find_value_in_tree) {
    BinaryTree t(2);
    ASSERT_NO_THROW(t.Find(2));
}
TEST(Semenova_Veronika_Binary_Tree, Find_value_in_tree_correctly) {
    BinaryTree t(2);
    Node* n = t.Find(2);
    EXPECT_EQ(n->Value, 2);
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_not_insert_repeated_node_in_tree) {
    BinaryTree t(3);
    ASSERT_ANY_THROW(t.Insert(3));
}
TEST(Semenova_Veronika_Binary_Tree, Can_SetNext_in_tree) {
    BinaryTree t(3);
    t.Reset();
    ASSERT_NO_THROW(t.SetNext());
}
TEST(Semenova_Veronika_Binary_Tree, Insert_node_in_tree_corrertly) {
    BinaryTree t(3);
    t.Insert(8);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 3);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 8);
}
TEST(Semenova_Veronika_Binary_Tree, Insert_node_in_tree_corrertly2) {
    BinaryTree t(3);
    t.Insert(1);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 1);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 3);
}
TEST(Semenova_Veronika_Binary_Tree, Can_create_tree_from_vector_of_values) {
    std::vector<int> val = { -2, 2, 5, 3, -1, 7, 8, 6 };
    ASSERT_NO_THROW(BinaryTree t(val));
}
TEST(Semenova_Veronika_Binary_Tree, Create_tree_from_vector_of_values_corrertly) {
    std::vector<int> val = { -2, 5, 3 };
    BinaryTree t(val);
    t.Reset();
    EXPECT_EQ(t.GetValue(), -2);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 3);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 5);
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_not_delete_node_in_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.Delete(2));
}
TEST(Semenova_Veronika_Binary_Tree, Find_value_in_tree_from_vector_of_values_corrertly) {
    std::vector<int> val = { -2, 2, 5, 3, -1, 7, 8, 6 };
    BinaryTree t(val);
    Node* res = t.Find(-1);
    EXPECT_EQ(res->Value, -1);
}
TEST(Semenova_Veronika_Binary_Tree, Ñan_delete_node_in_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Delete(3));
}
TEST(Semenova_Veronika_Binary_Tree, Delete_node_in_tree_corrertly) {
    BinaryTree t(3);
    t.Delete(3);
    EXPECT_EQ(t.Find(3), nullptr);
}
TEST(Semenova_Veronika_Binary_Tree, Can_delete_node_without_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(t.Delete(7));
}
TEST(Semenova_Veronika_Binary_Tree, Delete_node_without_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    t.Delete(7);
    EXPECT_EQ(t.Find(7), nullptr);
}
TEST(Semenova_Veronika_Binary_Tree, Can_delete_node_with_one_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(t.Delete(-3));
}
TEST(Semenova_Veronika_Binary_Tree, Delete_node_with_one_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    t.Delete(-3);
    EXPECT_EQ(t.Find(-3), nullptr);
}
TEST(Semenova_Veronika_Binary_Tree, Can_delete_node_with_two_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(t.Delete(5));
}
TEST(Semenova_Veronika_Binary_Tree, Delete_node_with_two_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    t.Delete(5);
    EXPECT_EQ(t.Find(5), nullptr);
}
TEST(Semenova_Veronika_Binary_Tree, Can_delete_a_root) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(t.Delete(1));
}
TEST(Semenova_Veronika_Binary_Tree, Delete_a_root_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    t.Delete(1);
    EXPECT_EQ(t.Find(1), nullptr);
}