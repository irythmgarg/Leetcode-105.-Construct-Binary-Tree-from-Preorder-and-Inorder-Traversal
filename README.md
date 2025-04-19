# Leetcode-105.-Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal
Construct Binary Tree from Preorder and Inorder Traversal
This project provides a C++ solution to reconstruct a binary tree given its preorder and inorder traversal sequences. This is a classic tree construction problem frequently used in technical interviews and computer science coursework.

🧠 Problem Statement
You are given the preorder and inorder traversal sequences of a binary tree. Construct and return the original binary tree.

Preorder Traversal: Root ➝ Left ➝ Right

Inorder Traversal: Left ➝ Root ➝ Right

✅ Constraints
All node values are unique.

The input lists represent a valid binary tree.

🚀 Approach
Root Identification:

The first element of the preorder list is always the root of the current (sub)tree.

Inorder Partitioning:

Find the index of the root in the inorder list.

Elements to the left belong to the left subtree.

Elements to the right belong to the right subtree.

Recursive Construction:

Recursively build left and right subtrees using slices of the preorder and inorder arrays.

📂 Functions Overview
buildTree(preorder, inorder)
Starts the recursive construction with full array bounds.

maketree(preorder, inorder, prestart, preend, instart, inend)
Recursively builds the tree using bounds within preorder and inorder arrays.

findindex(inorder, value, instart, inend)
Helper to find a node's index in the inorder array.

🧪 Example
cpp
Input:
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]

Output (tree structure):
    3
   / \
  9  20
     / \
    15  7
⏱️ Time & Space Complexity
Time Complexity: O(N²) in the worst case (due to linear search in findindex).
Can be improved to O(N) using a hashmap for inorder indices.

Space Complexity: O(N) for recursion stack and output tree.

📦 Applications
Tree Reconstruction in compilers, parsers.

Building abstract syntax trees.

Serialization and deserialization of trees.
