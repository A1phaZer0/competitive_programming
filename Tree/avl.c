#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	struct node *left;
	struct node *right;
	int data;
	int ht; //tree height
};

/* rotate left */
struct node *rotate_l(struct node *root)
{
	struct node *t;

	t = root->right;
	root->right = t->left;
	t->left = root;

	return t;
}

/* rotate right */
struct node *rotate_r(struct node *root)
{
	struct node *t;
	
	t = root->left;
	root->left = t->right;
	t->right = root;

	return t;
}

int balance_factor(struct node *root)
{
	int hl, hr;

	hl = root->left ? root->left->ht : 0;
	hr = root->right ? root->right->ht : 0;

	return  hl - hr;

}

int height(struct node *root)
{
	return root->ht;
}

void update_ht(struct node *root)
{
	int hl, hr;

	if (root) {
		hl = root->left ? height(root->left) : 0;
		hr = root->right ? height(root->right) : 0;

		root->ht = hl > hr ? hl : hr;
	}
}

struct node *insert(struct node *root, int val)
{
	struct node *t;
	int bf_root;
	int bf_sub;

	if (root == NULL) {
		t = (struct node *)malloc(sizeof(*t));
		t->left = t->right = NULL;
		t->ht = 0;
		t->data = val;
		return t;
	}
	
	if (val < root->data) {
		root->left = insert(root->left, val);
	}
	if (val > root->data) {
		root->right = insert(root->right, val);
	}

	bf_root = balance_factor(root);
	switch(bf_root) {
	case 2:
		bf_sub = balance_factor(root->left);
		if (bf_sub == -1) {// left right case
			root->left = rotate_l(root->left);
			root = rotate_r(root);
		}
		if (bf_sub == 1) {// left left case
			root = rotate_r(root->left);
		}
		break;
	case -2:
		bf_sub = balance_factor(root->right);
		if (bf_sub == -1) {
			root = rotate_l(root->right);
		}
		if (bf_sub == 1) {
			root->right = rotate_r(root->right);
			root = rotate_l(root);
		}
		break;
	default:
		break;
	}
	update_ht(root->left);
	update_ht(root->right);
	update_ht(root);

	return root;
}

struct node *delete(struct node *root, int val)
{
	struct node *t;
	int bf_root;
	int bf_sub;

	
	return root;
}

int main(int argc, char *argv[])
{
	return 0;
}
