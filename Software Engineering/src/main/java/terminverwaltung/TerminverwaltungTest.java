/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package terminverwaltung;

import java.util.ArrayList;

/**
 *
 * @author fb Letzte Änderung: 14.09.2017 Beschreibung Alternatives
 * Hauptprogramm, um Klassen zu testen.
 *
 */
public class TerminverwaltungTest {

    // Testmethode
    static void testeXMLReaderRaumliste() {
        
        //  XML-Reader-Test mit Ausgabe
        ArrayList<Raum> test=new ArrayList<>();
        ReadXMLRaumliste XMLrl = new ReadXMLRaumliste("/home/stud/3DMi4_3/src/main/java/terminverwaltung/Dateien/raumliste.xml");
        XMLrl.leseRaeume(test);
      
    }

    static void testeRaumhinzufuegen(){
   
        //Test ohne Dialog
    Raumverwaltung test=new Raumverwaltung();
    test.createRaum("tName", "tLoc", "tPlaetze");
        for (Raum raum : test.Raumliste) {
            System.out.println(raum.getName());
             System.out.println(raum.getLocation());
              System.out.println(raum.getPlaetze());
        }
    }
    /**     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Start des Testprogramms
        System.out.println("main: Test für Terminverwaltung");

        // Beispiel für Testmethodenaufruf
        testeXMLReaderRaumliste();
    }

}
