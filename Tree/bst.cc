#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
};

enum dir {left = 1, right, non};

struct node *root;
enum dir direction;
struct node *parent;

void swap(struct node *t, struct node *s)
{
  int temp;
  
  temp = t->key;
  t->key = s->key;
  s->key = temp;
}

void inorder(struct node *root)
{
  if (root) {
    inorder(root->left);
    printf("%p %d \n\tleft: %p \n\tright %p\n",root, root->key, root->left, root->right);
    inorder(root->right);
  }
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

struct node *successor(struct node *root)
{
  struct node *t = root->right;

  if (!t)
    return root;

  parent = root;
  direction = right;

  // critical: left MUST not be zero!!!
  while (t->left && (parent = t) && (direction = left)) { 
    t = t->left;
  }

  return t;
}


struct node *insert(struct node *root, int val)
{
  struct node *p, *t, *parent;
  enum dir d = non;

  t = create(val);
  parent = p = root;

  if (root == NULL) // empty tree
    return t;

  while (p) {
    if (val < p->key) {
      d = left;
      parent = p;
      p = p->left;
    } else if (val > p->key) {
      d = right;
      parent = p;
      p = p->right;
    } else { // same value shouldn't be insert twice;
      return root;
    }
  }

  if (d == left)
    parent->left = t;
  else if (d == right)
    parent->right = t;

  return root;
}

struct node *deletenode(struct node *root, int val)
{
  struct node *t; // target
  struct node *s; // successor
  direction = non;
  parent = NULL;

  t = root;
  while (t && t->key != val) { // find target
    if (val < t->key) {
      parent = t;
      direction = left;
      t = t->left;
    } else if (val > t->key) {
      parent = t;
      direction = right;
      t = t->right;
    }
  }

  /* case 0, find nothing */
  if (!t)
    return root;
  /* case 1, root is target and doesn't have successor*/
  if (t == root && t == successor(t)) {
    root = t->left;
    free(t);
    return root;
  }
  /* case 2, find target, and it has successor
   * swap content of t and successor(t), do the 
   * find/swap process to t's successor again.
   * FINALLY, t has no left or right, because
   * it's someone's successor and it doesn't have
   * a successor.
   */
  while ((s = successor(t)) && s != t) {
    swap(t, s);
    t = s;
  }
  if (direction == left)
    parent->left = t->left;
  else if (direction == right) 
    parent->right = t->left;
  else
    ;
  free(t);
  return root;
} 

int main (int argc, char *argv[])
{
  int n = 10;
  int i;
  int val;

  for (i = 0; i < n; i++) {
    scanf("%d ", &val);
    root = insert(root, val);
  }

  for (i = 0; i < n; i++) {
    root = deletenode(root, i);
    inorder(root);
    printf("\n");
  }

  return 0;
}

