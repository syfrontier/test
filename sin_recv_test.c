#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void sig_handler(int signum, siginfo_t *siginfo, void * act){

	printf("Caught the signal: %d\n", signum);
	
	printf("Sending PID: %ld, UID: %ld\n",
		(long)siginfo->si_pid, (long)siginfo->si_uid);

}

int main(int argc, char ** argv)
{
	struct sigaction act;
	memset(&act, 0 , sizeof(act));
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(6, &act, NULL) < 0) {
		perror("sigaction");
		return 1;
	}

	if (sigaction(7, &act, NULL) < 0) {
                perror("sigaction");
                return 1;
        }

	while(1) {
		printf("The signal acception program is running.\n");
		sleep(10);
	}
	
	return 0;
}
