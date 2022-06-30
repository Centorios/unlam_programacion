public class Caja {
    private int ancho;
    private int alto;
    private int profundidad;

    Caja() {
        ancho = 1;
        alto = 1;
        profundidad = 1;
    }

    Caja(int ancho, int alto, int profundidad) {
        this.ancho = ancho;
        this.alto = alto;
        this.profundidad = profundidad;
    }

    public int getVolume() {
        return ancho * alto * profundidad;
    }

    public int getVolume(int ancho, int alto, int profundidad) {
        return ancho * alto * profundidad;
    }

    public void setAncho(int ancho) {
        this.ancho = ancho;
    }

    public void setAlto(int alto) {
        this.alto = alto;
    }

    public void setProfundidad(int profundidad) {
        this.profundidad = profundidad;
    }

    public int getAncho() {
        return ancho;
    }

    public int getAlto() {
        return alto;
    }

    public int getProfundidad() {
        return profundidad;
    }

/*    public static void main(String[] args) {
        Caja caja = new Caja();
        System.out.println(caja.getVolume());
        Caja caja2 = new Caja(2, 2, 2);
        System.out.println(caja2.getVolume());
        Caja caja3 = new Caja(3, 3, 3);
        System.out.println(caja3.getVolume(1, 2, 3));
    }
*/

}
