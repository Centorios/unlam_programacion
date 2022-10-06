public class Aritmetica {
    private int a;
    private int b;

    public Aritmetica()
    {
        a = 0;
        b = 0;
    }

    public Aritmetica(int a, int b)
    {
        this.a = a;
        this.b = b;
    }

    public int suma(int x, int y)
    {
        return x + y;
    }

    public int suma(double x, double y)
    {
        return (int) (x + y);
    }

    public int suma()
    {
        return a + b;
    }
/*
    public static void main (String args[]) {
        Aritmetica a = new Aritmetica();
        System.out.println(a.suma(1, 2));
        Aritmetica b = new Aritmetica(4, 4);
        System.out.println(b.suma());
    }
    
*/
}
