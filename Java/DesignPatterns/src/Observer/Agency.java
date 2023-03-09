package Observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Agency {

    private static String news;
    private final List<Channel> channels = new ArrayList<>();

    public void addObserver(Channel channel) {
        this.channels.add(channel);
    }

    public void removeObserver(Channel channel) {
        this.channels.remove(channel);
    }

    public void setNews(String news) {
        Agency.news = news;
    }

    public String getNews() {
        return news;
    }

    public void notifyObservers() {
        for (Channel channel : this.channels) {
            channel.update(news);
        }
    }
}
