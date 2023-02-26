#ifndef _PARSER_H_
#define _PARSER_H_

#include <readline/readline.h>
#include <readline/history.h>

char* rl_gets();
void rl_get_line();
int skip_blanks();
void parse_ligne();

#endif
