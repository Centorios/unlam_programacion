package mapa;

public class Mapa {
	public enum Cosas {
		ENEMIGO, FRUTA, NADA, PARED
	}

	private Cosas[][] cosas;

	public Mapa(int filas, int columnas) {
		this.cosas = new Cosas[filas][columnas];
		for (int i = 0; i < this.cosas.length; i++)
			for (int j = 0; j < this.cosas[i].length; j++)
				cosas[i][j] = Cosas.NADA;
	}

	/**
	 * Coloca la cosa en una posición del mapa. Sirve para
	 * preparar los mapas
	 * 
	 * @param cosa, la cosa a colocar
	 * @param x,    la posición donde colocar la cosa en x
	 * @param y,    la posición donde colocar la cosa en y
	 */
	public void colocar(Cosas cosa, int x, int y) {
		// completar
		this.cosas[x][y] = cosa;
	}

	public Cosas revisar(int x, int y) {
		return this.cosas[x][y];
	}

	/**
	 * Buscará la cosa más cercana desde la posición suministrada
	 * 
	 * @param cosa, la cosa a buscar. No debe ser Cosas.NADA
	 * @param x,    la posición de origen en x
	 * @param y,    la posición de origen en y
	 * @return la posicion de la cosa más cercana a x, y
	 */

	private Cosas evaluarLaCosa(int x, int y) {
		return this.cosas[x][y];
	}

	public Posicion buscarCosaMasCercana(Cosas cosa, int x, int y) {
		if (cosa.equals(Cosas.NADA)) {
			throw new Error("No se puede buscar NADA");
		}
		int limiteInfY = this.cosas[0].length - 1;
		int limiteDerX = this.cosas.length - 1;
		// int limiteSupY = 0;
		// int limiteIzqX = 0;
		// completar, evitando utilizar "fuerza bruta"
		System.out.println("Limite inferior y: " + limiteInfY);
		System.out.println("Limite derecho x: " + limiteDerX);

		int i = x;
		int j = y;
		while (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) != cosa) {
			j--;
			while (i >= x && j < y) {
				i++;
				j++;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) == cosa) {
					Posicion resultado = new Posicion();
					resultado.x = i;
					resultado.y = j;
					return (resultado);
				}

			}
			while (i > x && j >= y) {
				j++;
				i--;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) == cosa) {
					Posicion resultado = new Posicion();
					resultado.x = i;
					resultado.y = j;
					return (resultado);
				}
			}
			while (i <= x && j > y) {
				i--;
				j--;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) == cosa) {
					Posicion resultado = new Posicion();
					resultado.x = i;
					resultado.y = j;
					return (resultado);
				}
			}
			while (i < x && j <= y) {
				j--;
				i++;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) == cosa) {
					Posicion resultado = new Posicion();
					resultado.x = i;
					resultado.y = j;
					return (resultado);
				}
			}
		}
		if (!checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0) && evaluarLaCosa(i, j) == cosa) {

			Posicion resultado = new Posicion();
			resultado.x = i;
			resultado.y = j;
			return (resultado);

		} else {
			throw new Error("No se encontro el objeto buscado");
		}
	}

	private boolean checkOutOfBounds(int i, int j, int limiteDerX, int limiteIzqX, int limiteInfY, int limiteSupY) {
		if (i <= limiteDerX && j <= limiteInfY && i >= limiteIzqX && j >= limiteSupY) {
			return true;
		} else
			return false;
	}

	/**
	 * Buscará la cosa más lejana desde la posición suministrada
	 * 
	 * @param cosa, la cosa a buscar. Puede ser Cosas.NADA
	 * @param x,    la posición de origen en x
	 * @param y,    la posición de origen en y
	 * @return la posicion de la cosa más lejana a x, y
	 */

	public Posicion buscarCosaMasLejana(Cosas cosa, int x, int y) {

		int limiteInfY = this.cosas[0].length - 1;
		int limiteDerX = this.cosas.length - 1;

		// int limiteSupY = 0;
		// int limiteIzqX = 0;
		// completar, evitando utilizar "fuerza bruta"
		System.out.println("Limite inferior y: " + limiteInfY);
		System.out.println("Limite derecho x: " + limiteDerX);

		int iRetorno = x;
		int jRetorno = y;

		int i = x;
		int j = y;
		while (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0)) {
			j--;
			while (i >= x && j < y) {
				i++;
				j++;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0)) {
					if(evaluarLaCosa(i, j)== cosa) {
						jRetorno= j;
						iRetorno=i;
					}

				}

			}
			while (i > x && j >= y) {
				j++;
				i--;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0)) {
					if(evaluarLaCosa(i, j)== cosa) {
						jRetorno= j;
						iRetorno=i;
					}
				}
			}
			while (i <= x && j > y) {
				i--;
				j--;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0)) {
					if(evaluarLaCosa(i, j)== cosa) {
						jRetorno= j;
						iRetorno=i;
					}
				}
			}
			while (i < x && j <= y) {
				j--;
				i++;
				if (checkOutOfBounds(i, j, limiteDerX, limiteInfY, 0, 0)) {
					if(evaluarLaCosa(i, j)== cosa) {
						jRetorno= j;
						iRetorno=i;
					}
				}
			}
		}
		if(jRetorno==x && iRetorno==y && cosas[iRetorno][jRetorno] == cosa){
			throw new Error("No se encontro un objeto lejano");
		} else {
			Posicion resultado = new Posicion();
			resultado.x = iRetorno;
			resultado.y = jRetorno;
			return (resultado);
		}

	}

}
