//This program is to see the Interfaces,IP Address and Netmask.
//To refer use --> http://yuba.stanford.edu/~casado/pcap/section2.html
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    //   net_addr --> IP Address; net_mask --> Subnet Mask.
    char *device_name, *net_addr, *net_mask;
    int rcode;
    char error[PCAP_ERRBUF_SIZE];

    bpf_u_int32 net_addr_int, net_mask_int; //IP Address as unsigned 32bit integer >> u -> Denotes for unsigned.
    //in_addr --> It have an already defined struct on pcap libary.
    struct in_addr addr; 

    //Asks pcap to give us a valid eth based device to sniff on it.
    device_name = pcap_lookupdev(error);
    if(device_name == NULL){
        printf("%s\n",error);
        return -1;
    }else{
        printf("Devices: %s\n", device_name);
    }
    

}