#ifndef __LEXER_H__
#define __LEXER_H__

#define LEXER_SAVED_STATE_COUNT 32

enum TokenType {
  IDENTIFIER,
  L_PAREN,
  R_PAREN,
  STR,
  OTHER
};

typedef struct {
  enum TokenType type;
  char *value;
  int length;
  int pos;
} Token;

typedef struct {
  char *s;
  int pos;
} Lexer;


Lexer* Lexer_new(char *s);
Token* Lexer_next(Lexer *lexer);

#endif
