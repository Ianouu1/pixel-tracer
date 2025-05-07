

/**
 * Class Rectangle
 */
public class Rectangle extends Shape{

  //
  // Fields
  //

  private Point p1;
  private int width;
  private int height;
  
  //
  // Constructors
  //
  public Rectangle (Point p1, int width, int height) {
    this.p1 = p1;
    this.width = width;
    this.height = height;
  };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of p1
   * @param newVar the new value of p1
   */
  public void setP1 (Point newVar) {
    p1 = newVar;
  }

  /**
   * Get the value of p1
   * @return the value of p1
   */
  public Point getP1 () {
    return p1;
  }

  /**
   * Set the value of width
   * @param newVar the new value of width
   */
  public void setWidth (int newVar) {
    width = newVar;
  }

  /**
   * Get the value of width
   * @return the value of width
   */
  public int getWidth () {
    return width;
  }

  /**
   * Set the value of height
   * @param newVar the new value of height
   */
  public void setHeight (int newVar) {
    height = newVar;
  }

  /**
   * Get the value of height
   * @return the value of height
   */
  public int getHeight () {
    return height;
  }

  //
  // Other methods
  //

  /**
   * @return
   */
  public String print()
  {
    return "p1 : " + p1.print() + "\nwidth : " + width + "\nheight : " + height;
  }


}
