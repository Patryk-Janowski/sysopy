#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	char buff[1024];
    int retv;
    int x = 1;
	
	if(argc < 3){
		printf("Incorrect num of arguments");
		exit(0);
	}

	//Setup Buffer Array
	memset(buff, 0, sizeof(buff));

	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0){
		perror("Client Error: Socket not created succesfully");
		exit(0);
	}
	
	//Structure to store details
	struct sockaddr_in server; 
	memset(&server, 0, sizeof(server)); 

	//Initialize	
	server.sin_family = AF_INET;
	server.sin_port =  htons(atoi(argv[2]));
    retv = inet_pton(AF_INET, argv[1], &server.sin_addr);

	if(retv < 0){
		perror("Client Error: IP not initialized succesfully");
		exit(0);
	}

	//Connect to given server	
	retv = connect(fd, (struct sockaddr *)&server, sizeof(server));
	while (retv < 0) {
        retv = connect(fd, (struct sockaddr *)&server, sizeof(server));
    } 

    retv = 2;

	while(retv > 1){

		printf("Please enter the message: ");
        bzero(buff, 256);
        fgets(buff, 256, stdin);
    
		/* Send message to the server */
        retv = send(fd, buff, strlen(buff), 0);
        if (retv < 0){
            perror("\nClient Error: Writing to Server");
            exit(0);
        }
		/* Now read server response */
        bzero(buff, 256);
        retv = recv(fd, buff, 256, 0);
        if (retv < 0){
            perror("\nClient Error: Reading from Server");
            exit(0);
        }
        printf("Received Message: %s",buff);
	}
	close(fd);
	exit(0);
}