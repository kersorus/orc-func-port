#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../dest_files/gstadderorc-dist.h"

int main(int argc, char *argv[])
{
  char *endptr;
  long int n = strtol(argv[1], &endptr, 10);
  long int p1 = strtol(argv[2], &endptr, 10);
  int32_t *a = malloc(n * sizeof(*a));
  int32_t *b = malloc(n * sizeof(*b));
  int32_t *c = malloc(n * sizeof(*c));

  for (int i = 0; i < n; i++)
  {
    a[i] = (int32_t) i;
    b[i] = (int32_t) i;
    c[i] = b[i];
  }

#ifdef DEBUG
  printf("a: ");
  for (int i = 0; i < n; i++)
    printf ("%d ", a[i]);
  printf("\n");

  printf("b: ");
  for (int i = 0; i < n; i++)
    printf ("%d ", b[i]);
  printf("\n");
#endif

#ifdef _ORC
#ifdef DEBUG
  printf("i am orc\n");
#endif
  long int start = clock();
  adder_orc_add_volume_s32(b, a, p1, n);
  long int final = clock();
#else
#ifdef _SSE
#ifdef DEBUG
  printf("i am sse\n");
#endif
  long int start = clock();
  adder_orc_add_volume_s32_sse(b, a, p1, n);
  long int final = clock();
#else
#ifdef _CMP
#ifdef DEBUG
  printf("i am cmp\n");
#endif
  long int start = clock();
  adder_orc_add_volume_s32(b, a, p1, n);
  long int final = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("orc time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1 + c[i])
    {
      printf("orc: FAILED, a[i] = %d, b[i] = %d\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("orc: PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  long int start_sse = clock();
  adder_orc_add_volume_s32_sse(b, a, p1, n);
  long int final_sse = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("sse time: %ld\n", final_sse - start_sse);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1 + a[i] * p1 + c[i])
    {
      printf("sse: FAILED, a[i] = %d, b[i] = %d\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("sse: PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

#endif
#endif
#endif

#ifdef DEBUG
  printf("result: ");
  for (int i = 0; i < n; i++)
    printf ("%d ", b[i]);
  printf("\n");
#endif

#ifndef _CMP
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1 + c[i])
    {
      printf("FAILED, a[i] = %d, b[i] = %d\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
#endif

  return 0;
}
