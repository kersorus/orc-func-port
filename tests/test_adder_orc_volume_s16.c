#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../dest_files/gstadderorc-dist.h"
#include <stdint.h>

int main(int argc, char *argv[])
{
  char *endptr;
  long int n = strtol(argv[1], &endptr, 10);
  int p1 = strtol(argv[2], &endptr, 10);
  int16_t *a = malloc(n * sizeof(*a));
  int16_t *b = malloc(n * sizeof(*b));

  for (int i = 0; i < n; i++)
  {
    b[i] = (int16_t) i;
    a[i] = b[i];
  }

#ifdef DEBUG
  printf("p1 = %d\n", p1);

  printf("a: ");
  for (int i = 0; i < n; i++)
    printf ("%hd ", a[i]);
  printf("\n");

  printf("b: ");
  for (int i = 0; i < n; i++)
    printf ("%hd ", b[i]);
  printf("\n");
#endif

#ifdef _ORC
#ifdef DEBUG
  printf("i am orc\n");
#endif
  long int start = clock();
  adder_orc_volume_s16(b, p1, n);
  long int final = clock();
#else
#ifdef _SSE
#ifdef DEBUG
  printf("i am sse\n");
#endif
  long int start = clock();
  adder_orc_volume_s16_sse(b, p1, n);
  long int final = clock();
#else
#ifdef _CMP
#ifdef DEBUG
  printf("i am cmp\n");
#endif
  long int start = clock();
  adder_orc_volume_s16(b, p1, n);
  long int final = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("orc time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1)
    {
      printf("orc: FAILED, a[i] = %hd, b[i] = %hd\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("orc: PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  long int start_sse = clock();
  adder_orc_volume_s16_sse(b, p1, n);
  long int final_sse = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("sse time: %ld\n", final_sse - start_sse);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1 * p1)
    {
      printf("sse: FAILED, a[i] = %hd, b[i] = %hd\n", a[i], b[i]);
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
    printf ("%hd ", b[i]);
  printf("\n");
#endif

#ifndef _CMP
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i] * p1)
    {
      printf("FAILED, a[i] = %hd, b[i] = %hd\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
#endif

  return 0;
}
