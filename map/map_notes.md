# Map

* **First rule:** The first node in the tree is the leftmost node in the tree.
* **Next rule:** The successor of a node is:
  * **Next-R rule:** If it has a right subtree, the leftmost node in the right subtree.
  * **Next-U rule:** Otherwise traverse up the tree
    * if you make a right turn (i.e. this node was a left child), then that parent node is the successor.
    * If you make a left turn (i.e. this node was a right child), continue going up.
    * If you can't go up anymore, then there's no successor.

```cpp
Node getLeftMost(Node n)
  WHILE (n.leftChild != NULL)
    n = n.leftChild
  RETURN n

Node getFirst(Tree t)
  IF (t.root == NULL) RETURN NULL
  ELSE
     RETURN getLeftMost(t.root);

Node getNext(Node n)
  IF (n.rightChild != NULL)
     RETURN getLeftMost(n.rightChild)
  ELSE
     WHILE (n.parent != NULL AND n == n.parent.rightChild)
        n = n.parent;
     RETURN n.parent;

PROCEDURE iterateOver(Tree t)
  Node n = getFirst(t);
  WHILE n != NULL
     visit(n)
     n = getNext(n)
```