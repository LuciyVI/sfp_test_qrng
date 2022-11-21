#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netinet/udp.h>
#include <string.h>
#include <malloc.h>

struct get_network_settings
{
    int udp_socket;
    char *ptr_buff;
    struct sockaddr_in *ptr_on_sockaddr_in;
    int *len;
    

};

char create_buffer()
{
    char buff[256]=" ";
    printf("buff now=%s \n",buff);
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
socket_service.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
socket_service.sin_port =  htons(7999);
int len=sizeof(socket_service);
get_set_net->udp_socket=udp_socket;
get_set_net->ptr_on_sockaddr_in= ptr_socket_service;
get_set_net->len=&len;
printf("ptr_socket_service=%ld",*ptr_socket_service);
int return_code = bind(udp_socket,(struct sockaddr  *) &socket_service ,len);
if (return_code == -1)
    {
        perror("error return_code");
    }

}
int _Messages(struct get_network_settings *get_set_net)
{   
    printf("UDP socket in main(): %d", get_set_net->udp_socket);
    printf("UDP socket in main(): %s", get_set_net->ptr_buff);
    printf("UDP socket in main(): %ld" , sizeof(&get_set_net));
    recvfrom(get_set_net->udp_socket,get_set_net->ptr_buff,sizeof(get_set_net->ptr_buff),MSG_WAITALL,get_set_net->ptr_on_sockaddr_in,get_set_net->len);
    
}

int main()
{
struct get_network_settings get_net_set;
memset(&get_net_set, 0, sizeof(get_net_set));
get_socket_and_bind(&get_net_set);
        if ((get_net_set.udp_socket)>0)
    {
        printf("\n bind socket sucsefull \n");
    
    }
        else {
        perror("bind error: \n");
    }
do
{
    perror("\n error in _Message: \n ");
}while (_Messages(&get_net_set)>0);
return 0;

}
