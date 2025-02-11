#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct
{
  uint8_t grade;
  char name[MAX_NAME_LENGTH];
} student_t;

typedef struct
{
  size_t count;
  student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *roster);
int compare_students(const void *a, const void *b);

roster_t get_grade(roster_t *roster, uint8_t grade);
bool add_student(roster_t *roster, char name[], uint8_t grade);

void init_roster(roster_t *roster) { roster->count = 0; }

int compare_students(const void *a, const void *b)
{
  student_t *s1 = (student_t *)a;
  student_t *s2 = (student_t *)b;

  if (s1->grade == s2->grade)
  {
    return strcmp(s1->name, s2->name);
  }

  if (s1->grade < s2->grade)
  {
    return -1;
  }

  return 1;
}

roster_t get_grade(roster_t *roster, uint8_t grade)
{
  roster_t filtered = {0};

  for (size_t i = 0; i < roster->count; i++)
    if (roster->students[i].grade == grade)
      filtered.students[filtered.count++] = roster->students[i];

  return filtered;
}

bool add_student(roster_t *roster, char name[], uint8_t grade)
{
  if (roster->count >= MAX_STUDENTS)
    return false;

  for (size_t i = 0; i < roster->count; i++)
    if (strcmp(roster->students[i].name, name) == 0)
      return false;

  student_t student;

  student.grade = grade;
  strcpy(student.name, name);

  roster->students[roster->count++] = student;
  qsort(roster->students, roster->count, sizeof(student_t), *compare_students);

  return true;
}
