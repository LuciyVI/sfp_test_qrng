#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netinet/udp.h>
#include <string.h>
#include <malloc.h>
#include <pcap/pcap.h>

void get_socket_and_bind()

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
int count=0; // кол-во итераций цикла отпрвки дейта грамм 
// get_set_net->udp_socket=udp_socket;
// get_set_net->ptr_on_sockaddr_in= ptr_socket_service;
// get_set_net->len=&len;
char message[32]="Hello world";
int number_templete_packet;

printf("\n Какой флаг использовать при отправке дейтаграмм \n [1]: MSG_DONTWAIT \n [2]: MSG_DONTROUTE \n [3]: MSG_NOSIGNAL \n [4]: MSG_OOB \n [5]: MSG_CONFIRM \n");
scanf("%d",&number_templete_packet);
switch(number_templete_packet)
{
    case 1: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_DONTWAIT,(struct sockaddr  *) &socket_service,len);
            printf("\n Num. count: %d \n",count);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        break;
    case 2: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_DONTROUTE,(struct sockaddr  *) &socket_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        break;
    case 3:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_NOSIGNAL,(struct sockaddr  *) &socket_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        break;    
    case 4:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_OOB,(struct sockaddr  *) &socket_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        break;    
    case 5:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_CONFIRM,(struct sockaddr  *) &socket_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        break;   
    // case 6:
    //     sendto(udp_socket,message,sizeof(message),MSG_TRUNC,(struct sockaddr  *) &socket_service,len);
    // case 7:
    //     sendto(udp_socket,message,sizeof(message),MSG_PEEK,(struct sockaddr  *) &socket_service,len);
}
// sendto(udp_socket,message,sizeof(message),MSG_EOR,(struct sockaddr  *) &socket_service,len);
}
int get_ip()
{

}
void main()
{
    get_socket_and_bind();
}