#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

int max(int num1, int num2);

Node *create_node(int data);
Node *create_binary_tree(int array[], int length);

int find_height(Node *root);
int find_depth(Node *root, int key, int depth);

Node *insert(Node *root, int data);

int get_node_count(Node *root);
void print_values(Node *root);

Node *delete_tree(Node *root);
bool is_int_tree(Node *root, int key);

int get_height(Node *root, int key);

Node *get_min(Node *root);
Node *get_max(Node *root);

bool is_binary_search_tree(Node *root, int min, int max);
Node *delete_value(Node *root, int key);

int max(int num1, int num2)
{
  return (num1 > num2) ? num1 : num2;
}

Node *create_node(int data)
{
  Node *root = (Node *)malloc(sizeof(Node));

  root->data = data;
  root->left = root->right = NULL;

  return root;
}

Node *create_binary_tree(int array[], int length)
{
  Node *root = NULL;

  for (int i = 0; i < length; i++)
  {
    root = insert(root, array[i]);
  }

  return root;
}

int find_height(Node *root)
{
  if (!root)
  {
    return -1;
  }

  return max(find_height(root->left), find_height(root->right)) + 1;
}

int find_depth(Node *root, int key, int depth)
{
  if (!root)
  {
    return -1;
  }

  if (root->data == key)
  {
    return depth;
  }

  int left_depth = find_depth(root->left, key, depth + 1);

  if (left_depth != -1)
  {
    return left_depth;
  }

  return find_depth(root->right, key, depth + 1);
}

Node *insert(Node *root, int data)
{
  if (!root)
  {
    root = create_node(data);
  }

  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }

  if (data > root->data)
  {
    root->right = insert(root->right, data);
  }

  return root;
}

int get_node_count(Node *root)
{
  if (!root)
  {
    return 0;
  }

  return 1 + get_node_count(root->left) + get_node_count(root->right);
}

void print_values(Node *root)
{
  if (!root)
  {
    return;
  }

  if (root->left)
  {
    print_values(root->left);
  }

  printf("%i ", root->data);

  if (root->right)
  {
    print_values(root->right);
  }
}

Node *delete_tree(struct Node *root)
{
  if (!root)
    return NULL;

  delete_tree(root->left);
  delete_tree(root->right);

  free(root);
  return NULL;
}

bool is_int_tree(Node *root, int key)
{
  if (!root)
  {
    return false;
  }

  if (key == root->data)
  {
    return true;
  }

  if (key < root->data)
  {
    return is_int_tree(root->left, key);
  }

  return is_int_tree(root->right, key);
}

int get_height(Node *root, int key)
{
  if (!root)
  {
    return -1;
  }

  if (key < root->data)
  {
    return get_height(root->left, key);
  }

  if (key > root->data)
  {
    return get_height(root->right, key);
  }

  return find_height(root) + 1;
}

Node *get_min(Node *root)
{
  if (!root || !root->left)
  {
    return root;
  }

  return get_min(root->left);
}

Node *get_max(Node *root)
{
  if (!root || !root->right)
  {
    return root;
  }

  return get_max(root->right);
}

bool is_binary_search_tree(Node *root, int min, int max)
{
  if (!root)
    return true;

  if (root->data < min || root->data > max)
    return false;

  return is_binary_search_tree(root->left, min, root->data) && is_binary_search_tree(root->right, root->data, max);
}

Node *delete_value(Node *root, int key)
{
  if (!root)
    return root;

  if (key < root->data)
  {
    root->left = delete_value(root->left, key);
    return root;
  }

  if (key > root->data)
  {
    root->right = delete_value(root->right, key);
    return root;
  }

  if (!root->left)
  {
    Node *temp = root;
    root = root->right;
    free(temp);
    return root;
  }

  if (!root->right)
  {
    Node *temp = root;
    root = root->left;
    free(temp);
    return root;
  }

  Node *temp = get_min(root->right);
  root->data = temp->data;
  root->right = delete_value(root->right, temp->data);
  return root;
}

int get_successor(Node *root, Node *node, int key, int successor)
{
  if (!node)
  {
    return successor;
  }

  if (key < node->data)
  {
    return get_successor(root, node->left, key, successor);
  }

  if (key > node->data)
  {
    return get_successor(root, node->right, key, successor);
  }

  if (node->right)
  {
    return get_min(node->right)->data;
  }

  if (key < root->data)
  {
    return get_successor(root->left, node, key, root->data);
  }

  if (key > root->data)
  {
    return get_successor(root->right, node, key, successor);
  }

  return successor;
}

int main()
{
  Node *root = NULL;
  int array[] = {10, 15, 5, 4, 6, 14, 16};

  root = create_binary_tree(array, 7);

  printf("In-Order Tree: ");
  print_values(root);
  printf("\n");

  printf("Status of 1: %s\n", is_int_tree(root, 1) ? "True" : "False");
  printf("Status of 15: %s\n", is_int_tree(root, 15) ? "True" : "False");

  printf("Minimum element: %i\n", get_min(root)->data);
  printf("Maximum element: %i\n", get_max(root)->data);

  printf("Height of tree: %i\n", find_height(root));
  printf("Height of node 16: %i\n", get_height(root, 16));
  printf("Depth of node 15: %i\n", find_depth(root, 15, 0));

  printf("Is a Binary Seach Tree: %s\n", is_binary_search_tree(root, INT_MIN, INT_MAX) ? "True" : "False");

  root = delete_value(root, 15);
  printf("In-Order Tree: ");
  print_values(root);
  printf("\n");

  printf("Nodes in a tree: %i\n", get_node_count(root));
  printf("Sucessor of Node 6: %i\n", get_successor(root, root, 6, -1));

  root = delete_tree(root);
  printf("In-Order Tree: ");
  print_values(root);
  printf("%s", !root ? "Empty\n" : "\n");
}
