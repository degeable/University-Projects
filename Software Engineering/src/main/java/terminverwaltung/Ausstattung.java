/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package terminverwaltung;
import java.lang.String;
/**
 *
 * @author istkastra
 */
public class Ausstattung {
     

}
    
     class Beamer extends Ausstattung{

    public Beamer(int ID, String TYP) {
        this.id = ID;
        this.typ = TYP;
    }
         
        int id;
        String typ;
        
        
    }
     class Computer extends Ausstattung{
        String id;
        String Betriebssysteme;

    public Computer(String id, String Betriebssysteme) {
        this.id = id;
        this.Betriebssysteme = Betriebssysteme;
    }
        
        
        
    }
     class Flipchart extends Ausstattung{
        String id;

    public Flipchart(String id) {
        this.id = id;
    }
      
    }


