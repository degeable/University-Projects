#include <cstdlib>
#include "header.h"
#include <iostream>

using namespace std;

int main() {
    
    //optional: cin>>jeden eizelnen Punkt...
    Punkt2D p1;
    p1.x = 1;
    p1.y = 3;
    
    Punkt2D p2;
    p2.x = 5;
    p2.y = 3;
    
    Punkt2D p3;
    p3.x = 1;
    p3.y = 1;
    
    Punkt2D p4;
    p4.x = 5;
    p4.y = 1;  // vier punkte im Koordinatensystem
    
    Kreis k;
    k.radius = 2;
    k.mittelpunkt = p3;
    
    Dreieck d;
    d.E1 = p1;
    d.E2 = p2;
    d.E3 = p3;  // länge 1= p2x-p1x    länge 2= p3y-p1y  länge 3= wurzel länge 1² + länge 2² 
    
    Rechteck r;
    r.R1 = p1;
    r.R2 = p2;
    r.R3 = p3;
    r.R4 = p4;
    
    cout<<"Umfang Kreis: "<<Umfang(k)<<" LE"<<endl<<endl; //Umfang Kreis
    cout<<"Umfang Dreieck :"<<Umfang(d)<<" LE"<<endl<<endl;
    cout<<"Umfang Rechteck: "<<Umfang(r)<<" LE"<<endl<<endl;
    
    cout<<"Kreisflaeche: "<<Flaeche(k)<<" FE"<<endl<<endl;
    cout<<"Dreiecksflaeche: "<<Flaeche(d)<<" FE"<<endl<<endl;
    cout<<"Rechtecksflaeche: "<<Flaeche(r)<<" FE"<<endl<<endl;
    
    
}
