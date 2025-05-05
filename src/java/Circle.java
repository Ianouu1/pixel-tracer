

/**
 * Class Circle
 */
public class Circle {

  //
  // Fields
  //

  private Point center;
  private int radius;
  
  //
  // Constructors
  //
  public Circle () { };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of center
   * @param newVar the new value of center
   */
  public void setCenter (Point newVar) {
    center = newVar;
  }

  /**
   * Get the value of center
   * @return the value of center
   */
  public Point getCenter () {
    return center;
  }

  /**
   * Set the value of radius
   * @param newVar the new value of radius
   */
  public void setRadius (int newVar) {
    radius = newVar;
  }

  /**
   * Get the value of radius
   * @return the value of radius
   */
  public int getRadius () {
    return radius;
  }

  //
  // Other methods
  //

  /**
   */
  public void print()
  {
    System.out.println("center radius : " + center + radius);
  }


}
