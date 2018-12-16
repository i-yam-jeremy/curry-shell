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
  Token *token = Lexer_next(lexer);
  printf("Token: %ld\n", token);
  if (token->type == L_PAREN) {
    printf("L_PAREN");
  }
  return NULL;
}

Command* parse(char *s) {
  Lexer *lexer = Lexer_new(s);
  printf("Lexer: %ld\n", lexer);
  return parse_command(lexer);
}
