#!/bin/bash

debootstrap sid sid

# Use same users as main system
cd sid/etc
rm passwd; ln /etc/passwd .
rm shadow; ln /etc/shadow .
rm group; ln /etc/group .
rm hosts; ln /etc/hosts .
#fonte: www.rutschle.net/2009/03/13/Securely_running_Firefox_in_a_chroot.html
