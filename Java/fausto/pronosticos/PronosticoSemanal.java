package pronosticos;

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
            throw new Error("ALgo estuvo mal");
        }
        return temperaturas[dia - 1];
    }

    public void pronosticarTemperatura(int dia, double temperatura) {
        if (dia < 1 || dia > 7) {
            throw new Error("ALgo estuvo mal");
        }
        temperaturas[dia - 1] = temperatura;
    }

    public double calcularPromedioDeTemperaturas() {
        double sumaTemperaturas = 0;

        for (int i = 0; i < temperaturas.length; i++) {

            sumaTemperaturas += temperaturas[i];
        }
        return (sumaTemperaturas / temperaturas.length);
    }

    public double buscarMaximaTemperatura() {
        double temperaturaMax = 0;
        for (int i = 0; i < temperaturas.length; i++) {
            if (temperaturaMax < temperaturas[i]) {
                temperaturaMax = temperaturas[i];
            }
        }
        return temperaturaMax;
    }
    public double buscarMinimaTemperatura() {
        double temperaturamin = temperaturas[0];
        for (int i = 0; i < temperaturas.length; i++) {
            if (temperaturamin > temperaturas[i]) {
                temperaturamin = temperaturas[i];
            }
        }
        return temperaturamin;
    }

}
