package edu.unlam.paradigmas;

public class cerradura {
    private int ClaveDeApertura = 1234;
    private int CantidadDeFallosConsecutivosQueLaBloquean = 3;
    private int FallosConsecutivos = 0;
    private int AperturasExitosas = 0;
    private boolean Abierto = false;

    public cerradura(int ClaveDeApertura, int CantidadDeFallosConsecutivosQueLaBloquean) {
        this.ClaveDeApertura = ClaveDeApertura;
        if (CantidadDeFallosConsecutivosQueLaBloquean <= 0) {
            throw new Error("La cantidad de fallos consecutivos no pueden ser 0 o menor");
        }
        this.CantidadDeFallosConsecutivosQueLaBloquean = CantidadDeFallosConsecutivosQueLaBloquean;
    }

    public cerradura()

    {

    }

    public boolean abrir(int ClaveDeApertura) {
        if (this.FallosConsecutivos >= this.CantidadDeFallosConsecutivosQueLaBloquean) {
            throw new Error("Bloqueado");
        }

        if (this.Abierto) {
            return true;
        }

        if (this.ClaveDeApertura == ClaveDeApertura) {
            this.CantidadDeFallosConsecutivosQueLaBloquean = 0;
            this.AperturasExitosas++;
            this.Abierto = true;
            return true;
        } else {
            this.FallosConsecutivos++;
            if (this.FallosConsecutivos >= this.CantidadDeFallosConsecutivosQueLaBloquean) {
                throw new Error("Bloqueado");
            }
            return false;
        }
    }

    public boolean estaCerrada() {
        return !this.Abierto;

    }

    public void cerrar() {
        this.Abierto = false;
    }

    public boolean estaAbierta() {
        return this.Abierto;
    }

    public boolean fueBloqueada() {
        if (this.FallosConsecutivos >= this.CantidadDeFallosConsecutivosQueLaBloquean) {
            return true;
        }
        return false;
    }

    public int contarAperturasExitosas() {
        return this.AperturasExitosas;
    }

    public int contarAperturasFallidas() {
        return this.FallosConsecutivos;
    }

}
