package Observer;

public class NewsChannel implements Channel {
    private String news;
    private final String name;

    public NewsChannel(String name) {
        this.name = name;
    }

    @Override
    public void update(Object news) {
        this.setNews(news.toString());
        System.out.println(name + " published: " + news);
    }

    public String getName() {
        return name;
    }

    public String getNews() {
        return news;
    }

    public void setNews(String news) {
        this.news = news;
    }
}
