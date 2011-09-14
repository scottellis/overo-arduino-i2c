/*
  Simple I2C communication test with an Arduino as the slave device.
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>

#define ARDUINO_I2C_ADDRESS 0x10

#define ARDUINO_I2C_BUFFER_LIMIT 32
 
int main(int argc, char **argv)
{
	int fh;
	char buff[40];
	int len, sent, rcvd;

	fh = open("/dev/i2c-3", O_RDWR);

	if (fh < 0) {
		perror("open");
		return 1;
	}

	if (ioctl(fh, I2C_SLAVE, ARDUINO_I2C_ADDRESS) < 0) {
		perror("ioctl");
		return 1;
	}

	if (argc > 1) {
		memset(buff, 0, sizeof(buff));
		strncpy(buff, argv[1], ARDUINO_I2C_BUFFER_LIMIT);
	}
	else {
		strcpy(buff, "hello");
	}

	len = strlen(buff);

	sent = write(fh, buff, len);

	if (sent != len) {
		perror("write");
		return 1;
	}

	printf("Sent: %s\n", buff);

	memset(buff, 0, sizeof(buff));
	rcvd = read(fh, buff, sent);

	while (rcvd < sent) {
		usleep(50000);	
		len = read(fh, buff + rcvd, sent - rcvd);

		if (len <= 0) {
			if (len < 0)
				perror("read");

			break;
		}

		rcvd += len;
	}

	if (rcvd > 0)
		printf("Received: %s\n", buff);

	close(fh);

	return 0;
}
