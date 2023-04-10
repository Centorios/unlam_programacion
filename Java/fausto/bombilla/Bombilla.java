package bombilla;

public class Bombilla {
    private boolean estate = false;

    public void encender() {
        this.estate = true;
    }

    public void apagar() {
        this.estate = false;
    }

    public boolean getEstate() {
        return this.estate;
    }

}
