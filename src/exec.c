#include "exec.h"

#include "parse.h"

void exec_command(Command *cmd) {
  //TODO
}

void exec(char *line) {
  Command *cmd = parse(line);
  exec_command(cmd);
}
