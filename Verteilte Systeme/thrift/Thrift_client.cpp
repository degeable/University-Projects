#include "getDataService.h"  // As an example
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/stdcxx.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "string.h"
#include "unistd.h"
#include <cstdlib>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace  ::Test;
int main(int argc, char **argv) {
     boost::shared_ptr<TSocket> socket(new TSocket("192.168.0.109", 9090));
     boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
     boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
     
     getDataServiceClient client(protocol);
     transport->open();
    std::vector<std::string>result;
    std::string auswahl;
    while(1){
    std::cout<<"Bitte wählen sie einen Sensor aus:\n\n";
    std::cout<<"0: Tank\n";
    std::cout<<"1: Kilometerstand\n";
    std::cout<<"2: Durchschnittsgeschwindigkeit\n";
    std::cout<<"3: Verkehrslage\n";
    std::cout<<"9: Programm verlassen\n\n";
    std::cin>>auswahl;
if(auswahl=="9")
    return 0;
    
     std::cout<<"Daten werden abgerufen und gespeichert...\n";
     client.getData(result,("MQTT_data"+auswahl+".txt").c_str());
        
     std::ofstream outputfile;
     outputfile.open(("sensor"+auswahl+".txt").c_str());
    auswahl="";
    
     for (int i=0; i<result.size();i++){
            outputfile<<result.at(i);
     } 
     std::string uhrzeit;
     std::string delim="#";
     std::cout<<"Geben sie eine Uhrzeit ein: (HH:MM)\n";
     std::cin>>uhrzeit;
 std::cout<<"....................\n\n";
     for(int i=0; i< result.size();i++){
     std::size_t found = result.at(i).find(uhrzeit,1);
    
     if(found!=std::string::npos){
        std::cout<<result.at(i).substr(1,8)<<" -> "<<result.at(i).substr(9,result.at(i).find(delim)-9)<<std::endl; 
    }
}
     std::cout<<"....................\n\n";

     result.clear();
     outputfile.close();
    }
     transport->close();
   
 return 0;
}


