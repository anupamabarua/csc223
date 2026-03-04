# Chapter 10 – Efficient Binary Trees (pp. 298–306)

## 10.1 Why “Efficient” Binary Trees?

Regular Binary Search Trees (BSTs) can become **skewed** if data is inserted in sorted order.

Example:
Insert: 10, 20, 30, 40  
→ Tree becomes right-skewed  
→ Height = n  
→ Search time becomes **O(n)** instead of O(log n)

Efficient binary trees are designed to:
- Maintain small height
- Stay balanced
- Guarantee O(log n) operations

Goal:
Keep tree height ≈ log₂(n)

---

## 10.2 Height-Balanced Trees

A tree is **height-balanced** if:
The difference between heights of left and right subtrees is limited.

Balance condition:
| height(left) − height(right) | ≤ 1

This ensures:
- No long skewed chains
- Logarithmic height
- Fast searching, insertion, and deletion

---

## 10.3 AVL Trees

AVL Tree = First self-balancing Binary Search Tree  
Invented by: Adelson-Velsky and Landis

### AVL Property

For every node:
Balance Factor (BF) = height(left subtree) − height(right subtree)

Allowed values:
BF ∈ { -1, 0, +1 }

If balance factor becomes:
+2 or -2 → Tree must be rebalanced

---

## 10.4 Rotations in AVL Trees

Rotations restore balance without violating BST property.

### 1. Single Rotation (LL Rotation)

Occurs when:
- Insertion in left subtree of left child
- Tree becomes left-heavy

Fix:
Right rotation

---

### 2. Single Rotation (RR Rotation)

Occurs when:
- Insertion in right subtree of right child
- Tree becomes right-heavy

Fix:
Left rotation

---

### 3. Double Rotation (LR Rotation)

Occurs when:
- Insertion in right subtree of left child

Fix:
1. Left rotation on left child
2. Right rotation on root

---

### 4. Double Rotation (RL Rotation)

Occurs when:
- Insertion in left subtree of right child

Fix:
1. Right rotation on right child
2. Left rotation on root

---

## 10.5 Insertion in AVL Tree

Steps:
1. Insert like a normal BST
2. Update heights
3. Compute balance factor
4. If unbalanced, perform appropriate rotation

Time Complexity:
O(log n)

Because height always remains logarithmic.

---

## 10.6 Deletion in AVL Tree

Steps:
1. Delete like a normal BST
2. Update heights
3. Check balance factor
4. Perform rotations if necessary

Deletion may require multiple rebalancing steps upward.

Time Complexity:
O(log n)

---

## 10.7 Comparison: BST vs AVL

| Feature | BST | AVL |
|----------|------|------|
| Balanced? | Not guaranteed | Always balanced |
| Worst-case search | O(n) | O(log n) |
| Height | Can be n | ≈ log n |
| Extra work | None | Rotations required |

---

## Key Takeaways

- Normal BSTs can degrade into linked lists.
- AVL trees automatically rebalance.
- Balance Factor controls structure.
- Rotations preserve BST property.
- Guarantees efficient O(log n) operations.