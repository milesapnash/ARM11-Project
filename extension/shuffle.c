#include "shuffle.h"
// Utilises Knuth shuffle algorithm
// Found at: https://www.rosettacode.org/wiki/Knuth_shuffle#C

int rrand(int m) { return (int)((double)m * (rand() / (RAND_MAX + 1.0))); }

#define BYTE(X) ((unsigned char *)(X))
void shuffle(void *obj, size_t nmemb, size_t size) {
  // Returns a randomly generated seed
  srand(time(NULL));

  void *temp = malloc(size);
  size_t n = nmemb;
  while (n > 1) {
    size_t k = rrand(n--);
    memcpy(temp, BYTE(obj) + n * size, size);
    memcpy(BYTE(obj) + n * size, BYTE(obj) + k * size, size);
    memcpy(BYTE(obj) + k * size, temp, size);
  }
  free(temp);
}