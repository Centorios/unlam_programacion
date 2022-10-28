package ListaDePacientes;

public class ListaDePacientes {
    int posicionEnLaLista = 0;
    Paciente[] Lista;

    public ListaDePacientes(int cantidadMaximaDePacientes) {
        if (cantidadMaximaDePacientes <= 0) {
            throw new Error("La cantidad tiene que ser mayor que 0");
        }
        this.Lista = new Paciente[cantidadMaximaDePacientes];
    }

    public String nombrePaciente(int i) {
        return this.Lista[i].nombre;
    }

    public void insertarPaciente(Paciente paciente) {
        if (posicionEnLaLista >= Lista.length-1) {
            throw new Error("Cantidad maxima alcanzada");
        }
        this.Lista[posicionEnLaLista] = paciente;
        posicionEnLaLista++;
    }

    public int contarPacientesDelDia() {
        return posicionEnLaLista;

    }

    public int tiempoDeEspera() {

        int contador = 0;
        for (int i = 0; i < posicionEnLaLista; i++) {
            contador += this.Lista[i].duracionVisita;

        }

        return contador;

    }



}
