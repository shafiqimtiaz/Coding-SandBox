package Observer;

public class ObserverApp {
    public static void main(String[] args) {
        NewsSubject observable = new NewsSubject();
        NewsObserver observer1 = new NewsObserver("News Observer 1");
        NewsObserver observer2 = new NewsObserver("News Observer 2");
        NewsObserver observer3 = new NewsObserver("News Observer 3");

        observable.addObserver(observer1);
        observable.setNews("INFLATION");

        observable.removeObserver(observer1);
        observable.addObserver(observer2);
        observable.addObserver(observer3);
        observable.setNews("LAYOFF");
    }
}
