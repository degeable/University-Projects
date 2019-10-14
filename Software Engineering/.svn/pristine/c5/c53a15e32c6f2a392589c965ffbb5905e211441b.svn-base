/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package terminverwaltung;

import java.util.concurrent.atomic.AtomicInteger;

/**
 *
 * @author Khanh
 */
public class Nutzer {
    
    private static final AtomicInteger count = new AtomicInteger(0); // used to create an unique user id
    
    private String vorname;
    private String nachname;
    private String userName;
    private String password;
    private int userId;

    public Nutzer(String inputVorname, String inputNachname,String inputUserName, String inputPassword) {
        
        vorname = inputVorname;
        nachname = inputNachname;
        userName = inputUserName;
        password = inputPassword;
        userId = count.incrementAndGet();
    }
    
    
    
    /**
     * @return the vorname
     */
    public String getVorname() {
        return vorname;
    }

    /**
     * @param vorname the vorname to set
     */
    public void setVorname(String vorname) {
        this.vorname = vorname;
    }

    /**
     * @return the nachname
     */
    public String getNachname() {
        return nachname;
    }

    /**
     * @param nachname the nachname to set
     */
    public void setNachname(String nachname) {
        this.nachname = nachname;
    }

    /**
     * @return the userId
     */
    public int getUserId() {
        return userId;
    }

    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @param password the password to set
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * @return the userName
     */
    public String getUserName() {
        return userName;
    }
    
    
    
    
    
    
    
            
    
}
