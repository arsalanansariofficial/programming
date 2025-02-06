typedef struct
{
  double a;
  double b;
  double c;
} triangle_t;

int is_triangle(triangle_t sides);

int is_scalene(triangle_t sides);
int is_isosceles(triangle_t sides);
int is_equilateral(triangle_t sides);

int is_triangle(triangle_t sides)
{
  int first = sides.b + sides.c >= sides.a;
  int second = sides.a + sides.c >= sides.b;
  int third = sides.a + sides.b >= sides.c;
  int fourth = !sides.a || !sides.b || !sides.c;

  return first && second && third && !fourth;
}

int is_scalene(triangle_t sides)
{
  int first = is_triangle(sides);
  int second = sides.a != sides.b && sides.a != sides.c && sides.b != sides.c;

  return first && second;
}

int is_isosceles(triangle_t sides)
{
  int first = is_triangle(sides);
  int second = sides.a == sides.b || sides.a == sides.c || sides.b == sides.c;

  return first && second;
}

int is_equilateral(triangle_t sides)
{
  int first = is_triangle(sides);
  int second = sides.a == sides.b && sides.a == sides.c;

  return first && second;
}
