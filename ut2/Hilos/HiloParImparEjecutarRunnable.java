public class HiloParImparEjecutar 
{
    public static void main(String[] args) 
    {
        HiloParImpar h1 = new HiloParImpar( 2);
        Thread t1 = new Thread(h1);
        t1.start(); 
        
        HiloParImpar h2 = new HiloParImpar( 1);
        Thread t2 = new Thread(h2);
        t2.start();
    }//fin main
}//fin clase
