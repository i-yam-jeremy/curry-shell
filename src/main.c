#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void read_line(char **line, int maxLength) {
  size_t size = maxLength;
  getline(line, &size, stdin);
}

int main(int argc, char **argv) {
  char *line = (char*) malloc(MAX_LINE_LENGTH+1);
  while (1) {
    printf("> ");
    read_line(&line, MAX_LINE_LENGTH);
    printf("Line: %s", line);
  }
  free(line);
}
