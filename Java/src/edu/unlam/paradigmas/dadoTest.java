package edu.unlam.paradigmas;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

public class dadoTest {
    
    @Test
    public void testRollear() {
        dado d = new dado(6);
        for (int i = 0; i < 9999999; i++) {
            int value = d.rollear();
            Assert.assertTrue(value >= 1 && value <= d.tipoDeDado());
        }
        
    }
     
    @Test
    public void testDistribucion() {
        int distribucion [] = new int[6];
        dado d = new dado(6);
        for (int i = 0; i < 9999999; i++) {
            distribucion[d.rollear()-1]++;
        }
        System.out.println("Distribucion:");
        System.out.println(Arrays.toString(distribucion));
    }
}
