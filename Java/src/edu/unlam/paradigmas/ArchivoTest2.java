package edu.unlam.paradigmas;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

public class ArchivoTest2 {

	@Test
	public void testUno() {
		Archivos2 resolucion = new Archivos2("falopa");
		int arhivoLeido[] = resolucion.leerArchivo();


		try {
			System.out.println(Arrays.toString(arhivoLeido));

		} catch (Exception e) {

			Assert.fail();
		}
	}

}
