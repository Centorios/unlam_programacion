import org.junit.Assert;
import org.junit.Test;
import ListaDePacientes.ListaDePacientes;
import ListaDePacientes.Paciente;

public class apptest {

    @Test
    public void cantidadPacientes3() {
        ListaDePacientes lista = new ListaDePacientes(3);
        lista.insertarPaciente((new Paciente("Juan", 10)));
        lista.insertarPaciente((new Paciente("Pedro", 20)));
        lista.insertarPaciente((new Paciente("Maria", 30)));

        Assert.assertEquals(3, lista.contarPacientesDelDia());
    }

    @Test
    public void tiempoEspera1Hora() {
        ListaDePacientes lista = new ListaDePacientes(3);
        lista.insertarPaciente((new Paciente("Juan", 10)));
        lista.insertarPaciente((new Paciente("Pedro", 20)));
        lista.insertarPaciente((new Paciente("Maria", 30)));

        Assert.assertEquals(60, lista.tiempoDeEspera());
    }

    @Test(expected = Error.class)
    public void personaDemas() {
        ListaDePacientes lista = new ListaDePacientes(3);
        lista.insertarPaciente((new Paciente("Juan", 10)));
        lista.insertarPaciente((new Paciente("Pedro", 20)));
        lista.insertarPaciente((new Paciente("Maria", 30)));
        lista.insertarPaciente((new Paciente("Maria", 30)));
    }
}
