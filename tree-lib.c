/**Name of the file : tree-lib.c
*Goal of the file : Creation an manipulation of binary trees
*Authors : Lucas CELANT / Loic MARTIN
*E-mail : lucas.celant@utbm.fr / loic.martin@utbm.fr
*Last modification : 6/12/2017
*/

#include "tree-lib.h"
#include "stack-lib.h"
#include <stdlib.h>

int max(int a, int b)
{
	return a < b ? b : a;
}

bool is_tree_empty(BTree b)
{
	return b == NULL;
}

bool is_leaf(BTree b)
{
	if(is_tree_empty(b))
	{
		return false;
	}
	
	return is_tree_empty(b->left) && is_tree_empty(b->right);
}

BTree root(BTree t, BTree l, BTree r)
{
	t->right=r;
	t->left=l;
	return t;
}

BTree new_leaf(long value)
{
	BTree t = (BTree)malloc(sizeof(Tree_Element));
	t->value = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

long root_value(BTree t)
{
	return t->value;
}

BTree left_child(BTree t)
{
	return t->left;
}

BTree right_child(BTree t)
{
	return t->right;
}

int size(BTree b)
{
	if(is_tree_empty(b)) {
		return 0;
	}
	
	return 1 + size(b->left) + size(b->right);
}

int nb_leaves(BTree b)
{
	if(is_tree_empty(b)) {
		return 0;
	}
	
	if(is_leaf(b)) {
		return 1;
	}
	
	return nb_leaves(b->left) + nb_leaves(b->right);
}

int height(BTree b)
{
	if(is_tree_empty(b)) {
		return 0;
	}
	
	return max(height(b->left), height(b->right)) + 1;
}

bool contain(BTree t, long l)
{
	Btree currentNode = t;
	bool b = false;
	if(is_tree_empty(t) == false){
		while(b == false || is_tree_empty(currentNode)){
			if(currentNode < l)
				currentNode = currentNode->left;
			else if(currentNode > l)
				currentNode = currentNode->right;
			else
				b = true;
	return b;
}
