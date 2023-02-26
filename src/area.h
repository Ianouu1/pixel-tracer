#include <stdlib.h>
#include <stdio.h>
#include "layers.h"

#ifndef _AREA_H_
#define _AREA_H_



struct area{
  unsigned char id;
  char          name[255];
  unsigned int  width;
  unsigned int  height;
  char**        area;
  LayersList*   lst_layers;
};

typedef struct area Area;


Area* create_area(unsigned int width, unsigned int height, unsigned char id, char* name);
void delete_area(Area* area);
void clear_area(Area* area);


#endif
