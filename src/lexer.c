#include "lexer.h"

#include <stdlib.h>

Token* Token_new(enum TokenType type, Lexer *lexer, int length) {
  Token *token = (Token*) malloc(sizeof(Token));
  token->type = type;
  token->value = &(lexer->s[lexer->pos]);
  token->length = length;
  token->pos = lexer->pos;
  return token;
}

Lexer* Lexer_new(char *s) {
  Lexer* lexer = (Lexer*) malloc(sizeof(Lexer));
  lexer->s = s;
  lexer->pos = 0;
  return lexer;
}

int is_identifier_char(char c, int length) {
  return
    ('a' <= c && c <= 'z') ||
    ('A' <= c && c <= 'Z') ||
    (c == '_') ||
    (length != 0 && ('0' <= c && c <= '9'));
}

Token* Lexer_read_identifier(Lexer *lexer) {
  int length = 0;

  while (is_identifier_char(lexer->s[lexer->pos+length], length)) {
    length++;
  }

  if (length > 0) {
    Token *token = Token_new(IDENTIFIER, lexer, length);
    lexer->pos += length;
    return token;
  }
  else {
    return NULL;
  }
}

Token* Lexer_read_string(Lexer *lexer, char quoteType) {
  lexer->pos++; // skip first quote
  int length = 0;
  while (lexer->s[lexer->pos+length] != quoteType) {
    length++;
  }

  Token *token = Token_new(STR, lexer, length);
  lexer->pos += length+1; // +1 to include end quote
  return token;
}

void Lexer_skip_whitespace(Lexer *lexer) {
  char c;
  while ((c = lexer->s[lexer->pos]), c == ' ' || c == '\t') {
    lexer->pos++;
  }
}

Token* Lexer_next(Lexer *lexer) {
  Lexer_skip_whitespace(lexer);

  Token *token = Lexer_read_identifier(lexer);
  if (token != NULL) {
    return token;
  }

  char c = lexer->s[lexer->pos];
  if (c == '(') {
    return Token_new(L_PAREN, lexer, 1);
  }
  else if (c == ')') {
    return Token_new(R_PAREN, lexer, 1);
  }
  else if (c == '"' || c == '\'') {
    return Lexer_read_string(lexer, c);
  }
  else {
    return Token_new(OTHER, lexer, 1);
  }

}
