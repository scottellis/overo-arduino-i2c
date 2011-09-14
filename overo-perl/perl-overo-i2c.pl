#!/usr/bin/perl -w

my $IOCTL_I2C_SLAVE = 0x0703;

my $ARDUINO_I2C_ADDR = 0x10;

my $ARDUINO_I2C_BUFFER_LIMIT = 32;


open(I2C_3, "+>/dev/i2c-3") || die "open: $!\n";

ioctl(I2C_3, $IOCTL_I2C_SLAVE, $ARDUINO_I2C_ADDR) || die "ioctl: $!\n"; 

my $buff = ($#ARGV == -1) ? "hello" : $ARGV[0];

if (length($buff) > $ARDUINO_I2C_BUFFER_LIMIT) {  
	$buff = substr($buff, 0, $ARDUINO_I2C_BUFFER_LIMIT);
}

my $len = length($buff);

syswrite(I2C_3, $buff, $len) || die "syswrite: $!\n";

print "Sent: ", $buff, "\n";

sysread(I2C_3, $buff, $len) || die "sysread: $!\n";

print "Received: ", $buff, "\n" if ($len > 0);

close(I2C_3);

