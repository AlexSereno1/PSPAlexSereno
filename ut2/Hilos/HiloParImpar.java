package Ejercicios;

/**
 *
 * @author Alex
 */
public class HiloParImpar extends Thread
{
    private int tipo;
    
    public HiloParImpar(String nombre, int tipo)
    {
        super(nombre);
        this.tipo = tipo;
    }//Fin metodo
    //-------------------------------------------------------------------------
    public void run()
    {
        if(tipo == 1)
        {
            for(int i = 2 ; i <= 100;i +=2)
            {
                System.out.println(getName()+" generando numero par : "+i);
            }
        }
        else
        {
            for(int i = 101 ; i <= 200;i +=2)
            {
                System.out.println(getName()+" generando numero impar : "+i);
            }
        }
    }//fin metodo
    //---------------------------------------------------------------------
    public static void main(String[] args) 
    {
        HiloParImpar h1 = new HiloParImpar("Hilo 1", 2);
        HiloParImpar h2 = new HiloParImpar("Hilo 2", 1);
        
        h1.start();
        h2.start();
        
    }//fin main
}//Fin clase
