#define _GNU_SOURCE
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare(FILE *file, char *pattern, int iflag, char *file_name) {
  char buffer[500] = { 0 };
  int count = 0;
  while (fgets(buffer, 500, file)) {
    if (iflag) {
      if (strcasestr(buffer, pattern) != NULL) {
        fputs(file_name, stdout);
        fputs(": ", stdout);
        fputs(buffer, stdout);
      }
    } else if (strstr(buffer, pattern) != NULL) {
      fputs(file_name, stdout);
      fputs(": ", stdout);
      fputs(buffer, stdout);
    }
    count++;
  }
  return count;
}

int main(int argc, char *argv[argc + 1]) {
  int c = 0;
  int cflag = 0;
  int iflag = 0;
  opterr = 2;
  while ((c = getopt(argc, argv, "ic")) != -1) {
    switch (c) {
    case 'i':
      iflag = 1;
      break;
    case 'c':
      cflag = 1;
      break;
    case '?':
      fprintf(stderr, "Unknown flag given\n");
      return EXIT_FAILURE;
    }
  }

  if (argc - optind < 2) { // check accuracy of conditional
    fprintf(stderr, "Not enough arguments given\n");
    return EXIT_FAILURE;
  }
  int index = optind;
  char *pattern = argv[index];
  index++;
  int lines = 0;
  while (index < argc) {
    char *file_name = argv[index];
    FILE *file = fopen(file_name, "r");
    if (file) {
      lines = lines + compare(file, pattern, iflag, file_name);
      fclose(file);
    } else {
      fprintf(stderr, "Failed to open file\n");
    }

    index++;
  }
  if (cflag) {
    printf("Total lines scanned: %d\n", lines);
  }
  return EXIT_SUCCESS;
}
