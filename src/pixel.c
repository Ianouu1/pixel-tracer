#include "pixel.h"


Pixel *create_pixel(int px, int py, int color) {
    Pixel *pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    pixel->color = color;
    return pixel;
}

void delete_pixel(Pixel * pixel) {
    free(pixel);
}


list *create_shape_to_pixel(Shape * shape) {
    if (shape->ptrShape == NULL) {
        return NULL;
    }
    list *lst = lst_create_list();

    switch (shape->shape_type) {
    case POINT:
        pixel_point(shape, lst);
        break;
    case LINE:
        pixel_line(shape, lst);
        break;
    case SQUAR:
        pixel_square(shape, lst);
        break;
    case RECTANGLE:
        pixel_rectangle(shape, lst);
        break;
    case CERCLE:
        pixel_cercle(shape, lst);
        break;
    case POLYGON:
        pixel_polygon(shape, lst);
        break;
    }

    return lst;
}

void remove_pixel_shape(list * pixel_lst) {

}


void pixel_point(Shape * shape, list * lst) {
    Point *pt = (Point *) shape->ptrShape;
    Pixel *px = create_pixel(pt->pos_x, pt->pos_y, shape->color);
    lst_insert_tail(lst, lst_create_lnode(px));
}

void draw_segment(int x, int y, int dx, int dy, Color color, list *lst){
  int i, cumul;
  int xinc, yinc;
  Pixel *px;

  xinc = (dx > 0) ? 1 : -1;
  yinc = (dy > 0) ? 1 : -1;
  dx = abs(dx);
  dy = abs(dy);

  px = create_pixel(x, y, color);
  lst_insert_tail(lst, lst_create_lnode(px));

  if (dx > dy) {
    cumul = dx / 2;
    for (i = 1; i <= dx; i++) {
      x += xinc;
      cumul += dy;
      if (cumul >= dx) {
        cumul -= dx;
        y += yinc;
      }
      px = create_pixel(x, y, color);
      lst_insert_tail(lst, lst_create_lnode(px));
    }
  } else {
    cumul = dy / 2;
    for (i = 1; i <= dy; i++) {
      y += yinc;
      cumul += dx;
      if (cumul >= dy) {
        cumul -= dy;
        x += xinc;
      }
      px = create_pixel(x, y, color);
      lst_insert_tail(lst, lst_create_lnode(px));
    }
  }
}

void pixel_line(Shape * shape, list * lst) {
    Line *p_line = (Line *) shape->ptrShape;
    int dx, dy, x, y;

    x = p_line->p1->pos_x;
    y = p_line->p1->pos_y;;
    dx = p_line->p2->pos_x - p_line->p1->pos_x;
    dy = p_line->p2->pos_y - p_line->p1->pos_y;
    draw_segment(x,y, dx,dy, shape->color,  lst);
}

void pixel_cercle(Shape * shape, list * lst) {
    Cercle *p_cercle = (Cercle *) shape->ptrShape;
    int x = 0;
    int y = p_cercle->radus;
    int d = p_cercle->radus - 1;
    Pixel *px;

    while (y >= x) {
        px = create_pixel(p_cercle->center->pos_x + x,
                          p_cercle->center->pos_y + y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x + y,
                          p_cercle->center->pos_y + x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x - x,
                          p_cercle->center->pos_y + y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x - y,
                          p_cercle->center->pos_y + x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x + x,
                          p_cercle->center->pos_y - y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x + y,
                          p_cercle->center->pos_y - x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x - x,
                          p_cercle->center->pos_y - y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x - y,
                          p_cercle->center->pos_y - x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (p_cercle->radus - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_rectangle(Shape * shape, list * lst) {

  return;
}

void pixel_square(Shape * shape, list * lst) {
  Squar *p_sqaure = (Squar *) shape->ptrShape;
  int px1, py1, px2, py2, px3, py3, px4, py4;
  int x, y, dx,dy, length;
  Line l1, l2, l3, l4;

  px1 = p_sqaure->p1->pos_x;
  py1 = p_sqaure->p1->pos_y;
  length = p_sqaure->length;

  draw_segment(x,y, dx,dy, shape->color, lst);
  draw_segment(x,y, dx,dy, shape->color, lst);
  draw_segment(x,y, dx,dy, shape->color, lst);
  draw_segment(x,y, dx,dy, shape->color, lst);

}

void pixel_polygon(Shape * shape, list * lst) {

}
