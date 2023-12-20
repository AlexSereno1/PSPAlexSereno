
package Ejercicio2;

import Ejercicio2.HiloSumasRestas;

/**
 *
 * @author Clase
 */
public class HiloSumasRestasEjecutar 
{
    public static void main(String[] args) 
    {
        HiloSumasRestas h1 = new HiloSumasRestas("Hilo 1",100,"+");
        HiloSumasRestas h2 = new HiloSumasRestas("Hilo 2",100,"-");
        HiloSumasRestas h3 = new HiloSumasRestas("Hilo 3",1,"+");
        HiloSumasRestas h4 = new HiloSumasRestas("Hilo 4",1,"-");
        
        h1.start();
        h2.start();
        h3.start();
        h4.start();

    }
}
