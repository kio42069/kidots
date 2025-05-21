#!/bin/bash

# Check the active window title
active_window_title=$(hyprctl activewindow | grep -oP '(?<=title: ").*(?=")')

# Define the command to kill or restart focusclock
kill_or_restart_focusclock() {
  # killall -SIGTERM focusclock || focusclock -br -B "$1" -R 30 -a 1 -c C78162 -F HurmitNerdFont-BoldItalic
  killall -SIGTERM focusclock || focusclock -br -B "$1" -R 30 -B 20 -a 1 -c C78162 -F HurmitNerdFont-BoldItalic
}

# If the active window title contains "vim", set brightness to 40, otherwise to 80
if [[ "$active_window_title" =~ vim ]]; then
  kill_or_restart_focusclock 40
else
  kill_or_restart_focusclock 80
fi

