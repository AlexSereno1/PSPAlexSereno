public class HiloParImparEjecutar 
{
    public static void main(String[] args) 
    {
        HiloParImpar h1 = new HiloParImpar("Hilo 1", 2);
        HiloParImpar h2 = new HiloParImpar("Hilo 2", 1);
        
        h1.start();
        h2.start();
        
    }//fin main
}//fin clase
