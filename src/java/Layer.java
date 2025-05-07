import java.util.ArrayList;

public class Layer {
    static boolean visible;
    private int id;
    private String name;
    private ArrayList<Shape> shapes;

    public Layer(String name, int id){
        this.name = name;
        this.id = id;
        shapes = new ArrayList<>();
        visible = true;
    }

    public void setVisible(boolean new_value) {
        this.visible = new_value;
    }

    public void addShape(Shape shape) {
        shapes.add(shape);
    }

    public void removeShape(Shape shape) {
        shapes.remove(shape);
    }

    public boolean isVisible() {
        return visible;
    }

    public ArrayList<Shape> getShapes() {
        return shapes;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

}
