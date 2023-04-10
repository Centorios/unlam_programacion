package edu.unlam.paradigmas;

public class arandela {
    private circulo radioInterno;
    private circulo radioExterno;

    public arandela(double radioCirculoInterno, double radioCirculoExterno) {
        if (radioCirculoInterno < 0 || radioCirculoExterno < 0) {
            throw new IllegalArgumentException("El radio no puede ser negativo o 0");
        }
        this.radioInterno = new circulo(radioCirculoInterno);
        this.radioExterno = new circulo(radioCirculoExterno);
    }

    public arandela(circulo circuloInterno, circulo circuloExterno) {
        this.radioInterno = circuloInterno;
        this.radioExterno = circuloExterno;
    }

    public double calcularArea() {
        return this.radioExterno.calcularArea() - this.radioInterno.calcularArea();
    }

}
