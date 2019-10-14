/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package terminverwaltung;

import java.lang.String;

/**
 *
 * @author stud
 */
public class Raum {
  
    private String location;
    private String plaetze;
    private String name;

    
    public Raum(String Loc, String Plaetze, String Name){
        location=Loc;
        plaetze=Plaetze;
        name=Name;
    }
    /**
     * @return the location
     */
    public String getLocation() {
        return location;
    }

    /**
     * @param location the location to set
     */
    public void setLocation(String location) {
        this.location = location;
    }

    /**
     * @return the plaetze
     */
    public String getPlaetze() {
        return plaetze;
    }

    /**
     * @param plaetze the plaetze to set
     */
    public void setPlaetze(String plaetze) {
        this.plaetze = plaetze;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }
}
