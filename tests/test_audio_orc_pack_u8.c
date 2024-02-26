#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include "../dest_files/gstaudiopack-dist.h"

int main(int argc, char *argv[])
{
  char *endptr;
  long int n = strtol(argv[1], &endptr, 10);
  int32_t *a = calloc(n, sizeof(*a));
  uint8_t *b = calloc(n, sizeof(*b));

  for (int i = 0; i < n; i++)
  {
    a[i] = (int32_t) i % 127;
    b[i] = (uint8_t) 0;
  }

#ifdef DEBUG
  printf("a: ");
  for (int i = 0; i < n; i++)
    printf ("%d ", a[i]);
  printf("\n");

  printf("b: ");
  for (int i = 0; i < n; i++)
    printf ("%hhu ", b[i]);
  printf("\n");
#endif

#ifdef _ORC
#ifdef DEBUG
  printf("i am orc\n");
#endif
  long int start = clock();
  audio_orc_pack_u8(b, a, n);
  long int final = clock();
#else
#ifdef _SSE
#ifdef DEBUG
  printf("i am sse\n");
#endif
  long int start = clock();
  audio_orc_pack_u8_sse(b, a, n);
  long int final = clock();
#else
#ifdef _CMP
#ifdef DEBUG
  printf("i am cmp\n");
#endif
  long int start = clock();
  audio_orc_pack_u8(b, a, n);
  long int final = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("orc time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i])
    {
      printf("orc: FAILED, a[i] = %d, b[i] = %hhu\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("orc: PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    b[i] = 0;
    if (b[i] != 0)
    {
      printf("ERROR: zeroing b\n");
      return 1;
    }
  }
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("b zeroed\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  long int start_sse = clock();
  audio_orc_pack_u8_sse(b, a, n);
  long int final_sse = clock();

  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("sse time: %ld\n", final_sse - start_sse);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i])
    {
      printf("sse: FAILED, a[i] = %d, b[i] = %hhu\n", a[i], b[i]);
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
    printf ("%hhu ", b[i]);
  printf("\n");
#endif

#ifndef _CMP
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
  printf("time: %ld\n", final - start);
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");

  for (int i = 0; i < n; i++)
  {
    if (b[i] != a[i])
    {
      printf("FAILED, a[i] = %d, b[i] = %hhu\n", a[i], b[i]);
      for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
      return 1;
    }
  }

  printf("PASSED\n");
  for (int i = 0; i < 60; i++)  {printf("-");} printf("\n");
#endif

  return 0;
}
