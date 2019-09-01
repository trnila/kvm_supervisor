#!/bin/sh

DELAY_MS=5000
SLEEP_MS=100

RETRIES=$((DELAY_MS / SLEEP_MS))
DELAY=$(echo "scale=1; $SLEEP_MS/1000" | bc)

export DISPLAY=:0

for i in $(seq 1 $RETRIES); do
  if xrandr  | grep VGA1 -A10 | grep 1920x1080 | grep -F '*'; then
   break 
  fi

  xrandr --output VGA1 --mode 1920x1080 --output LVDS1 --off
  sleep "$DELAY"
done
