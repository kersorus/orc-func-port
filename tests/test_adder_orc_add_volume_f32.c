#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include "../dest_files/gstadderorc-dist.h"

int main(int argc, char *argv[])
{
  char *endptr;
  long int n = strtol(argv[1], &endptr, 10);
  float v = strtof(argv[2], &endptr);
  float *a = malloc(n * sizeof(*a));
  float *b = malloc(n * sizeof(*b));
  float *c = malloc(n * sizeof(*c));

  for (int i = 0; i < n; i++)
  {
    a[i] = (float) i;
    b[i] = (float) i;
    c[i] = b[i];
  }

#ifdef DEBUG
  printf("a: ");
  for (int i = 0; i < n; i++)
    printf ("%1.1f ", a[i]);
  printf("\n");

  printf("v: %1.1f\n", v);

  printf("b: ");
  for (int i = 0; i < n; i++)
    printf ("%1.1f ", b[i]);
  printf("\n");
#endif

#ifdef _ORC
#ifdef DEBUG
  printf("i am orc\n");
#endif
  long int start = clock();
  adder_orc_add_volume_f32(b, a, v, n);
  long int final = clock();
#else
#ifdef _SSE
#ifdef DEBUG
  printf("i am sse\n");
#endif
  long int start = clock();
  adder_orc_add_volume_f32_sse(b, a, v, n);
  long int final = clock();
#else
#ifdef _CMP
#ifdef DEBUG
  printf("i am cmp\n");
#endif
  long int start = clock();
  adder_orc_add_volume_f32(b, a, v, n);
  long int final = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("orc time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (!((b[i] - c[i] - a[i] * v < 0.01) && (a[i] * v + c[i] - b[i] < 0.01)))
    {
      printf("orc: FAILED, a[i] = %f, b[i] = %f\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("orc: PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  long int start_sse = clock();
  adder_orc_add_volume_f32_sse(b, a, v, n);
  long int final_sse = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("sse time: %ld\n", final_sse - start_sse);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (!((b[i] - c[i] - a[i] * v * 2 < 0.01) && (a[i] * v * 2 + c[i] - b[i] < 0.01)))
    {
      printf("sse: FAILED, a[i] = %f, b[i] = %f\n", a[i], b[i]);
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
    printf ("%1.1f ", b[i]);
  printf("\n");
#endif

#ifndef _CMP
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (!((b[i] - c[i] - a[i] * v < 0.01) && (a[i] * v + c[i] - b[i] < 0.01)))
    {
      printf("FAILED, a[i] = %f, b[i] = %f\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
#endif

  return 0;
}
