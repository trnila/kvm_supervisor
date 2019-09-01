all:

install_udev_rule: kvm_supervisor.rules
	cp -v $^ /etc/udev/rules.d/
	udevadm control --reload-rules

install_%: % install_udev_rule
	cp -rv $< /etc/dock/
