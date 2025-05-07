public class Area {
    private int width;
    private int height;
    private int id;
    private String name;
    private char[][] area;
    private LayerList lstLayers;
    private char emptyChar;
    private char fullChar;

    public Area(int width, int height, int id, String name) {
        this.width = width;
        this.height = height;
        this.id = id;
        this.name = name;
        this.lstLayers = new LayerList(); // Assure-toi que cette classe existe

        // Initialisation de la matrice
        this.area = new char[height][width];
    }

    public void fillArea(char fillChar) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                area[i][j] = fillChar;
            }
        }
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public char[][] getArea() {
        return area;
    }

    public void setArea(char[][] area) {
        this.area = area;
    }

    public LayerList getLstLayers() {
        return lstLayers;
    }

    public void setLstLayers(LayerList lstLayers) {
        this.lstLayers = lstLayers;
    }

    public char getEmptyChar() {
        return emptyChar;
    }

    public void setEmptyChar(char emptyChar) {
        this.emptyChar = emptyChar;
    }

    public char getFullChar() {
        return fullChar;
    }

    public void setFullChar(char fullChar) {
        this.fullChar = fullChar;
    }

}
