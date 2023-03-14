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
    case CURVE:
        pixel_curve(shape, lst);
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

void draw_segment(int x, int y, int dx, int dy, Color color, list * lst) {
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
    y = p_line->p1->pos_y;
    dx = p_line->p2->pos_x - p_line->p1->pos_x;
    dy = p_line->p2->pos_y - p_line->p1->pos_y;
    draw_segment(x, y, dx, dy, shape->color, lst);
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
    int x, y, dx, dy, length;
    Line l1, l2, l3, l4;

    x = p_sqaure->p1->pos_x;
    y = p_sqaure->p1->pos_y;
    length = p_sqaure->length;

    x = x;
    y = y;
    dx = length;
    dy = 0;
    draw_segment(x, y, dx, dy, shape->color, lst);

    x = x;
    y = y;
    dx = 0;
    dy = length;
    draw_segment(x, y, dx, dy, shape->color, lst);

    x = x;
    y = y + length;
    dx = length;
    dy = 0;
    draw_segment(x, y, dx, dy, shape->color, lst);

    x = x + length;
    y = y;
    dx = 0;
    dy = length;;
    draw_segment(x, y, dx, dy, shape->color, lst);

}

void pixel_polygon(Shape * shape, list * lst) {
    // TODO : 
}


Point calc_point_median(Point * p1, Point * p2, double t) {
    double x = p1->pos_x * (1 - t) + p2->pos_x * t;
    double y = p1->pos_y * (1 - t) + p2->pos_y * t;
    Point result = { x, y };
    return result;
}

// Fonction pour calculer un point sur une courbe de Bézier à l'aide de l'algorithme de Casteljau
Point cj_calc(Point ** points, int numPoints, double t) {
    Point tempPoints[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        tempPoints[i] = *points[i];
    }
    for (int i = numPoints - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            tempPoints[j] =
                calc_point_median(&tempPoints[j], &tempPoints[j + 1], t);
        }
    }
    return tempPoints[0];
}


void pixel_curve(Shape * shape, list * lst) {
    Curve *p_curve = (Curve *) shape->ptrShape;
    Point *points[] =
        { p_curve->p1, p_curve->p2, p_curve->p3, p_curve->p4 };
    int numPoints = sizeof(points) / sizeof(Point);
    double t = 0;

    for (t = 0; t < 1.0; t = t + 0.02) {
        Point cjp1 = cj_calc(points, numPoints, t);
        Point cjp2 = cj_calc(points, numPoints, t + 0.01);
        int dx, dy, x, y;
        x = cjp1.pos_x;
        y = cjp1.pos_y;
        dx = cjp2.pos_x - cjp1.pos_x;
        dy = cjp2.pos_y - cjp1.pos_y;
        draw_segment(x, y, dx, dy, shape->color, lst);
    }
}
