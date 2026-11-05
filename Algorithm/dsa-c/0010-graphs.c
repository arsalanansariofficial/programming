#include <stdio.h>

#define LENGTH 10
#define NO_EDGE -1

#define NODES {'A', 'B', 'C', 'D', 'E', 'F', 'G'}

#define MATRIX_1 {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}}

#define MATRIX_2 {{0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0}, {1, 1, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}}

#define MATRIX_3 {{0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}}

typedef struct
{
  char nodes[LENGTH];
  int matrix[LENGTH][LENGTH];
} Graph;

void init_array(int array[], int length);
void init_graph(Graph *graph, int length);
void print_edges(Graph *graph, int length);
void print_graph(Graph *graph, int length);

void add_node(Graph *graph, int length, int index, char data);
void add_edge(Graph *graph, int length, int src, int dst, int weight);
int check_edge(Graph *graph, int length, int src, int dst);

void dfs(Graph *graph, int length, int node_index, int visited[]);
void print_dfs(Graph *graph, int length, int node_index);
void bfs(Graph *graph, int length, int node_index);

int dfs_cyclic(Graph *graph, int length, int node_index, int visited[], int parent);
int is_cyclic(Graph *graph, int length);

void init_array(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    array[i] = 0;
  }
}

void init_graph(Graph *graph, int length)
{
  for (int i = 0; i < length; i++)
  {
    graph->nodes[i] = 0;

    for (int j = 0; j < length; j++)
    {
      graph->matrix[i][j] = NO_EDGE;
    }
  }
}

void print_edges(Graph *graph, int length)
{
  printf("Edges\n");

  for (int i = 0; i < length; i++)
  {
    printf("%c: ", graph->nodes[i]);

    for (int j = 0; j < length; j++)
    {
      if (graph->matrix[i][j])
      {
        printf("%c ", graph->nodes[j]);
      }
    }

    printf("\n");
  }
}

void print_graph(Graph *graph, int length)
{
  printf("Graph\n* ");

  for (int i = 0; i < length; i++)
  {
    printf("%c ", graph->nodes[i]);
  }

  printf("\n");

  for (int i = 0; i < length; i++)
  {
    printf("%c ", graph->nodes[i]);

    for (int j = 0; j < length; j++)
    {
      if (graph->matrix[i][j] == NO_EDGE)
      {
        printf("0 ");
        continue;
      }

      printf("%i ", graph->matrix[i][j]);
    }

    printf("\n");
  }
}

void add_node(Graph *graph, int length, int index, char data)
{
  if (index >= 0 && index < length)
  {
    graph->nodes[index] = data;
  }
}

void add_edge(Graph *graph, int length, int src, int dst, int weight)
{
  if (src >= 0 && src < length && dst >= 0 && dst < length)
  {
    graph->matrix[src][dst] = weight;
  }
}

int check_edge(Graph *graph, int length, int src, int dst)
{
  if (src >= 0 && src < length && dst >= 0 && dst < length)
  {
    return graph->matrix[src][dst] == 1;
  }

  return -1;
}

void dfs(Graph *graph, int length, int node_index, int visited[])
{
  visited[node_index] = 1;
  printf("%c ", graph->nodes[node_index]);

  for (int i = 0; i < length; i++)
  {
    if (graph->matrix[node_index][i] && !visited[i])
    {
      dfs(graph, length, i, visited);
    }
  }
}

void print_dfs(Graph *graph, int length, int node_index)
{
  int visited[length];
  init_array(visited, length);

  printf("DFS: ");
  dfs(graph, length, node_index, visited);
  printf("\n");
}

void bfs(Graph *graph, int length, int node_index)
{
  int visited[length], queue[length], start = 0, end = 0;

  init_array(queue, length);
  init_array(visited, length);

  visited[node_index] = 1;
  queue[end++] = node_index;

  printf("BFS: ");

  while (start < end)
  {
    int current_node = queue[start++];
    printf("%c ", graph->nodes[current_node]);

    for (int i = 0; i < length; i++)
    {
      if (graph->matrix[current_node][i] && !visited[i])
      {
        visited[i] = 1;
        queue[end++] = i;
      }
    }
  }

  printf("\n");
}

int dfs_cyclic(Graph *graph, int length, int node_index, int visited[], int parent)
{
  visited[node_index] = 1;

  for (int i = 0; i < length; i++)
  {
    if (!graph->matrix[node_index][i])
    {
      continue;
    }

    if (visited[i] && i != parent)
    {
      return 1;
    }

    if (!visited[i] && dfs_cyclic(graph, length, i, visited, node_index))
    {
      return 1;
    }
  }

  return 0;
}

int is_cyclic(Graph *graph, int length)
{
  int visited[length];
  init_array(visited, length);

  for (int i = 0; i < length; i++)
  {
    if (!visited[i] && dfs_cyclic(graph, length, i, visited, -1))
    {
      printf("Given graph is cyclic\n");
      return 1;
    }
  }

  printf("Given graph is non-cyclic\n");
  return 0;
}

int main()
{
  Graph graph_1 = {NODES, MATRIX_1};
  Graph graph_2 = {NODES, MATRIX_2};
  Graph graph_3 = {NODES, MATRIX_3};

  print_graph(&graph_1, 4);
  print_dfs(&graph_1, 4, 3);

  bfs(&graph_1, 4, 3);
  is_cyclic(&graph_1, 4);

  print_graph(&graph_2, 7);
  print_dfs(&graph_2, 7, 3);

  bfs(&graph_2, 7, 3);
  is_cyclic(&graph_2, 7);

  print_graph(&graph_3, 7);
  print_dfs(&graph_3, 7, 3);

  bfs(&graph_3, 7, 3);
  is_cyclic(&graph_3, 7);
}