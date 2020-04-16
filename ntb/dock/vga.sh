#!/bin/bash
exec > /tmp/x 2>&1

DELAY_MS=5000
SLEEP_MS=100

RETRIES=$((DELAY_MS / SLEEP_MS))
DELAY=$(echo "scale=1; $SLEEP_MS/1000" | bc)

export SWAYSOCK=$(ls /run/user/1000/sway-ipc.1000.*.sock)

for i in $(seq 1 $RETRIES); do
  if swaymsg output LVDS-1 disable; then
    break
  fi
  sleep "$DELAY"
done
