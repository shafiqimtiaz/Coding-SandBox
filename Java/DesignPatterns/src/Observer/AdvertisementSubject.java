package Observer;

public class AdvertisementSubject extends Subject {
    public void setAdvertisement(String advertisement) {
        super.setSubject(advertisement);
        notifyObservers();
    }
}
