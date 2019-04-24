obj-m = netlink_kernel.o

modules:
	make -C /lib/modules/`uname -r`/build M=${PWD} modules
	gcc netlink_user.c -o netlink_user

clean:
	make -C /lib/modules/`uname -r`/build M=${PWD} clean
	rm netlink_user
