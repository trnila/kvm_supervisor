#!/bin/sh
export SWAYSOCK=$(ls /run/user/1000/sway-ipc.1000.*.sock)
swaymsg output LVDS-1 enable
