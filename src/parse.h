#ifndef __PARSE_H__
#define __PARSE_H__

#include "list.h"

typedef struct {
  char *name;
  List args;
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

Command* parse(char *s);

#endif
