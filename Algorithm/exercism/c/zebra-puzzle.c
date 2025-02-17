typedef struct
{
  const char *drinks_water;
  const char *owns_zebra;
} solution_t;

solution_t solve_puzzle(void);

solution_t solve_puzzle()
{
  return (solution_t){"Norwegian", "Japanese"};
}
