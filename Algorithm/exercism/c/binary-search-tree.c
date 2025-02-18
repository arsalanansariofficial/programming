#include <stdlib.h>
#include <stddef.h>

typedef struct node_t
{
  struct node_t *right;
  struct node_t *left;
  int data;
} node_t;

int get_node_count(node_t *root);
node_t *create_node(int data);

node_t *insert(node_t *root, int data);
size_t dfs(node_t *root, int array[], size_t index);

void free_tree(node_t *root);
int *sorted_data(node_t *root);
node_t *build_tree(int *array, size_t length);

int get_node_count(node_t *root)
{
  if (!root)
  {
    return 0;
  }

  return 1 + get_node_count(root->left) + get_node_count(root->right);
}

node_t *create_node(int data)
{
  node_t *root = malloc(sizeof(node_t));

  root->data = data;
  root->left = root->right = NULL;

  return root;
}

node_t *insert(node_t *root, int data)
{
  if (!root)
  {
    return create_node(data);
  }

  if (data <= root->data)
  {
    root->left = insert(root->left, data);
    return root;
  }

  root->right = insert(root->right, data);
  return root;
}

size_t dfs(node_t *root, int array[], size_t index)
{
  if (!root)
  {
    return index;
  }

  if (root->left)
  {
    index = dfs(root->left, array, index);
  }

  array[index++] = root->data;

  if (root->right)
  {
    index = dfs(root->right, array, index);
  }

  return index;
}

void free_tree(node_t *root)
{
  if (!root)
  {
    return;
  }

  free_tree(root->left);
  free_tree(root->right);

  free(root);
}

int *sorted_data(node_t *root)
{
  int *array = calloc(get_node_count(root), sizeof(int));

  dfs(root, array, 0);
  return array;
}

node_t *build_tree(int *array, size_t length)
{
  node_t *root = NULL;

  for (size_t i = 0; i < length; i++)
  {
    root = insert(root, array[i]);
  }

  return root;
}
