package terminverwaltung;

import java.io.File;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

public class ReadXMLAusstattung {

    int error;
    String XMLdateiName;

    public ReadXMLAusstattung (String dateiname) {
        error = 0;
        XMLdateiName = dateiname;
        
        // Testausgabe für Dateipfad zu XML-Datei
        System.out.println(XMLdateiName);
    }

    public void leseRaeume() {

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
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
