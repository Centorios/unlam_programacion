import pronosticos.DiasLluviosos;

public class Main {
    public static void main(String args[]) {
        DiasLluviosos carlos = new DiasLluviosos();
        carlos.registrarQueLlovioElDia(7, true);
        System.out.println("Llovio : " + carlos.consultarSiLlovioElDia(7));
        System.out.println("Cantidad de dias que llovieron: " + carlos.contarDiasLluviosos());
        System.out.println(carlos.consultarCuatrimestreMasLluvioso());
        System.out.println(carlos.consultarPrimerDiaConLluvia());
    }
}
