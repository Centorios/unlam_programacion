package  edu.unlam.paradigmas;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class contadorTest {
    
        @Test
        public void testContador() {
            contador c = new contador();
            c.contar();
            c.contar();
            c.contar();
            assertEquals(3, c.mostrar());
        }
    
        @Test
        public void testResetear() {
            contador c = new contador();
            c.contar();
            c.contar();
            c.contar();
            c.resetear();
            assertEquals(0, c.mostrar());
        }
}
