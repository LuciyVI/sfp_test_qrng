#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netinet/udp.h>
#include <string.h>
#include <malloc.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
// #define DEBUG
struct get_network_settings
{
    int udp_socket;
    char ptr_buff[1024];
    int *ptr_on_sockaddr_in;
    int *len;
    int size_struct;
    int *device_name;

};

char create_buffer()
{
    char buff[32]=" ";
#ifdef DEBUG
    printf("buff now=%s \n",buff);
#endif
    return *buff;
}
void get_socket_and_bind(struct get_network_settings *get_set_net)

{
    struct sockaddr_in socket_service;
    struct sockaddr_in *ptr_socket_service = &socket_service;
    int udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (udp_socket == -1)
    {
        perror("error ");
    }
memset(&socket_service, 0, sizeof(socket_service)); 

socket_service.sin_family = AF_INET;
socket_service.sin_addr.s_addr = inet_addr("89.208.103.217");
socket_service.sin_port =  htons(7999);
int len=sizeof(socket_service);
get_set_net->udp_socket=udp_socket;
get_set_net->ptr_buff[1]=" Hello";
// printf("Buff in socket_and_bind : %s",&get_set_net->ptr_buff);
get_set_net->ptr_on_sockaddr_in=ptr_socket_service;
// printf("\nPTR on sockaddr socket in get_socket_and_bind: %ld \n ", &ptr_socket_service);
// printf("\nPTR on sockaddr socket in get_socket_and_bind: %ld \n ", get_set_net->ptr_on_sockaddr_in);
get_set_net->len=&len;
int return_code = bind(udp_socket,(struct sockaddr  *) &socket_service ,len);
if (return_code == -1)
    {
        perror("error return_code");
    }
// if (return_code = listen(get_set_net->udp_socket,4)<0)
//     {
//         perror("error return_code");
//     }

}
int _Messages(struct get_network_settings *get_set_net,int ptr_on_count)
{   
#ifdef DEBUG    
    printf("\nUDP socket in _Messages: %d \n", get_set_net->udp_socket);
    printf("\nBuff socket in main(): %s \n ", get_set_net->ptr_buff);
    printf("\nPTR on sockaddr socket in main(): %s \n ", get_set_net->ptr_on_sockaddr_in);
    printf("\nUDP socket in main(): %ld \n" , sizeof(get_set_net));
#endif
    get_set_net->ptr_buff[1]=" ";

    switch(recv(get_set_net->udp_socket,get_set_net->ptr_buff,sizeof(get_set_net->ptr_buff),MSG_WAITALL))
    {
    
            // case 32 :
                
                
                // break;
            // case 26 :
            //     break;
            // default:
            //     break; 
    }
return 0;
}

// int find_dev_name(struct get_network_settings *get_net_set)
// {
//     char *device; 
//     char error_buffer[64]; 

    
//     get_set_net->device_name = pcap_lookupdev(error_buffer);
//     // get_set_net->device_name = 
//     if (device == NULL) {
        
//         printf("\n \n Error finding device: %s\n", error_buffer);
        
//         return -1;
//     }else{

//         printf("\n \n Network device found: %s\n", device);
    
//     }
// return device;
// }
int main()
{

struct get_network_settings get_net_set;
get_net_set.size_struct=sizeof(get_net_set);
printf("\n size : %d\n",get_net_set.size_struct);
memset(&get_net_set, 0, sizeof(get_net_set));

get_socket_and_bind(&get_net_set);
        if ((get_net_set.udp_socket)>0)
    {
        printf("\n+=======================+\n+ bind socket sucsefull +\n+=======================+\n");
    
    }
        else {
        perror("bind error: \n");
    }
// find_dev_name(&get_net_set);

int _messages_count=0;
int *ptr_on_count = &_messages_count;

do
{
    //  printf("message = %d \n",_messages_count); 
    // printf("message = %s \n",&get_net_set.ptr_buff);
    _Messages(&get_net_set, &_messages_count);
    _messages_count++;
    printf("message count: %d \n", _messages_count);
    printf("\n message_in buff received \n %s", get_net_set.ptr_buff);
}while (1);

return 0;

}
