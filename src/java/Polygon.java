import java.util.ArrayList;
import java.util.Arrays;

/**
 * Class Polygon
 */
public class Polygon extends Shape {

  //
  // Fields
  //

  private int n;
  private ArrayList<Point> points;
  
  //
  // Constructors
  //
  public Polygon(ArrayList<Point> pointsList) {
    points = pointsList;
  }

  public Polygon(int n) {
    points = new ArrayList<Point>(n);
  }
  public Polygon(int n, int[] xandy) {
    points = new ArrayList<Point>(n);
    try {
      for (int i = 0; i < n * 2; i += 2) { // n*2 parce que x et y sont stockés dans le même tableau
        System.out.println();
        points.add(new Point(xandy[i], xandy[i + 1]));
      }
      this.n = n;
    } catch (Exception e) {
      System.out.println("Taille du tableau et cordonnées des points incohérentes : " + e);
    }
  }



  //
  // Methods
  //
  public void addPoint(Point p) {
    points.add(p);
  }

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
  public void setPoints (ArrayList<Point> newVar) {
    points = newVar;
  }

  /**
   * Get the value of points
   * @return the value of points
   */
  public ArrayList<Point> getPoints () {
    return points;
  }

  //
  // Other methods
  //

  /**
   * @return
   */
  public String print()
  {
    StringBuilder sb = new StringBuilder();
    sb.append("points :\n");
    for (Point point : points) {
      sb.append(point.print()).append("\n");
    }
    sb.append("n : ").append(n);
    return sb.toString();
  }


}
