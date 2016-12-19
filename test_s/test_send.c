#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int SendTo (void * data, int len) {
	int sock;
	struct sockaddr_in addr;
	
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(50000);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		return -1;
	}

	sendto(sock, data, len, 0, (struct sockaddr *)&addr, sizeof(addr));
	sleep(1);

	close(sock);

	return 0;
}

int main(int argc, char ** argv) {
	if (argc > 0)
		SendTo(argv[1], sizeof(argv[1]));
	return 0;	
}
