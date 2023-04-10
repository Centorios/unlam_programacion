package edu.unlam.paradigmas;       
public class contador {
    private int cont=0;

    public void resetear () {
        this.cont=0;
    }
    public void contar() {
        this.cont++;    
    }
    public int mostrar() {
        return this.cont;
    }
}