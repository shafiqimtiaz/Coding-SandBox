package Observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Subject {

    private static String subject;
    private final List<Observer> observers = new ArrayList<>();

    public void addObserver(Observer observer) {
        this.observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        this.observers.remove(observer);
    }

    public void setSubject(String subject) {
        Subject.subject = subject;
    }

    public String getSubject() {
        return subject;
    }

    public void notifyObservers() {
        for (Observer observer : this.observers) {
            observer.update(subject);
        }
    }
}
