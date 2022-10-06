public class PronosticoSemanal {

    private double[] temperaturas;

    public PronosticoSemanal() {

        temperaturas = new double[7];
        for (int i = 0; i < temperaturas.length; i++) {
            temperaturas[i] = 25.0;
        }
    }

    public double obtenerTemperatura(int dia) {

        if (dia < 1 || dia > 7) {
            throw new IllegalArgumentException("El día debe estar comprendido entre 1 y 7");
        }
        return temperaturas[dia - 1];
    }

    public void pronosticarTemperatura(int dia, double temperatura) {
        if (dia < 1 || dia > 7) {
            throw new IllegalArgumentException("El día debe estar comprendido entre 1 y 7");
        }
        temperaturas[dia - 1] = temperatura;
    }

    public static void main(String args[]) {
        PronosticoSemanal p = new PronosticoSemanal();
        System.out.println(p.obtenerTemperatura(1));
        p.pronosticarTemperatura(1, 30.0);
        System.out.println(p.obtenerTemperatura(1));
    }

}
