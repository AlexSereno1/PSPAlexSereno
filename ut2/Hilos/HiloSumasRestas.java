
package Ejercicio2;

/**
 *
 * @author Clase
 */
public class HiloSumasRestas extends Thread
{
    private int numvec;
    private String operacion;
    private int numero = 1000;
    
    public HiloSumasRestas(String nombre,int numvec,String operacion)
    {
        super(nombre);
        this.numvec = numvec;
        this.operacion = operacion;
    }
    //---------------------------------
    public void run ()
    {
        if(operacion == "+")
            incrementar();
        else if(operacion == "-")
            decrementar();
        else
            System.out.println("Error al introducir la operación");
    }
    //--------------------------------------
    public void incrementar()
    {
        numero += numvec;
        System.out.println("El numero del "+ getName()+" es: "+numero);
    }
    //-----------------------------------
    public void decrementar()
    {
        numero -= numvec;
        System.out.println("El numero del "+ getName()+" es: "+numero);
    }
   
}
