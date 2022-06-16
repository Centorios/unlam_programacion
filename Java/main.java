import java.util.Scanner;

class Ejemplo {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce un numero: ");
        int num = sc.nextInt();
        System.out.println("El numero es: " + num);
        sc.close();

    }

}