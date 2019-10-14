
package terminverwaltung;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;



/**
 *
 * @author Khanh
 */
public class Nutzerverwaltung {
    
    private final ArrayList<Nutzer> userList = new ArrayList<>();

    public Nutzerverwaltung() {
        addAdmin();
    }
    
    public void addUser(String inputVorname, String inputNachname,String inputUsername, String inputPassword) {
    
        getUserList().add(new Nutzer(inputVorname, inputNachname,inputUsername, inputPassword));
    }

    /**
     * @return a copy of userList to ensure integrity 
     */
    public ArrayList<Nutzer> getUserList() {
        ArrayList<Nutzer> userListCopy = userList;
        return userListCopy;
    }
    
    /**
     * params still missing
     */
    private void addAdmin() {
    
    }
    
    
    
    
    
}
