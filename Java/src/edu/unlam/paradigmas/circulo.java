package edu.unlam.paradigmas;

public class circulo {
    private double radius=1;

    public circulo(double a) {
        if (a < 0) {
            throw new IllegalArgumentException("El radio no puede ser negativo o 0");
        }
        this.radius = a;
    }

    public double calcularArea() {
        return this.radius * this.radius * Math.PI;
    }
}
