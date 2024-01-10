
public class HiloSumasRestas implements Runnable
{
    private int numvec;
    private String operacion;
    private int numero = 1000;
    
    public HiloSumasRestas(int numvec,String operacion)
    {
        this.numvec = numvec;
        this.operacion = operacion;
    }
    //---------------------------------
    public void run ()
    {
        if(operacion.equals("+"))
            incrementar();
        else if(operacion.equals("-"))
            decrementar();
        else
            System.out.println("Error al introducir la operación");
    }
    //--------------------------------------
    public void incrementar()
    {
        numero += numvec;
        System.out.println("El numero del hilo con id "+Thread.currentThread().getId() +" es: "+numero);
    }
    //-----------------------------------
    public void decrementar()
    {
        numero -= numvec;
        System.out.println("El numero del hilo con id "+ Thread.currentThread().getId()+" es: "+numero);
    }
   
}
