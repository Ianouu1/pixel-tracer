#include "area.h"


Area* create_area(unsigned int width,
                  unsigned int height,
                  unsigned char id,
                  char* name){
  Area* ptr_area = (Area*) malloc (sizeof(Area));
  ptr_area->width = width;
  ptr_area->height = height;
  ptr_area->lst_layers = create_layers_list();
  ptr_area->id = id;
  strcpy(ptr_area->name, name);
  ptr_area->area = (char**) malloc (height * sizeof(char*));
  for(unsigned int i=0; i < ptr_area-> height ; i++){
    ptr_area->area[i] = (char*) malloc (width * sizeof(char));
  }
  return ptr_area;
}

void delete_area(Area* area){
  // todo: delate layers
  for(unsigned int i=0; i < area-> height ; i++){
    free(area->area[i]);
  }
  free (area);
}
