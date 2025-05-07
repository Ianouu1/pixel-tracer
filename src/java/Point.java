

/**
 * Class Point
 */
public class Point extends Shape {

  //
  // Fields
  //

  private int px;
  private int py;
  
  //
  // Constructors
  //
  public Point(int x, int y) {
    this.px = x;
    this.py = y;
  }


  //
  // Methods
  //


  //
  // Accessor methods
  //

  /**
   * Set the value of px
   * @param newVar the new value of px
   */
  public void setPx (int newVar) {
    px = newVar;
  }

  /**
   * Get the value of px
   * @return the value of px
   */
  public int getPx () {
    return px;
  }

  /**
   * Set the value of py
   * @param newVar the new value of py
   */
  public void setPy (int newVar) {
    py = newVar;
  }

  /**
   * Get the value of py
   * @return the value of py
   */
  public int getPy () {
    return py;
  }

  //
  // Other methods
  //

  /**
   * @return
   */

  public String print(){
    return "(px : " + px + " - py : " + py + ")";
  }


}
