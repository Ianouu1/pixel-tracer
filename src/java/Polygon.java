import java.util.Arrays;

/**
 * Class Polygon
 */
public class Polygon {

  //
  // Fields
  //

  private int n;
  private Point[] points;
  
  //
  // Constructors
  //
  public Polygon () { };
  
  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of n
   * @param newVar the new value of n
   */
  public void setN (int newVar) {
    n = newVar;
  }

  /**
   * Get the value of n
   * @return the value of n
   */
  public int getN () {
    return n;
  }

  /**
   * Set the value of points
   * @param newVar the new value of points
   */
  public void setPoints (Point[] newVar) {
    points = newVar;
  }

  /**
   * Get the value of points
   * @return the value of points
   */
  public Point[] getPoints () {
    return points;
  }

  //
  // Other methods
  //

  /**
   */
  public void print()
  {
    System.out.println("n : " + n);
    System.out.println("points : " + Arrays.toString(points));
  }


}
