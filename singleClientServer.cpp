#include "sockets.hpp"

int	main()
{
	// int	server_fd, new_socket, valread;
	// struct sockaddr_in address;
	// int	opt = 1;
	// int addrlen = sizeof(address);
	sockets	sock(4242);
	char	buffer[1024] = {0};
	char *hello = strdup("Hi from server side");

	//Create socket fd
	// if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	// {
	// 	perror("socket creation failed");
	// 	exit(EXIT_FAILURE);
	// }

	// //Attach socket to port 8080
	// if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	// {
	// 	perror("setsockopt err");
	// 	exit(EXIT_FAILURE);
	// }
	// address.sin_family = AF_INET;
	// address.sin_addr.s_addr = INADDR_ANY;
	// address.sin_port = htons(8080);
	// if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	// {
	// 	perror("bind failed");
	// 	exit(EXIT_FAILURE);
	// }
	// if(listen(server_fd, 3) < 0)
	// {
	// 	perror("listening failed");
	// 	exit(EXIT_FAILURE);
	// }
	// if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
	// {
	// 	perror("accepting new socket failed");
	// 	exit(EXIT_FAILURE);
	// }
	sock.bindSock();
	sock.listener(10);
	sock.acceptClient();
	/* valread =  */read(sock.getClientsVec()[0], buffer, 1024);
	printf("%s\n", buffer);
	send(sock.getClientsVec()[0], hello, strlen(hello), 0);
	printf("Hello msg sent\n");
	return 0;
}