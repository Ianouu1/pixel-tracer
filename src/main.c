#include <stdio.h>
#include <stdlib.h>
#include "pixel_tracer.h"
#include "command.h"


int main(){

  Pixel_tracer_app  app;
  init_app(&app);

  Shape* sh1 = create_cercle_shape(15,15,5);
  Shape* sh2 = create_cercle_shape(20,20,7);

  add_shape_to_layer(app.current_layer, sh1);
  add_shape_to_layer(app.current_layer, sh2);

  clear_screen();
  draw_all_layers(app.current_area);
  draw_area(app.current_area);

  while(1){

    int err = read_exec_command(&app);
    if (err == 0 || err == 6){
      clear_screen();
      draw_all_layers(app.current_area);
      draw_area(app.current_area);
    }
    if (err == 4){
      break;
    }
    if (err == 5){
      clear_screen();
    }
    if (err == 7){
      continue;
    }

  }


  destry_app(&app);
}

