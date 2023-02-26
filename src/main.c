#include <stdio.h>
#include <stdlib.h>
#include "area.h"
#include "shape.h"
#include "parser.h"
#include "render.h"
#include "layers.h"
#include "id.h"

int main(){

  Area* area;

  area = create_area(80,40,1, "MainArea");
  Layer* layer1 = create_layer(get_next_id(), "Layer-1");

  add_layer_to_list(area->lst_layers , layer1);
  set_layer_visible(layer1);

  Shape* sh1 = create_cercle_shape(15,15,5);
  Shape* sh2 = create_cercle_shape(20,20,7);


  add_shape_to_layer(layer1, sh1);
  add_shape_to_layer(layer1, sh2);

  while(1){
    clear_screen();
    draw_all_layers(area);
    draw_area(area);
    rl_get_line();
    parse_ligne();
  }

  delete_area(area);
}

