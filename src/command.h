#ifndef _COMMAND_H_
#  define _COMMAND_H_

#  define MAX_PARAM 10

#  include <stdlib.h>
#  include <string.h>
#  include <stdio.h>

#  include <readline/readline.h>
#  include <readline/history.h>
#  include "pixel_tracer.h"


struct command {
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char *str_params[10];
    int flt_size;
    float flt_params[10];
};

typedef struct command Command;



Command *create_commande();

void add_int_param(Command * cmd, int p);

void add_float_param(Command * cmd, float p);

void add_str_param(Command * cmd, char *p);

void free_cmd(Command * cmd);

int read_exec_command(Pixel_tracer_app * app);

void read_from_stdin(Command * cmd);


#endif
