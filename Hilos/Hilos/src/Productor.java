
import java.io.File;
import java.util.Random;
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
public class Productor extends Thread{
    int id;
    Almacen almacen;
    
    Productor(int id, Almacen almacen) {
        this.id = id;
        this.almacen = almacen;
    }
    
    File[] getArchivos() {
        File directorio = new File("C:\\Users\\Carlos\\Desktop\\ChivasLacticas\\Hilos\\Archivos");
        File[] archivos = directorio.listFiles();
        return archivos;
    }
    
    @Override
    synchronized public void run() {
        System.out.println("Productor " + this.id);
        
        File[] productos = getArchivos();
      
        for (int i=0 ; i<productos.length ; i++) {
            this.almacen.producir(productos[i].toString());
        }
        detener();
    }
    
    synchronized void detener() {
        this.almacen.end();
        notifyAll();
    }
}
