#include <stdlib.h>
#include "parser.h"

static char *line_read = (char *)NULL;
char *input_string;
int tk_ptr;


int low_case(char c){
	if ((c>='A')&&(c<='Z'))
		c-='A'-'a';
	return c;
}

int is_digit(char c){
	if ((c>='0')&&(c<='9')) return 1;
	return 0;
}



// rend true si c est un caractère autorisé pour un identifieur
int is_idchar(char c){
	if ((c>='a')&&(c<='z')) return 1;
	if ((c>='0')&&(c<='9')) return 1;
	if (c=='_') return 1;
	return 0;
}


// rend true si le mot sur le flux d'entrée est le mot m de longueur l
int check_word(char*m, int l){
	int i;
	for (i=0;i<l;i++){
    if (m[i]!=low_case(input_string[tk_ptr+i])){
      return 0;
    }
  }
	//printf("[%d]",input_string[tk_ptr+i]); fflush(stdout);
	if (is_idchar(low_case(input_string[tk_ptr+i]))==1){
    return 0;
  }
	return 1;
}

// comme ckeck_word, mais positionne l'entrée à la fin du mot si le test est positif
int is_word(char*m,int l){
	int r=check_word(m,l);
	if (r) tk_ptr+=l;
	return r;
}


char* rl_gets(){
  // Si le buffer ets deja plein alors il faut le libérer
	if (line_read){
      free (line_read);
      line_read = (char *)NULL;
  }
	char prompt[4]="~> ";

	line_read = readline(prompt);
	//Ajouter la ligne à l'historique
	if (line_read && *line_read)
		add_history (line_read);
  return (line_read);
}


// rend le prochain caractère qui n'est pas un espace
int skip_blanks(){
	int tk;
	if (input_string==NULL){ return -1; }
	while ((input_string[tk_ptr]==SPACE)||(input_string[tk_ptr]==TAB)) tk_ptr++;
	if (input_string[tk_ptr]=='#'){
    do
      tk_ptr++;
    while ((input_string[tk_ptr]!=10)&&(input_string[tk_ptr]!=0));
    return 0;	// équivaut à une fin de ligne
  }
	tk=input_string[tk_ptr];
	if (tk==10) tk=0;
	return tk;
}



//récupération d'une ligne par la console
// c'est le get_line par défaut.
void rl_get_line(){
	do{
      input_string=rl_gets();
      tk_ptr=0;
  }while (skip_blanks()==0);
}


int is_eol(){
	switch (skip_blanks()){
  case '#':	// le début d'un commentaire signifie une fin de ligne
  case 10:	// caractère de fin de ligne
  case 0:		// caractère de fin de fichier
    return 1;
  }
	return 0;
}

// erreur avec affichage de la position
void error(char*msg){
	fprintf(stderr,"%*c\nerreur **%s**\n",tk_ptr+3,'^',msg);
}


int next_token(){
	tk_ptr++;
	return skip_blanks();
}

int token(){
	if (input_string==NULL) return -1;
	return input_string[tk_ptr];
}



void check_eol(){
	char error_msg[30];
	if (is_eol()==0){
    //fprintf(stderr,"%*c\n",tk_ptr+3,'^');
    sprintf(error_msg,"fin de ligne attendue (%d)",token());
    error(error_msg);
  }
}


int get_params(){
  


}


void parse_ligne(){
	skip_blanks();
	if (is_word("exit",4)){
		exit(0);
		return;
	}
}






