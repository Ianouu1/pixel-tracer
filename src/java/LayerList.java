import java.util.ArrayList;
import java.util.List;

public class LayerList {
    private List<Layer> layers;

    public LayerList() {
        this.layers = new ArrayList<>();
    }

    public void addLayer(Layer layer) {
        layers.add(layer);
    }

    public void removeLayer(Layer layer) {
        layers.remove(layer);
    }

    public List<Layer> getLayers() {
        return layers;
    }
}
