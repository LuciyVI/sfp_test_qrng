
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netinet/udp.h>
#include <string.h>
#include <malloc.h>
#include <pcap/pcap.h>
#include <asm/types.h>
#include <linux/netlink.h>

void get_socket_and_bind()

{
    char message[32];
    struct sockaddr_in dst_service , src_service;
    struct sockaddr_in *ptr_socket_service = &dst_service;
    int udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (udp_socket == -1)
    {
        perror("error ");
    }
memset(&dst_service, 0, sizeof(dst_service)); 

        dst_service.sin_family = AF_INET;
        dst_service.sin_addr.s_addr = inet_addr("192.0.2.5");
        dst_service.sin_port =  htons(7999);
int len=sizeof(dst_service);

memset(&src_service,0,sizeof(src_service));
        src_service.sin_family = AF_INET;
        src_service.sin_addr.s_addr = inet_addr("192.0.2.2");
        src_service.sin_port = htons(8888);
if (bind(udp_socket, (struct sockaddr *) &src_service, sizeof(src_service)) < 0)
    {
        perror("ERROR: ");
    } else { printf("\n ============================================ \n +               Bind Sucsessfull           +\n ============================================ \n"); }
int count=0; 

int number_templete_packet;

    printf("\n Введите текст сообщения \n");
    fgets(message, 32, stdin);
    printf("Текст в буфере %s",message);
    printf("\n Какой флаг использовать при отправке дейтаграмм \n [1]: MSG_DONTWAIT \n [2]: MSG_DONTROUTE \n [3]: MSG_NOSIGNAL \n [4]: MSG_OOB \n [5]: MSG_CONFIRM \n");
    scanf("%d",&number_templete_packet);
switch(number_templete_packet)
{
    case 1: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_DONTWAIT,(struct sockaddr  *) &dst_service,len);
            printf("\n Num. count: %d \n",count);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        if (recv(udp_socket,message,sizeof(message),MSG_WAITALL)<0)
            {
                perror("ERROR: ");
            } else { printf("Buff it's now: %s ", message);}
        break;
    case 2: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_DONTROUTE,(struct sockaddr  *) &dst_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        if (recv(udp_socket,message,sizeof(message),MSG_WAITALL)<0)
            {
                perror("ERROR: ");
            } else { printf("Buff it's now: %s ", message);}
        break;
    case 3:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_NOSIGNAL,(struct sockaddr  *) &dst_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        if (recv(udp_socket,message,sizeof(message),MSG_WAITALL)<0)
            {
                perror("ERROR: ");
            } else { printf("Buff it's now: %s ", message);}
        break;    
    case 4:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_OOB,(struct sockaddr  *) &dst_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }
        if (recv(udp_socket,message,sizeof(message),MSG_WAITALL)<0)
            {
                perror("ERROR: ");
            } else { printf("Buff it's now: %s ", message);}
        break;    
    case 5:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(udp_socket,message,sizeof(message),MSG_CONFIRM,(struct sockaddr  *) &dst_service,len);
            printf("sendto Message now: %s",message);
            printf("\n Num. message : %d \n",i);
            }   
        if (recv(udp_socket,message,sizeof(message),MSG_WAITALL)<0)
            {
                perror("ERROR: ");
            } else { printf("Buff it's now: %s ", message);}
        break;      

}
}

void main ()
{
	 get_socket_and_bind();
}
