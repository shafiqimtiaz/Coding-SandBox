package Observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Subject {

    private static String news;
    private final List<Observer> observers = new ArrayList<>();

    public void addObserver(Observer observer) {
        this.observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        this.observers.remove(observer);
    }

    public void setNews(String news) {
        Subject.news = news;
    }

    public String getNews() {
        return news;
    }

    public void notifyObservers() {
        for (Observer observer : this.observers) {
            observer.update(news);
        }
    }
}
