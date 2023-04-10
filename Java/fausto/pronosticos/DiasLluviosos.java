package pronosticos;

public class DiasLluviosos {
    private boolean[] diasDelAnio = new boolean[365];

    public void registrarQueLlovioElDia(int diaDeAnio, boolean llovio) {
        if (diaDeAnio < 1 || diaDeAnio > 365) {
            throw new Error("Tiene que estar entre 1 y 365");
        }
        diasDelAnio[diaDeAnio - 1] = llovio;
    }

    public boolean consultarSiLlovioElDia(int diaDelAnio) {
        return diasDelAnio[diaDelAnio - 1];
    }

    public int contarDiasLluviosos() {
        int cantidadDeDiasQueLlovio = 0;

        for (int i = 0; i < diasDelAnio.length; i++) {

            if (diasDelAnio[i] == true) {

                cantidadDeDiasQueLlovio++;
            }
        }
        return cantidadDeDiasQueLlovio;
    }

    public int consultarCuatrimestreMasLluvioso() {
        // boolean[] diasDelAnio = new boolean[365];
        int contadorPrimerCuatrimestre = 0;
        int contadorSegundoCuatrimestre = 0;
        int contadorTercerCuatrimestre = 0;

        for (int i = 0; i < diasDelAnio.length; i++) {

            if (diasDelAnio[i] == true) {
                if (i <= 121) {
                    contadorPrimerCuatrimestre++;

                } else if (i > 121 && i <= 242) {
                    contadorSegundoCuatrimestre++;

                } else if (i > 242 && i <= 365) {
                    contadorTercerCuatrimestre++;

                }
            }
        }
        if (contadorPrimerCuatrimestre > contadorSegundoCuatrimestre
                && contadorPrimerCuatrimestre > contadorTercerCuatrimestre) {
            return 1;
        } else if (contadorSegundoCuatrimestre > contadorPrimerCuatrimestre
                && contadorSegundoCuatrimestre > contadorTercerCuatrimestre) {
            return 2;

        } else {
            return 3;
        }
    }
    public int consultarPrimerDiaConLluvia(){
        int primerDiaConLluvia = 0;

        while (diasDelAnio[primerDiaConLluvia] == false) {
            primerDiaConLluvia++;
            
        }
        return primerDiaConLluvia+1;
    }
}