# Splay Trees
## By: Anupama and Donovan

- A splay tree is a self-adjusting binary search tree data structure
- The tree structure is adjusted dynamically based on the accessed or insterted elements

## Different rotations

### Zig Rotation
![Tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203100633/Zig-rotation.png)
-  If a node has a right child, perform a right rotation to bring it to the root. If it has a left child, perform a left rotation.

### Zag Rotation
![tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203101229/zag-rotation.png)
- Nodes shift one position to the left from their current location

### Zig - Zig Rotation
![tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203102114/Zig-zig-rotation.png)
- Nodes shift two positions to the right from their current location

### Zag-Zag Rotation
![tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203103016/zag--zag-rotation.png)
- Nodes move two positions to the left from their present position

### Zig-Zag Rotation
![tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203104532/Zig-zag-rotation2.png)
- A combination of a zig rotation followed by a zag rotation
- Nodes shift one position to the right and then one position to the left from their current location

### Zag-Zig Rotation:
![tree](https://media.geeksforgeeks.org/wp-content/uploads/20230203105833/zag-zig-rotation.png)
-  A series of zag rotations followed by a zig rotation
- Nodes moving one position to the left, followed by a shift one position to the right from their current location