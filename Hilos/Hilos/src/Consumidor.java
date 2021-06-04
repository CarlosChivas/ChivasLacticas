
import java.util.logging.Level;
import java.util.logging.Logger;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author alejandro.degante
 */
public class Consumidor extends Thread {
    int id;
    Almacen almacen;
    boolean bandera;
    
    Consumidor(int id, Almacen almacen) {
        this.id = id;
        this.almacen = almacen;
        this.bandera = true;
    }
    
    @Override
    public void run() {
        System.out.println("Consumidor " + this.id);
        String producto;
        for (int i=0 ; i<5 ; i++) {
            producto = this.almacen.consumir();
            try
            {
               Runtime runTime = Runtime.getRuntime();
               
               String directorioDeEjecutable = "C:\\Users\\natal\\Desktop\\comp\\Hilos\\C++\\main.exe "+producto;
               Process process = runTime.exec(directorioDeEjecutable);
            }
            catch (Exception e)
            {
               System.out.println("Hubo un error");
            }
            System.out.println("Consume (" + this.id + "): " + producto);
            
     /*       try {
                Thread.sleep(2000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Productor.class.getName()).log(Level.SEVERE, null, ex);
            }*/
        }
    }
    
    public void detener() {
        this.bandera = false;
    }
}
