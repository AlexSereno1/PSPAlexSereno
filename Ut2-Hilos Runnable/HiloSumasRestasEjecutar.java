public class HiloSumasRestasEjecutar 
{
    public static void main(String[] args) 
    {
        HiloSumasRestas h1 = new HiloSumasRestas(100,"+");
        Thread t1 = new Thread(h1);
        t1.start(); 
        
        HiloSumasRestas h2 = new HiloSumasRestas(100,"-");
        Thread t2 = new Thread(h2);
        t2.start();
        
        HiloSumasRestas h3 = new HiloSumasRestas(1,"+");
        Thread t3 = new Thread(h3);
        t3.start();
        
        HiloSumasRestas h4 = new HiloSumasRestas(1,"-");
        Thread t4 = new Thread(h4);
        t4.start();
    }
}
