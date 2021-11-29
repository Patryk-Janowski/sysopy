#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
	int fd = 0;
	char buff[1024];
	int retv;
	

	if(argc < 2){
		printf("Less no of arguments !!");
		exit(0);
	}

	//Setup Buffer Array
	memset(buff, 0, sizeof(buff));
 
	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0){
		perror("Client Error: Socket not created succesfully");
		return 0;
	}

	//Structure to store details
	struct sockaddr_in server; 
	memset(&server, 0, sizeof(server)); 

	//Initialize	
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1])); 
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(fd, (struct sockaddr*)&server, sizeof(server)); 

	int cfd;
	
	listen(fd, 1); 
	cfd = accept(fd, (struct sockaddr*)NULL, NULL);

	while ((retv = recv(cfd, buff, 256, 0)) > 1){
	
		printf("Recived Message: %s",buff);
		
		printf("Please enter the message: ");
		bzero(buff, 256);
		fgets(buff, 256, stdin);
      	retv = send(cfd, buff, strlen(buff), 0);
        if (retv < 0){
            perror("\nClient Error: Writing to Server");
            exit(0);
        }
		bzero(buff,256);				
	}
	close(cfd);
	exit(0);
}