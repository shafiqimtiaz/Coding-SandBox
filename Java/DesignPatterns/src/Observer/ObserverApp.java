package Observer;

public class ObserverApp {
    public static void main(String[] args) {
        NewsAgency observable = new NewsAgency();
        NewsChannel observer1 = new NewsChannel("News Channel 1");
        NewsChannel observer2 = new NewsChannel("News Channel 2");

        observable.addObserver(observer1);
        observable.setNews("INFLATION");

        observable.removeObserver(observer1);
        observable.addObserver(observer2);
        observable.setNews("LAYOFF");
    }
}
