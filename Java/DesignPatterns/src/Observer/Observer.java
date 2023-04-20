package Observer;

import java.util.ArrayList;
import java.util.List;

public interface Observer {
    List<Subject> subjects = new ArrayList<>();

    void update(Object o);
}
