/**Name of the file : tree-lib.h
*Goal of the file : Creation an manipulation of binary trees
*Authors : Lucas CELANT / Loic MARTIN
*E-mail : lucas.celant@utbm.fr / loic.martin@utbm.fr
*Last modification : 6/12/2017
*/

#ifndef _TREE_LIB_H_
#define _TREE_LIB_H_

/*
 	* The abstract datatype transaction
 */
typedef enum bool
{
	true = 1, false = 0
} bool;

typedef struct tree_elem {
	long value;
	struct tree_elem* right;
	struct tree_elem* left;
} Tree_Element;
typedef Tree_Element* BTree;

/**
 * @param a an integer value
 * @param b an integer value
 * @return the maximum value between a and b
 */
int max(int a, int b);

/**
 * Test if a binary tree is empty
 * @param b the binary tree to test
 * @return true if the binary tree is empty, false otherwise
 */
bool is_empty(BTree b);

/**
 * Test if a binary tree is a leaf (i.e. has no children)
 * @param b the binary tree to test
 * @return true if the binary tree is leaf, false if it's not
 */
bool is_leaf(BTree b);

/** Link a tree t to its children l(left) and r(right)
 * @param t the ase tree
 * @param l the left children
 * @param r the right children
 * @return the adress of the t tree
 */
BTree root(BTree t, BTree l, BTree r);

/**
 * Creates a binary tree leaf
 * @param value the content of the node
 * @return a pointer to the binary tree node
 */
BTree new_leaf(long value);

/**
 * Give the value of the root node
 * @param t the tree we want to know the adress
 * @return value of the root node
 */
long root_value(BTree t);

/**
 * Give the adress of the left node
 * @param t the tree we want to the left child
 * @return the left child node
 */
BTree left_child(BTree t);

/**
 * Give the adress of the right node
 * @param t the tree we want to the right child
 * @return the right child node
 */
BTree right_child(BTree t);

/**
 * @param b the binary tree
 * @return the number of nodes of the tree
 */
int size(BTree b);

/**
 * @param b the binary tree
 * @return the number of leaves of the tree
 */
int nb_leaves(BTree b);

/**
 * @param b the binary tree
 * @return the height (number of levels) of the tree
 */
int height(BTree b);

/**
 * Test if a value is contained in the tree
 * @param t a binary tree
 * @param l the value we want to search in the tree
 * @return true if the value is contained, othewise false
 */
bool contain(BTree t, long l);

#endif
