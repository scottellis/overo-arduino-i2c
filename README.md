  overo-arduino-i2c
=======

Some example programs for Gumstix Overo to Arduino I2C communication.

There is some more documentation here [Gumstix to Arduino using I2C](http://www.jumpnowtek.com/index.php?option=com_content&view=article&id=68:gumstix-arduino-i2c&catid=39:arduino&Itemid=76)

The Arduino is a more flexible I2C device because it can be either a master or slave
device on the I2C bus. Because of the Linux driver, the Overo can only be an I2C
master.

There is an Arduino sketch under the arduino directory that implements the Arduino
side of the test programs in this project. You should load that first. It establishes
the Arduino as a slave device at address 0x10.

On the Gumstix side you have a choice of C, Perl or Python.

For the C program, you can build it either on your host workstation using the OE cross-compiler
tools using the Makefile provided then copy the resulting *overo-i2c* executable to the Gumstix. 
If you have C development tools on the Gumstix, then you can use the Makefile-native make file
and compile it there.

For Perl or Python, just copy the *perl-overo-i2c.pl* or *python-overo-i2c.py* script to the
Gumstix and run it. Of course you need Perl or Python on the Gumstix first.

There is an OE image recipe called *dev-image.bb* in the recipe directory of this project that
will build a minimal Overo image with all the dev tools you need to run the examples. Copy it
to your workstation and build it with bitbake or just use it to figure out what to add to your
image.

Usage
-------

Assuming you copied the following files to your Gumstix

    root@overo:~# ls
    Makefile  Makefile-native  overo-i2c.c	perl-overo-i2c.pl  python-overo-i2c.py


To build the C program

    root@overo:~# make -f Makefile-native
    gcc -Wall overo-i2c.c -o overo-i2c 

And to test it

    root@overo:~# ./overo-i2c test-me
    Sent: test-me
    Received: TEST-ME


For the Perl program

    root@overo:~# ./perl-overo-i2c.pl perl-test
    Sent: perl-test
    Received: PERL-TEST


And the Python program

    root@overo:~# ./python-overo-i2c.py 
    Sent: hello
    Received: HELLO


To build the C program on your workstation using the OE cross-compiler

    ~$ cd overo-arduino-i2c/overo-c
    ~$ export OETMP=/oe5 [optional if you have a non-standard OETMP]
    ~$ make
    /oe5/sysroots/`uname -m`-linux/usr/armv7a/bin/arm-angstrom-linux-gnueabi-gcc -Wall -I /oe5/sysroots/armv7a-   angstrom-linux-gnueabi/usr/include -L /oe5/sysroots/armv7a-angstrom-linux-gnueabi/usr/lib overo-i2c.c -o overo-i2c
    
Then copy the *overo-i2c* executable to your Overo.





