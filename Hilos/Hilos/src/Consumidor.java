
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
        while (this.bandera) {
            producto = this.almacen.consumir();
            if(producto == "Fin"){
                break;
            }
            try
            {
               Runtime runTime = Runtime.getRuntime();
               
               String directorioDeEjecutable = "C:\\Users\\Carlos\\Desktop\\ChivasLacticas\\Hilos\\C++\\main.exe "+producto;
               Process process = runTime.exec(directorioDeEjecutable);
               process.waitFor();
            }
            catch (Exception e)
            {
               System.out.println("Hubo un error");
            }
            System.out.println("Consumidor (" + this.id + ") analizó el archivo: " + producto);
        }
    }
    
    public void detener() {
        this.bandera = false;
    }
}
