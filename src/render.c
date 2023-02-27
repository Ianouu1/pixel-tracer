#include "render.h"
#include <string.h>

void clear_area(Area* area){
  for(unsigned int i=0; i < area-> height ; i++){
    for(unsigned int j=0; j < area-> width ; j++){
      area->area[i][j] = EMPTY_CELL;
    }
  }
}

void draw_area(Area* area){
  for(unsigned int i=0; i < area-> height ; i++){
    for(unsigned int j=0; j < area-> width ; j++){
      switch(area->area[i][j]){
      case EMPTY_CELL:
        printf("%c", EMPTY_CHAR);
        break;
      case FULL_CHAR:
        printf("%c", FULL_CHAR);
        break;
    }
    }
    printf("\n");
  }
}


void clear_screen(){
  printf("\033[H\033[J");
}


void draw_all_layers(Area* area){
  list* layer_list = area->lst_layers;
  lnode* layer_node = get_first_node(layer_list);
  while(layer_node != NULL){
    Layer* layer = (Layer*) layer_node->data;
    if (layer->visible == 0){
      break;
    }
    draw_layer_shapes(area, layer);
    layer_node = get_next_node(layer_list, layer_node);
  }
  
}



void draw_layer_shapes(Area* area, Layer* layer){
  list shape_list = layer->shapes;

  lnode* shape_node = get_first_node(&shape_list);
  while (shape_node != NULL){
    Shape* shp = (Shape*) shape_node->data;

    list* list_pixel = create_shape_to_pixel(shp);

    lnode* pixel_node = get_first_node(list_pixel);
    while(pixel_node != NULL){
      Pixel* pxl = pixel_node->data;
      // TODO check if cell is in the area 
      area->area[pxl->px][pxl->py] = FULL_CHAR;
      pixel_node = get_next_node(list_pixel, pixel_node);
    }
    void remove_pixel_shape(list* list_pixel);
    shape_node = get_next_node(&shape_list, shape_node);
  }

  return;
}


