#include <stdio.h>
#include <stdlib.h>
#include "pixel_tracer.h"

int main(){

  Pixel_tracer_app  app;
  init_app(&app);


  Shape* sh1 = create_cercle_shape(15,15,5);
  Shape* sh2 = create_cercle_shape(20,20,7);


  add_shape_to_layer(app.current_layer, sh1);
  add_shape_to_layer(app.current_layer, sh2);

  while(1){
    clear_screen();
    draw_all_layers(app.current_area);
    draw_area(app.current_area);
    rl_get_line();
    parse_ligne();
  }


  destry_app(&app);
}

