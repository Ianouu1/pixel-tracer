

/**
 * Class Shape
 */
public abstract class Shape {

  //
  // Fields
  //
  private static int nextId = 1;

  int id;
  ShapeType type;
  Object content;  // peut être Point, Line, etc.
  String color = "BLACK";
  float thickness = 1.0f;
  float rotation = 0.0f;
  protected boolean fill;
  
  //
  // Constructors
  //
  public Shape(ShapeType type, Object content) {
    this.id = nextId++;
    this.type = type;
    this.content = content;
  }

  public Shape() {
  }

  //
  // Methods
  //
  public static Shape createPointShape(int x, int y) {
    return new Point(x, y);
  }

  public static Shape createLineShape(int x1, int y1, int x2, int y2) {
    return new Line(new Point(x1, y1), new Point(x2, y2));
  }

  public static Shape createSquareShape(int x, int y, int length) {
    return new Square(new Point(x, y), length);
  }

  public static Shape createRectangleShape(int x, int y, int w, int h) {
    return new Rectangle(new Point(x, y), w, h);
  }

  public static Shape createCircleShape(int x, int y, int r) {
    return new Circle(new Point(x, y), r);
  }

  public static Shape createPolygonShape(int[] coords) {
    if (coords.length % 2 != 0) return null;
    Polygon poly = new Polygon(coords.length / 2);
    for (int i = 0; i < coords.length; i += 2) {
      poly.addPoint(new Point(coords[i], coords[i + 1]));
    }
    return poly;
  }

  public static Shape createCurveShape(int[] coords) {
    if (coords.length != 8) return null;
    return new Curve(
            new Point(coords[0], coords[1]),
            new Point(coords[2], coords[3]),
            new Point(coords[4], coords[5]),
            new Point(coords[6], coords[7])
    );
  }

  //
  // Accessor methods
  //

  /**
   * Set the value of id
   * @param newVar the new value of id
   */
  public void setId (int newVar) {
    id = newVar;
  }

  /**
   * Get the value of id
   * @return the value of id
   */
  public int getId () {
    return id;
  }

  /**
   * Set the value of fill
   * @param newVar the new value of fill
   */
  public void setFill (boolean newVar) {
    fill = newVar;
  }

  /**
   * Get the value of fill
   * @return the value of fill
   */
  public boolean getFill () {
    return fill;
  }

  /**
   * Set the value of color
   * @param newVar the new value of color
   */
  public void setColor (String newVar) {
    color = newVar;
  }

  /**
   * Get the value of color
   * @return the value of color
   */
  public String getColor () {
    return color;
  }

  //
  // Other methods
  //

  /**
   */
  public String print_shape()
  {
    return this.print();
  }


  public abstract String print();

}
