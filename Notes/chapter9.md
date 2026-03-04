# Chapter 9 – Trees Notes

## 9.1 Introduction

### What is a Tree?
A tree is a non-linear data structure that represents hierarchical relationships between data elements. Unlike arrays, stacks, or queues (linear structures), trees represent parent–child relationships.

### Key Characteristics
- One node is designated as the **root**
- Every other node is connected by exactly one path from the root
- A tree does not contain cycles
- A tree with N nodes has **N–1 edges**

### Basic Terminology
| Term | Definition |
|---|---|
| Node | A data element in a tree |
| Root | Topmost node |
| Edge (Branch) | Connection between two nodes |
| Parent | A node that has children |
| Child | Node derived from another node |
| Leaf (External node) | Node with no children |
| Internal node | Node with at least one child |
| Degree of a node | Number of children of a node |
| Degree of a tree | Maximum degree among all nodes |
| Level of a node | Number of edges from root to that node |
| Height of a tree | Maximum level of any node |
| Subtree | A tree formed from a node and its descendants |
| Forest | A set of disjoint trees |

### Why Trees Are Important
Used to represent:
- Hierarchical data (file systems)
- Organizational charts
- Expression evaluation
- Searching and sorting structures

## 9.2.3 Binary Trees

### Definition
A binary tree is a tree in which each node has **at most two children**: a left child and a right child.

### Properties
- Maximum nodes at level *i*: `2^i`
- Maximum nodes in a binary tree of height *h*: `2^(h+1) - 1`
- Minimum nodes in a binary tree of height *h*: `h + 1`
- For any non-empty binary tree: **# leaf nodes = # nodes with two children + 1**

### Types of Binary Trees

**1. Strict (Full) Binary Tree**
Every non-leaf node has exactly two children.

**2. Complete Binary Tree**
All levels completely filled except possibly the last; last level filled from left to right.

**3. Skewed Binary Tree**
All nodes have only one child (left-skewed or right-skewed). Essentially behaves like a linked list.

### Representation

**Array Representation**
- Root stored at index `1`
- Left child of node at index `i` → `2i`
- Right child → `2i + 1`
- Parent → `i / 2`

✔ Efficient for complete binary trees  
✘ Wasteful for sparse trees

**Linked Representation**
```c
struct node {
    int data;
    struct node *left;
    struct node *right;
};
```
✔ Efficient memory usage  
✔ Suitable for dynamic trees

## 9.2.4 Binary Search Trees

### Definition
A BST is a binary tree where:
- Left subtree contains values **less than** the root
- Right subtree contains values **greater than** the root
- Both subtrees are also BSTs

**Key Property:** `Left subtree < Root < Right subtree`

### Time Complexity
| Case | Search | Insert | Delete |
|---|---|---|---|
| Average | O(log n) | O(log n) | O(log n) |
| Worst (skewed) | O(n) | O(n) | O(n) |

## 9.2.5 Expression Trees

### Definition
An expression tree is a binary tree used to represent arithmetic expressions.

### Structure
- **Leaf nodes** → Operands (numbers/variables)
- **Internal nodes** → Operators (`+`, `−`, `×`, `÷`)

### Example: `(A + B) * C`
```
      *
     / \
    +   C
   / \
  A   B
```

### Applications
- Expression evaluation
- Compiler design / syntax trees
- Converting between infix, prefix, and postfix notation

## 9.4 Traversing a Binary Tree

### 1. Pre-order (Root → Left → Right)
```c
void preorder(node *root) {
    if(root != NULL) {
        visit(root);
        preorder(root->left);
        preorder(root->right);
    }
}
```
Used for: copying trees, prefix expression generation

### 2. In-order (Left → Root → Right)
```c
void inorder(node *root) {
    if(root != NULL) {
        inorder(root->left);
        visit(root);
        inorder(root->right);
    }
}
```
> ⭐ In a BST, in-order traversal produces **sorted output**.

### 3. Post-order (Left → Right → Root)
```c
void postorder(node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        visit(root);
    }
}
```
Used for: deleting a tree, postfix expression generation

### 4. Level-order (By levels, left to right)
- Uses a **queue** (also called Breadth-First Traversal)
- Steps:
  1. Insert root into queue
  2. While queue is not empty: remove node → visit → insert left child → insert right child

### Constructing a Binary Tree from Traversals
- ✔ **In-order + Pre-order** → unique tree
- ✔ **In-order + Post-order** → unique tree
- ✘ **Pre-order + Post-order** alone → not unique

### Quick Comparison
| Traversal | Order | Key Use |
|---|---|---|
| Pre-order | Root → L → R | Tree copy |
| In-order | L → Root → R | Sorted output (BST) |
| Post-order | L → R → Root | Delete tree |
| Level-order | By levels | BFS traversal |