#include "pch.h"
#include "Q1.h"
#include "Q2.h"

TEST(BinarySearchTreeTest, InsertAndInOrderTraversal) {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    testing::internal::CaptureStdout();
    bst.inOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 3 4 5 6 7 8 ");
}

TEST(BinarySearchTreeTest, RemoveAndInOrderTraversal) {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.remove(4);

    testing::internal::CaptureStdout();
    bst.inOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 3 5 6 7 8 ");
}

TEST(BinarySearchTreeTest, BreadthFirstTraversalTest) {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

 //   testing::internal::CaptureStdout(); // Redirect stdout to testing::internal::GetCapturedStdout()

 //   tree.breadthFirstTraversal();

    std::string output = testing::internal::GetCapturedStdout();

    // Assert that the output of the traversal is correct
    EXPECT_EQ(output, "5 3 7 2 4 6 8 \n");
}

// Test case for in-order traversal
TEST(BinaryTreeTraversalTest, InOrderTraversalTest) {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

//    testing::internal::CaptureStdout();
    inOrderTraversal(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 4 5 6 7 ");

    deleteTree(root);
}

// Test case for pre-order traversal
TEST(BinaryTreeTraversalTest, PreOrderTraversalTest) {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    testing::internal::CaptureStdout();
    preOrderTraversal(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4 2 1 3 6 5 7 ");

    deleteTree(root);
}

// Test case for post-order traversal
TEST(BinaryTreeTraversalTest, PostOrderTraversalTest) {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    testing::internal::CaptureStdout();
    postOrderTraversal(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 3 2 5 7 6 4 ");

    deleteTree(root);
}