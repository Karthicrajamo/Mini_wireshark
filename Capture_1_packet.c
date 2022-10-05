//To capture a single packet 
//To refer use --> http://yuba.stanford.edu/~casado/pcap/section2.html
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<netinet/if_ether.h>

int main(){
    char *device_name;
    char error[PCAP_ERRBUF_SIZE];
    pcap_t* pack_desc; //pcap_t *pcap_open_live(char *device, int snaplen, int promisc, int to_ms,char *ebuf) --> Session Handle
    const u_char *packet;
    struct pcap_pkthdr header;

    //Asks pcap to give us a valid eth bashe device to stiff on it.
    device_name = pcap_lookupdev(error); // It is a outdated version use --> pcap_findalldevs
    if(device_name == NULL){
        printf("Error in the device name area : %s\n",error);
        return -1;
    } else {
        printf("Device : %s\n",device_name);
    }

    pack_desc = pcap_open_live(device_name, BUFSIZ, 0, 1, error);
    if(pack_desc == NULL){
        printf("Error on pack_disc : %s\n",error);
        return -1;
    } 

    packet = pcap_next(pack_desc, &header);
    if(packet == NULL){
        printf("Error: Cannot capture packet\n");
        return -1;
    } else {
        printf("Recived a packet with length %d\n", header.len);
        printf("Recived at %s\n", ctime((const time_t*) &header.ts.tv_sec));// --> This is to see the which time the packet is captured
    }

}