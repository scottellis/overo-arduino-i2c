# Angstrom minimalist image with some dev tools and ssh access

DEPENDS = "task-sdk-native"

ANGSTROM_EXTRA_INSTALL ?= "\
	devmem2 \
	openssh-scp \
	tcpdump \
	task-native-sdk \
	python \
        python-fcntl \
	"

DISTRO_SSH_DAEMON ?= "openssh"

IMAGE_PREPROCESS_COMMAND = "create_etc_timestamp"

IMAGE_INSTALL = "task-boot \
            util-linux-ng-mount util-linux-ng-umount \
            ${DISTRO_SSH_DAEMON} \
            ${ANGSTROM_EXTRA_INSTALL} \
            angstrom-version \
            ${SPLASH} \
	   "

export IMAGE_BASENAME = "dev-image"
IMAGE_LINGUAS = ""

inherit image

