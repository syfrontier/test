#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main (int argc, char ** argv) {

	struct sockaddr_in addr;
	char recv_buf[64];
	int sock, addr_len, read_bytes;

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(50000);
	addr_len = sizeof(addr);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
	}

	bind(sock, (struct sockaddr *)&addr, addr_len);

	while (1) {
		
		read_bytes = recvfrom(sock, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr, &addr_len);
		if (read_bytes > 0) {
			printf("\r\nReceive Data: %s", recv_buf);
		}
	}

	close(sock);

	return 0;
}
