
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
    boolean bandera;
    
    Productor(int id, Almacen almacen) {
        this.id = id;
        this.almacen = almacen;
        this.bandera = true;
    }
    
    File[] getArchivos() {
        File directorio = new File("C:\\Users\\natal\\Desktop\\comp\\Hilos\\Archivos");
        File[] archivos = directorio.listFiles();
        for(File f : archivos) {
            String nombre = f.getName();
            System.out.println(nombre);
        }
        return archivos;
    }
    
    @Override
    public void run() {
        //getArchivos();
        System.out.println("Productor " + this.id);
        //String productos = "AEIOU";
        long tiempo1 = System.currentTimeMillis();
        
        File[] productos = getArchivos();
       // Random r = new Random(System.currentTimeMillis());
        String producto;
        int leng = productos.length;
        for (int i=0 ; i<leng ; i++) {
            //System.out.println(productos[r.nextInt(productos.length)].toString());
            producto = productos[i].toString();
            this.almacen.producir(producto);
            System.out.println("Produce (" + this.id + "): " + producto);
            /*try {
                Thread.sleep(5000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Productor.class.getName()).log(Level.SEVERE, null, ex);
            }*/
        }
    }
    
    public void detener() {
        this.bandera = false;
    }
}
