//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 17/04/2020
//
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
/*
Función que maneja los errores
Imprime y salle del programa
*/
void error(const char *msg)
{
    perror(msg);
    exit(1);
}
/*
Función Principal
*/
int main(int argc, char *argv[])
{
    //Declaración de variables
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    //Si los parámetros no son suficientes
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    //Genera un socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //Por deficinición, si no se logra encontrar el socket regresa -1
    if (sockfd < 0)
        error("ERROR opening socket");
    //Binding del address del servidor y el tamaño del número
    bzero((char *)&serv_addr, sizeof(serv_addr));
    //Transforma el argumento a número de puerto
    portno = atoi(argv[1]);
    //Configuración del servidor
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    //Handshake
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    //Abierto para escuchar las requests
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    //Handshake TCP
    newsockfd = accept(sockfd,
                       (struct sockaddr *)&cli_addr,
                       &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
    bzero(buffer, 256);
    //Reads the new message
    n = read(newsockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    //Prints the message
    printf("Here is the message: %s\n", buffer);
    //Returns the socket of the message
    n = write(newsockfd, "I got your message", 18);
    //En caso de que no exista un mensaje de buffer
    if (n < 0)
        error("ERROR writing to socket");
    //Cierra la conexión
    close(newsockfd);
    close(sockfd);
    return 0;
}
