#include "command.h"

Command* create_commande (){
  Command*  cmd = (Command*)malloc(sizeof(Command));
  cmd->name[0] = '\0';
  cmd->int_size = 0;
  cmd->str_size = 0;
  cmd->flt_size = 0;
  return cmd;
}

void add_int_param(Command* cmd, int p){
  if (cmd->int_size >= MAX_PARAM-1) return;
  cmd->int_params[cmd->int_size] = p;
  cmd->int_size = cmd->int_size + 1;
}


void add_float_param(Command* cmd, float p){
  if (cmd->flt_size >= MAX_PARAM-1) return;
  cmd->flt_params[cmd->flt_size] = p;
  cmd->flt_size = cmd->flt_size + 1;
}

void add_str_param(Command* cmd, char* p){
  if (cmd->str_size >= MAX_PARAM-1) return;
  char* cpy_str =  (char*) malloc (strlen(p));
  strcpy(cpy_str, p);
  cmd->str_params[cmd->str_size] = cpy_str;
  cmd->str_size = cmd->str_size + 1;
}

void free_cmd(Command* cmd){
  int i;
  for(i=0 ; i < cmd->str_size ; i++){
    free(cmd->str_params[i]);
  }
}
