public class HiloParImpar implements Runnable
{
    private int tipo;
    
    public HiloParImpar(int tipo)
    {
        this.tipo = tipo;
    }//Fin metodo
    //-------------------------------------------------------------------------
    public void run()
    {
        if(tipo == 1)
        {
            for(int i = 2 ; i <= 100;i += 2)
            {
                System.out.println("El hilo con id "+Thread.currentThread().getId()+" generando numero par: "+i);
            }
        }
        else
        {
            for(int i = 101 ; i <= 200;i +=2)
            {
                System.out.println("El hilo con id "+Thread.currentThread().getId()+" generando numero impar: "+i);
            }
        }
    }//fin metodo
}//Fin clase
