#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av) {
  srand(time(NULL));
  
  int n, lmax, lmin = 0;

  if (ac > 1) 
    n = atoi(av[1]);

  if (ac > 2)
    lmax = atoi(av[2]);

  if (ac > 3) {
    lmin = atoi(av[3]);
    lmin = lmin < 0 ? 0 : lmin;
    lmin = lmax < lmin ? lmax : lmin;
  }
  
  if (ac < 3 || n < 1 || lmax < lmin) {
    fprintf(stderr, "randstr  num  max_length  [min_length]\n");
    exit(1);
  }

  for (int i = 0; i < n; i ++) {
    int l = lmin + rand() % (lmax - lmin + 1);
    for (int j = 0; j < l; j ++)
      printf("%c", 'a' + rand() % ('z' - 'a' + 1));
    printf("\n");
  }

  return 0;
}
