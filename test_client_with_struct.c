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
struct network_configuration {

    int udp_socket;
    char ptr_buff[1024];
    struct sockaddr_in *ptr_dst_service;
    struct sockaddr_in *ptr_src_service;
    int dst_len;
    int src_len;
    int size_struct;
    int *device_name;
    char ptr_buff_recv[1024];
};

void get_socket(struct network_configuration *get_s_net)

{
    struct sockaddr_in dst_service, src_service;
    // struct sockaddr_in *ptr_dst_service = &dst_service;
    // struct sockaddr_in *ptr_src_service = &src_service;
    int udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

if (udp_socket == -1)
    {
        perror("error ");
    }
memset(&dst_service, 0, sizeof(dst_service)); 

    dst_service.sin_family = AF_INET;
    dst_service.sin_addr.s_addr = inet_addr("192.0.2.5");
    dst_service.sin_port =  htons(7999);

int dst_len=sizeof(dst_service);

memset(&src_service,0,sizeof(src_service));

        src_service.sin_family = AF_INET;
        src_service.sin_addr.s_addr = inet_addr("192.0.2.2");
        src_service.sin_port = htons(8888);

int src_len=sizeof(src_service);

if (bind(udp_socket, (struct sockaddr *) &src_service, sizeof(src_service)) < 0)

    {

        perror("ERROR: ");

    } 

else 

{ 

    printf("\n ============================================ \n +               Bind Sucsessfull           +\n ============================================ \n"); 

}

get_s_net->udp_socket=udp_socket;
// printf("Buff in socket_and_bind : %s",&get_set_net->ptr_buff);
get_s_net->ptr_dst_service=&dst_service;
get_s_net->ptr_src_service=&src_service;
// printf("\nPTR on sockaddr socket in get_socket_and_bind: %ld \n ", &ptr_socket_service);
get_s_net->dst_len=dst_len;
// printf("\nLenght socket-service in get_socket: %d \n ", get_set_net->len);
}
int send_message(struct network_configuration *get_net)
{

    
    printf("\n Введите текст сообщения \n");
    
    fgets(get_net->ptr_buff, 1024, stdin);
    
    printf("Текст в буфере %s", get_net->ptr_buff);
    
    int number_templete_packet,count=0;


// printf("\nLenght socket-service in sin.family: %d \n ", get_net->ptr_socket_service);
printf("\n Какой флаг использовать при отправке дейтаграмм \n [1]: MSG_DONTWAIT \n [2]: MSG_DONTROUTE \n [3]: MSG_NOSIGNAL \n [4]: MSG_OOB \n [5]: MSG_CONFIRM \n");
scanf("%d" , &number_templete_packet);
// int return_code = connect(udp_socket,(struct sockaddr  *) &socket_service,len);
//         if(return_code<0)
//         {
//             printf("Connect it's: %d", return_code);
//         }else{ 
//             perror("connect error");
//         }
//         recv(udp_socket,message,sizeof(message),0);
//         printf("message now: %s", message);
switch(number_templete_packet)
{
    case 1: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
        
        {
                sendto(get_net->udp_socket,get_net->ptr_buff,sizeof(get_net->ptr_buff),MSG_DONTWAIT,get_net->ptr_dst_service,get_net->dst_len);
        
                printf("\n Num. count: %d \n",count);
                printf("\n sendto Message now: %s \n",get_net->ptr_buff);
                printf("\n Num. message : %d \n",i);
                
                printf("Buff it's empty: %s ", get_net->ptr_buff_recv);

            if (recv(get_net->udp_socket,get_net->ptr_buff_recv,sizeof(get_net->ptr_buff_recv),MSG_WAITALL)<0)
        
                {
        
                    perror("ERROR: ");
        
                } 
        
            else 
        
                { 

                    printf("Buff it's now: %s ", get_net->ptr_buff_recv);
                    
                }
        }
        break;
    case 2: 
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
        {
            
            sendto(get_net->udp_socket,get_net->ptr_buff,sizeof(get_net->ptr_buff),MSG_DONTROUTE,get_net->ptr_dst_service,get_net->dst_len);
            printf("sendto Message now: %s",get_net->ptr_buff);
            printf("\n Num. message : %d \n",i);
            

            if (recv(get_net->udp_socket,get_net->ptr_buff_recv,sizeof(get_net->ptr_buff_recv),MSG_WAITALL)<0)
        
                {
        
                    perror("ERROR: ");
        
                } 
        
            else 
        
                { 

                    printf("Buff it's now: %s ", get_net->ptr_buff_recv);
                    
                }

        }
        break;
    case 3:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            
            sendto(get_net->udp_socket,get_net->ptr_buff,sizeof(get_net->ptr_buff),MSG_NOSIGNAL,get_net->ptr_dst_service,get_net->dst_len);
            printf("sendto Message now: %s",get_net->ptr_buff);
            printf("\n Num. message : %d \n",i);
            
            
            if (recv(get_net->udp_socket,get_net->ptr_buff_recv,sizeof(get_net->ptr_buff_recv),MSG_WAITALL)<0)
        
                {
        
                    perror("ERROR: ");
        
                } 
        
            else 
        
                { 

                    printf("Buff it's now: %s ", get_net->ptr_buff);
                    
                }

            }
            
        break;    
    case 4:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            
            sendto(get_net->udp_socket,get_net->ptr_buff,sizeof(get_net->ptr_buff),MSG_OOB,get_net->ptr_dst_service,get_net->dst_len);
            printf("sendto Message now: %s",get_net->ptr_buff); 
            printf("\n Num. message : %d \n",i);
            
            
            if (recv(get_net->udp_socket,get_net->ptr_buff_recv,sizeof(get_net->ptr_buff_recv),MSG_WAITALL)<0)
        
                {
        
                    perror("ERROR: ");
        
                } 
        
            else 
        
                { 

                    printf("Buff it's now: %s ", get_net->ptr_buff_recv);
                    
                }

            }
            

        break;    
    case 5:
        printf("\n Введите кол-во отправленных дейтаграмм \n ============================================ \n");
        scanf("%d",&count);
        for (int i=0; i<count;i++)
            {
            sendto(get_net->udp_socket,get_net->ptr_buff_recv,sizeof(get_net->ptr_buff_recv),MSG_CONFIRM,get_net->ptr_dst_service,get_net->dst_len);
            printf("sendto Message now: %s",get_net->ptr_buff);
            printf("\n Num. message : %d \n",i);
            
            
            if (recv(get_net->udp_socket,get_net->ptr_buff,sizeof(get_net->ptr_buff),MSG_WAITALL)<0)
        
                {
        
                    perror("ERROR: ");
        
                } 
        
            else 
        
                { 

                    printf("Buff it's now: %s ", get_net->ptr_buff_recv);
                    
                }

            

            }
        break;   
}   
}

int get_ip()
{

}
void main()
{   
    struct network_configuration get_set_net;
    
    get_set_net.size_struct=sizeof(get_set_net);
    
        printf("\n size : %d\n",get_set_net.size_struct);
    
    memset(&get_set_net, 0, sizeof(get_set_net));
    
    get_socket(&get_set_net);
    
    send_message(&get_set_net);
    
}
