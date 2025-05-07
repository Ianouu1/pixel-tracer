class Main{
    public static void main(String[] args) {
        System.out.println(" Shapes ");

        Shape[] shapes = new Shape[8]; // tableau de 8 shapes (area)
        shapes[0] = new Circle(10, 5, 4);
        shapes[1] = new Point(4, 8);
        shapes[2] = new Circle(41, 65, 40);
        shapes[3] = new Line(new Point(4,8), new Point(6,10));
        shapes[4] = new Curve(new Point(4,8), new Point(6,10), new Point(7,12), new Point(8,14));
        int[] coordsForPolygon = {4, 8, 6, 10, 7, 12, 8, 14};
        shapes[5] = new Polygon(4, coordsForPolygon);
        shapes[6] = new Rectangle(new Point(4,8), 10, 20);
        shapes[7] = new Square(new Point(4,8), 10);
        // print toutes les shapes
        for (int i = 0; i < shapes.length; i++) {
            System.out.println("--------[" + shapes[i].getClass().getSimpleName() + "]--------");
            System.out.println(shapes[i].print_shape());
        }
        System.out.println("------------------------");

    }

}