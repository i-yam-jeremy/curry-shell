#include "parse.h"

#include <stdio.h>

#include "lexer.h"

/*
typedef struct {
  char *name;
  LinkedList args;
} Command;

enum ValueType {
  STRING,
  LIST,
  COMMAND
};

typedef struct command_value {
  enum ValueType type;
  union {
    List *list;
    char *string;
    Command *command;
  };
} CommandValue;
*/

Command* parse_command(Lexer *lexer) {
  //TODO
  return NULL;
}

Command* parse(char *s) {
  Lexer *lexer = Lexer_new(s);
  return parse_command(lexer);
}
