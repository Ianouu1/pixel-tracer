import java.util.ArrayList;
import java.util.List;

public class AreaList {
    private List<Area> areas;

    public AreaList() {
        areas = new ArrayList<>();
    }

    public void addArea(Area area) {
        areas.add(area);
    }

    public void removeArea(Area area) {
        areas.remove(area);
    }

    public void clear() {
        areas.clear();
    }

    public List<Area> getAreas() {
        return areas;
    }
}
