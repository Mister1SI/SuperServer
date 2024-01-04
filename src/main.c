#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
	const char* msg = "Welcome to the amazing program!\x0a";
	write(1, msg, 32);
	

	int fd = open("a.txt", O_RDONLY);
	char buf[1024] = {0};
	read(fd, buf, 1024);
	if(fd == -1) {
		const char* fail_msg = "Failed to open tile\x0a";
		write(1, fail_msg, 20);
		return 1;
	}
	write(1, buf, 1024);
	
	struct timespec ts = {3, 0};
	nanosleep(&ts, 0);
	const char* msg2 = "Amog\n";
	write(1, msg2, 5);

	close(fd);
	
	fd = open("a.txt", O_APPEND);
	if(fd == -1) {
		char* fail_msg = "Failed to open file\n";
		write(1, fail_msg, 20);
		return 1;
	}
	const char* msg3 = "Enter some text to append to the file: ";
	write(1, msg3, 39);
	char buf2[1024] = {0};
	read(0, buf2, 1024);
	write(fd, buf2, 1024);

	close(fd);
	return 0;
}
