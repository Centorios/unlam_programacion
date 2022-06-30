public class Empleado extends Persona {
    private String cargo;

    public Empleado(String nombre, String apellido, int edad, String cargo) {
        super(nombre, apellido, edad);
        this.cargo = cargo;
    }


    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

}
