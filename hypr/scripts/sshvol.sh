#!/bin/bash

# Check if an argument is passed
if [ -z "$1" ]; then
  echo "Usage: $0 [i|d]"
  exit 1
fi

# IP and command details
USER="arv"
HOST="192.168.45.146"
SINK_ID=3

# Decide based on input
case "$1" in
  i)
    ssh "$USER@$HOST" "/usr/bin/pamixer -d 5"
    # ssh "$USER@$HOST" "/usr/bin/pactl set-sink-volume $SINK_ID -10%"
    ;;
  d)
    ssh "$USER@$HOST" "/usr/bin/pamixer -i 5"
    # ssh "$USER@$HOST" "/usr/bin/pactl set-sink-volume $SINK_ID +10%"
    ;;
  *)
    echo "Invalid argument. Use 'i' to decrease or 'd' to increase volume."
    exit 1
    ;;
esac

