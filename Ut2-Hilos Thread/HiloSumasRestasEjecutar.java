public class HiloSumasRestasEjecutar 
{
    public static void main(String[] args) 
    {
        HiloSumasRestas h1 = new HiloSumasRestas("Hilo1",100,"+");
        h1.start(); 
        
        HiloSumasRestas h2 = new HiloSumasRestas("Hilo2",100,"-");
        h2.start();
        
        HiloSumasRestas h3 = new HiloSumasRestas("Hilo3",1,"+");
        h3.start();
        
        HiloSumasRestas h4 = new HiloSumasRestas("Hilo4",1,"-");
        h4.start();
    }
}
