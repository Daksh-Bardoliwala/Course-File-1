#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int value;
  // Left child is always a smaller value
  struct node *left;
  // Right child is always a larger value
  struct node *right;
} node;

void printTree(node *tree) {
  if (tree == NULL) {
    return;
  }
  printf("%p", tree);
  printTree(tree->left);
  printf("%d\n", tree->value);
  printTree(tree->right);
}

bool searchTree(node *tree, int num) {
  if (tree == NULL) {
    return false;
  }
  if (num < tree->value) {
    return (searchTree(tree->left, num));
  } else if (num > tree->value) {
    return (searchTree(tree->right, num));
  } else {
    return true;
  }
}

void deleteTree(node *tree) {
  if (tree == NULL) {
    return;
  }
  node *rtmp = tree->right;
  node *ltmp = tree->left;
  free(tree);
  deleteTree(rtmp);
  deleteTree(ltmp);
}

void addNode(node *tree, node *value) {
  if (tree == NULL) {
    return;
  }
  if (value->value < tree->value) {
    if (tree->left == NULL) {
      tree->left = value;
      return;
    } else {
      addNode(tree->left, value);
    }
  } else if (value->value > tree->value) {
    if (tree->right == NULL) {
      tree->right = value;
      return;
    } else {
      addNode(tree->right, value);
    }
  } else if (value->value == tree->value) {
    return;
  }
}

int main(void) {
  int a[10] = {
    3, 1, 5, 2, 4,
    5, 2, 7, 9, 3
  };
  node *root = malloc(sizeof(node));
  if (root == NULL) {
    return 1;
  }
  root->left = NULL;
  root->right = NULL;
  for (int i = 0; i < 10; i++) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
      return 1;
    }
    n->value = a[i];
    addNode(root, n);
  }
  printTree(root);
  deleteTree(root);
  return 0;
}