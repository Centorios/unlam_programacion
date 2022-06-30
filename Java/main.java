public class Main {
    public static void main(String[] args) {
        Persona pepe = new Persona();
        Persona juan = new Persona("Juan", "Perez", 30);
        pepe.getPersonaAtt();
        juan.getPersonaAtt();
        System.out.println(Persona.getContadorDePersonas());
    }
}
