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


void strlwr(char* str){
  int i;
  for(i=0; i < strlen(str); i++){
    if((str[i]>='A')&&(str[i]<='Z')){
      str[i]+='a'-'A';
    }
  }
}

int is_int(const char* str){
  int i;
  for(i=0; i < strlen(str); i++){
    if((str[i]<'0')||(str[i]>'9')){
      return 0;
    }
  }
  return 1;
}

int is_word(const char* str){
  int i;
  for(i=0; i < strlen(str); i++){
    if((str[i]<'a')||(str[i]>'z')){
      return 0;
    }
  }
  return 1;
}


int is_float(const char* str){
  return 0;                     /* TODO  */
}

void clean_text(char* str){
  int i = 0;
  strlwr(str);
  while(str[i] != '\0'){
    if(str[i] == '#' || str[i] == '\n') {
      str[i] = '\0';
      return;
    }
    if( ((str[i]<'0')&&(str[i]>'9')) && (str[i]<'a')&&(str[i]>'z')) {
      strcpy(str, "error carractere inattendu !");
      return;
    }
    i++;
  }
}

void read_from_stdin(Command* cmd){
  char *str1, *token;
  int nb_str = 0, nb_int = 0, nb_float = 0; 
  char *line_read = (char *)NULL;
  char prompt[4]="~> ";
	line_read = readline(prompt);
  if (line_read && *line_read){
		add_history (line_read);
  }
  else{
    return;                     /* rien lu */
  }
  clean_text(line_read);

  printf("{%s}\n",line_read);

  token = strtok(line_read, " ");
  while(token != NULL){
    if(cmd->str_size > 9 || cmd->int_size > 9 || cmd->flt_size > 9)  return; /* nb max args */

    if(is_word(token)){
      add_str_param(cmd, token);
    }
    else if(is_int(token)){
      add_int_param(cmd, atoi(token));
    }
    else if(is_float(token)){
      add_float_param(cmd, atof(token));
    }
    else{
      // error ligne
      add_str_param(cmd, "error");
      add_str_param(cmd, "line");
    }
    token = strtok(NULL, " ");
  }
  free(line_read);
}


void debug_cmd(Command* cmd){
  printf("\n --- \n");
  printf("str:\n");
  for(int i = 0; i < cmd->str_size ; i++){
    printf("<%s>\n", cmd->str_params[i]);
  }
  printf("int:\n");
  for(int i = 0; i < cmd->int_size ; i++){
    printf("<%d>\n", cmd->int_params[i]);
  }
  printf("float:\n");
  for(int i = 0; i < cmd->flt_size ; i++){
    printf("<%f>\n", cmd->flt_params[i]);
  }
}

void read_exec_command(Pixel_tracer_app* app){
  Command* cmd = create_commande();
  read_from_stdin(cmd);
  // debug_cmd(cmd);

  



  free_cmd(cmd);
}

