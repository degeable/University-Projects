/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package terminverwaltung;


import java.util.ArrayList;
/**
 *
 * @author stud
 */
public class Raumverwaltung {

    public Raumverwaltung() {
        ReadXMLRaumliste r=new ReadXMLRaumliste("/home/stud/3DMi4_3/src/main/java/terminverwaltung/Dateien/raumliste.xml");
        r.leseRaeume(Raumliste);
    }

  public void createRaum(String name, String location, String plaetze){
    Raum newraum = new Raum(location,plaetze,name);
        Raumliste.add(newraum);
}
    
    public ArrayList<Raum>Raumliste=new ArrayList<>();

    /**
     * @return the Raumliste
     */
    public ArrayList<Raum> getRaumliste() {
        return Raumliste;
    }

    /**
     * @param Raumliste the Raumliste to set
     */
    public void setRaumliste(ArrayList<Raum> Raumliste) {
        this.Raumliste = Raumliste;
    }

}