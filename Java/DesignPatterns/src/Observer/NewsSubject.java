package Observer;

public class NewsSubject extends Subject {
    public void setNews(String news) {
        super.setSubject(news);
        notifyObservers();
    }
}
