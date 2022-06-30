public class Persona {
    private String nombre;
    private String apellido;
    private int edad;
    static int contadorDePersonas;
    private int id;

    public void getPersonaAtt() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Apellido: " + apellido);
        System.out.println("Edad: " + edad);
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getNombre() {
        return nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public int getEdad() {
        return edad;
    }

    public int getId() {
        return id;
    }

    public static int getContadorDePersonas() {
        return contadorDePersonas;
    }

    Persona() {
        contadorDePersonas++;
        this.id = contadorDePersonas;
    }

    Persona(String nombre, String apellido, int edad) {
        this(); //esto llama al constructor de arriba, el vacio
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;

    }

    /*
     * public static void main(String[] args) {
     * 
     * Persona pepe = new Persona();
     * Persona juan = new Persona("Juan", "Perez", 30);
     * pepe.getPersonaAtt();
     * juan.getPersonaAtt();
     * }
     */

}
