#include <stdio.h>
#include <stdlib.h>

//Indirect memory leak example.
//The struct represents a binary tree. 

int main(void)
{
	typedef struct
	{
	  int val;
	  struct Tree *left;
	  struct Tree *right;
	} Tree;

	Tree* t = (Tree*)malloc(sizeof(Tree));
	t->left = malloc(sizeof(Tree));
	t->right = malloc(sizeof(Tree));

	((Tree*)(t->left))->left = malloc(sizeof(Tree));

	return 0;
}
