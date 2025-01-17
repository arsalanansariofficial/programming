#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct Node
{
  TreeNode *value;
  struct Node *next;
} Node;

typedef struct Queue
{
  Node *head;
  Node *tail;
} Queue;

bool is_empty(Queue *queue)
{
  return !queue->head;
}

Queue *create_queue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

void enqueue(TreeNode *node, Queue *queue)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->value = node;
  new_node->next = NULL;

  if (!queue->head)
  {
    queue->head = new_node;
    queue->tail = new_node;
    return;
  }

  queue->tail->next = new_node;
  queue->tail = queue->tail->next;
}

TreeNode *dequeue(Queue *queue)
{
  if (is_empty(queue))
  {
    return NULL;
  }

  Node *current = queue->head;
  TreeNode *node = current->value;

  queue->head = queue->head->next;
  free(current);

  return node;
}

TreeNode *create_tree_node(int value)
{
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

  root->value = value;
  root->left = NULL;
  root->right = NULL;

  return root;
}

TreeNode *create_binary_tree(int array[], int length)
{
  if (!length)
  {
    return NULL;
  }

  Queue *queue = create_queue();
  TreeNode *root = create_tree_node(array[0]);

  enqueue(root, queue);

  int i = 1;

  while (i < length)
  {
    TreeNode *current = dequeue(queue);

    if (i + 1 < length)
    {
      current->left = create_tree_node(array[i++]);
      current->right = create_tree_node(array[i++]);
      enqueue(current->left, queue);
      enqueue(current->right, queue);
    }
  }

  free(queue);

  return root;
}

void in_order_traversal(TreeNode *root)
{
  if (!root)
  {
    return;
  }

  if (root->left)
  {
    in_order_traversal(root->left);
  }

  printf("%i ", root->value);

  if (root->right)
  {
    in_order_traversal(root->right);
  }
}

void pre_order_traversal(TreeNode *root)
{
  if (!root)
  {
    return;
  }

  printf("%i ", root->value);

  if (root->left)
  {
    pre_order_traversal(root->left);
  }

  if (root->right)
  {
    pre_order_traversal(root->right);
  }
}

void post_order_traversal(TreeNode *root)
{
  if (!root)
  {
    return;
  }

  if (root->left)
  {
    post_order_traversal(root->left);
  }

  if (root->right)
  {
    post_order_traversal(root->right);
  }

  printf("%i ", root->value);
}

void level_order_traversal(TreeNode *root)
{
  if (!root)
  {
    return;
  }

  Queue *queue = create_queue();

  enqueue(root, queue);

  while (!is_empty(queue))
  {
    TreeNode *node = dequeue(queue);

    printf("%i ", node->value);

    if (node->left)
    {
      enqueue(node->left, queue);
    }

    if (node->right)
    {
      enqueue(node->right, queue);
    }
  }

  free(queue);
}

int main()
{
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root = create_binary_tree(array, 7);

  printf("In-Order Tree: ");
  in_order_traversal(root);
  printf("\n");

  printf("Pre-Order Tree: ");
  pre_order_traversal(root);
  printf("\n");

  printf("Post-Order Tree: ");
  post_order_traversal(root);
  printf("\n");

  printf("Level-Order Tree: ");
  level_order_traversal(root);
  printf("\n");

  free(root);
}
