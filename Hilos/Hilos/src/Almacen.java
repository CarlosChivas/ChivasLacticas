
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
public class Almacen {
    private String espacio;
    private Boolean end;
    Almacen() {
        this.espacio = "";
        this.end = false;
    }
    
    synchronized String consumir() { 
        while (this.espacio == "") {
            try {
                if(end){
                    return "Fin";
                }
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Almacen.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        String producto = this.espacio;
        this.espacio = "";
        notifyAll();
        return producto;
    }
    
    synchronized void producir(String producto) {
        while (this.espacio != "") {
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Almacen.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        this.espacio = producto;
        notifyAll();
    }
    public void end(){
        this.end = true;
    }
}
