package Observer;

public class NewsSubject extends Subject {
    public void setNews(String news) {
        super.setNews(news);
        notifyObservers();
    }
}
