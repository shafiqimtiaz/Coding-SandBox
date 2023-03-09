package Observer;

public class NewsAgency extends Agency {
    public void setNews(String news) {
        super.setNews(news);
        notifyObservers();
    }
}
