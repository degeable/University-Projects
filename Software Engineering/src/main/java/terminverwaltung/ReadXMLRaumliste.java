/* 
 * Projekt: Terminverwaltung
 * Datei  : ReadXMLRaumliste
 * Gruppe : Frank Buehler
 * Letzte Änderung: 14.09.2017
 *
 * Änderungen
 *
 */
package terminverwaltung;

import java.io.File;
import java.util.ArrayList;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

public class ReadXMLRaumliste {

    int error;
    String XMLdateiName;

    public ReadXMLRaumliste(String dateiname) {
        error = 0;
        XMLdateiName = dateiname;
        
        // Testausgabe für Dateipfad zu XML-Datei
        System.out.println(XMLdateiName);
    }

    public void leseRaeume(ArrayList<Raum> list) {

        try {
            // XML-Datei einlesen
            File fXmlFile = new File(XMLdateiName);
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(fXmlFile);
            doc.getDocumentElement().normalize();

            // XML-Elemente auslesen und ausgeben
            System.out.println("\nWurzelelement: " + doc.getDocumentElement().getNodeName());

            NodeList nList = doc.getElementsByTagName("raum");

            System.out.println("----------------------------");

            for (int temp = 0; temp < nList.getLength(); temp++) {

                Node nNode = nList.item(temp);

                System.out.println("\nElement :" + nNode.getNodeName());

                if (nNode.getNodeType() == Node.ELEMENT_NODE) {

                    Element eElement = (Element) nNode;
                    String raumID = eElement.getTextContent();
                    String loc = eElement.getAttribute("location");
                    String pl = eElement.getAttribute("plaetze");

                    System.out.println("Raum-ID : " + raumID);
                    System.out.println("Lokation : " + loc);
                    System.out.println("Plätze : " + pl);
                    list.add(new Raum(loc,pl,raumID));
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
