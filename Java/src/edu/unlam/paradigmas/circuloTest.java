package edu.unlam.paradigmas;


import org.junit.Assert;
import org.junit.Test;

public class circuloTest {
    
    @Test
    public void testArea() {
        circulo c = new circulo(2);
        Assert.assertEquals(12.566370614359172, c.calcularArea(), 0.000000000000001);
    }
     
}
