/**
 * Class Square
 */
public class Square extends Shape {

  //
  // Fields
  //

  private Point p1;
  private int length;
  
  //
  // Constructors
  //
  public Square(Point p1, int length) {
    this.p1 = p1;
    this.length = length;
  }

  
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
   * Set the value of length
   * @param newVar the new value of length
   */
  public void setLength (int newVar) {
    length = newVar;
  }

  /**
   * Get the value of length
   * @return the value of length
   */
  public int getLength () {
    return length;
  }

  //
  // Other methods
  //

  /**
   * @return
   */
  public String print()
  {
    return "p1 : " + p1.print() + "\nlength : " + length;
  }


}
