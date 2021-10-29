// Problem-28 If we are given two traversal sequences, can we construct the binary tree
// uniquely?

// Solution: It depends on what traversals are given. If one of the traversal methods is Inorder then
// the tree can be constructed uniquely, otherwise not.
// Therefore, the following combinations can uniquely identify a tree:
// • Inorder and Preorder
// • Inorder and Postorder
// • Inorder and Level-order

// The following combinations do not uniquely identify a tree.
// • Postorder and Preorder
// • Preorder and Level-order
// • Postorder and Level-order

// So, even if three of them (PreOrder, Level-Order and PostOrder) are given, the tree cannot be
// constructed uniquely.