import mapa.Mapa;
import mapa.Posicion;

public class Main {
    public static void main(String args[]) {
        

        Mapa pepe = new Mapa(5, 5);
        pepe.colocar(Mapa.Cosas.FRUTA, 0, 0);;
        Posicion pos = pepe.buscarCosaMasLejana(Mapa.Cosas.FRUTA,3,3);

        System.out.println(pos.x);
        System.out.println(pos.y);

    }
}