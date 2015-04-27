#include <stdio.h>

#include "youtube-dl-embedder.h"

int main (int argc, char **argv)
{
  char * resolved;

  if (argc < 2)
    return 1;

  resolved = ydle_resolve_url(argv[1]);
  printf ("%s\n", resolved);
  return 0;
}
