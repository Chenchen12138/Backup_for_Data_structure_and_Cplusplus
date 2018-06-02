#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
typedef char Elem;
typedef struct tagBinTree
{
	Elem data;
	struct tagBinTree *lc;
	struct tagBinTree *rc;
}BinNode,BinTree;
void binTreePreorder(BinTree *root)
{
	if (root == NULL) return;
	printf("%c", root->data);
	binTreePreorder(root->lc);
	binTreePreorder(root->rc);
}
void binTreeInorder(BinTree *root)
{
	if (root == NULL) return;
	binTreeInorder(root->lc);
	printf("%c", root->data);
	binTreeInorder(root->rc);
}
void binTreePostorder(BinTree *root)
{
	if (root == NULL) return;
	binTreePostorder(root->lc);
	binTreePostorder(root->rc);
	printf("%c", root->data);
}
bool binTreeCreate(BinTree **root)
{
	char ch;
	printf("Input:");
	ch = getchar(); getchar();
	if (ch == '#')
		*root = NULL;
	else
	{
		if (*root == NULL) return false;
		*root = (BinNode *)malloc(sizeof(BinNode));
		(*root)->data = ch;
		binTreeCreate(&((*root)->lc));
		binTreeCreate(&((*root)->rc));
	}
	return true;
}
bool binTreeClear(BinTree *root)
{
	if (root == NULL) return false;
	if (root->lc) binTreeClear(root->lc);
	if (root->rc) binTreeClear(root->rc);
	free(root);
	return true;
}
int binTreeDepth(BinTree *root)
{
	if (root == NULL) return 0;
	int m=binTreeDepth(root->lc);
	int n=binTreeDepth(root->rc);
	return m > n ? (m + 1) : (n + 1);
}
int main()
{
	BinTree *tree;
	tree = (BinTree *)malloc(sizeof(BinTree));
	int depth;
	binTreeCreate(&tree);
	printf("\nPreorder:\t"); binTreePreorder(tree); 
	printf("\nInorder:\t");  binTreeInorder(tree);
	printf("\nPostorder:\t"); binTreePostorder(tree);
	depth = binTreeDepth(tree);
	printf("\nDepth=%d\n", depth);
	binTreeClear(tree);
	system("pause");
	return 0;
}