//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 17/04/2020
//
/*
A simple client in the local environment using TCP
 The hostname is the ip_addr
 And the port is where the handshake will be made
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
/*
Función que maneja los errores
Imprime y salle del programa
*/
void error(const char *msg)
{
    perror(msg);
    exit(0);
}
/*
Función Principal
*/
int main(int argc, char *argv[])
{
    //Declaración de variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    //Si los parámetros no son suficientes
    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    //Transforma el argumento a número de puerto
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //Por deficinición, si no se logra encontrar el socket regresa -1
    if (sockfd < 0)
        error("ERROR opening socket");
    //Verifica el ip address está accesible para la conexión
    server = gethostbyname(argv[1]);
    //Si el servidor no está corriendo marca el error
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    //Transforma el argumento a número de puerto
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    //Handshake TCP
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    //Sends the message
    n = write(sockfd, buffer, strlen(buffer));
    //In case of error
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer, 256);
    //Returns the socket of the message
    n = read(sockfd, buffer, 255);
    //En caso de que no exista un mensaje de buffer
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);
    //Cierra la conexión
    close(sockfd);
    return 0;
}
