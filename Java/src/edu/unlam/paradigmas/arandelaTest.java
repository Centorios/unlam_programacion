package edu.unlam.paradigmas;


import org.junit.Assert;
import org.junit.Test;

public class arandelaTest {
    
    @Test
    public void testAreaArandela() {
        arandela a = new arandela(2, 4);
        Assert.assertEquals(37.69911184307752, a.calcularArea(), 0.000000000000001);
    }
     
}
