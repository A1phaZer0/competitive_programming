#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void inorder(struct node *root)
{
	if (root) {
		inorder(root->left);
		printf("%d %p %p %p\n", root->key, root, root->left, root->right);
		inorder(root->right);
	}
}

struct node *successor(struct node *root)
{
	struct node *t;

	t = root->right;
	while (t->left) {
		t = t->left;
	}

	return t;
}

struct node *create(int val)
{
	struct node *t;

	t = (struct node *)malloc(sizeof(*t));
	t->key = val;
	t->left = NULL;
	t->right = NULL;

	return t;
}

struct node *insert(struct node *root, int val)
{
	struct node *t;

	if (root == NULL) {
		t = create(val);
		root = t;
		return root;
	}

	if (val < root->key) {
		root->left = insert(root->left, val);
	} else if (val > root->key) {
		root->right= insert(root->right, val);
	}

	
	return root;
}

struct node *delete(struct node *root, int val)
{
	struct node *t;
	if (root == NULL)
		return root;
	if (val < root->key) { // left subtree
		root->left = delete(root->left, val);
	} else if (val > root->key) { // right subtree
		root->right = delete(root->right, val);
	} else { // found target node
		if (root->left == NULL) { // only has right child or both NULL
			t = root->right;
			free(root);
			return t;
		} else if (root->right == NULL) { // only has left child
			t = root->left;
			free(root);
			return t;
		} else { // has both children
			t = successor(root);

			root->key = t->key;
			root->right = delete(root->right, t->key);
		}
	}
	return root;
}

int main(int argc, char *argv[])
{
	int val;
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%d ", &val);
		root = insert(root, val);
	}
	for (i = 0; i < 2; i++) {
		scanf("%d ", &val);
		root = delete(root, val);
	}

	printf("INORDER:\n");
	inorder(root);
	printf("\n");

	return 0;
}
