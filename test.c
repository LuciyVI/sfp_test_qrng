#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netinet/udp.h>
#include <string.h>
#include <malloc.h>


char create_buffer()
{
    char buff[]=" ";
    printf("buff now=%s \n",buff);
    return *buff;
}
int get_soket_and_bind()
{
        struct sockaddr_in socket_service;
    int udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (udp_socket == -1)
    {
        perror("error ");
    }


memset(&socket_service, 0, sizeof(socket_service)); 
// memset(&cliaddr, 0, sizeof(cliaddr)); 
        socket_service.sin_family = AF_INET;
        socket_service.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        socket_service.sin_port =  htons(7999);
int socket_len = 16;
int return_code = bind(udp_socket,(struct sockaddr  *) &socket_service ,sizeof(socket_service));
if (return_code == -1)
    {
        perror("error return_code");
    }
char ptr_on_buff=create_buffer(); 

fgets(&ptr_on_buff,254,stdin);

printf("them ptr_on_buff = %s", &ptr_on_buff);
return 0;
}
int get_hook()
{

}

int main()
{
        if (get_soket_and_bind()==0)
    {
        printf("bind socket sucsefull \n");
    
    }
        else {
        perror("bind error: \n");
    }
// get_message();
// while (1)
// {

// }
return 0;

}
