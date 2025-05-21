#!/bin/bash

# Check if any Waybar process is running
if ! pgrep -x "waybar" > /dev/null; then
    echo "Waybar is not running. Launching two instances..."

    # Launch second command first (config.jsonc)
    waybar -c ~/.config/waybar/config.jsonc -s ~/.config/waybar/style.css &

    # Slight delay to ensure the first starts before launching the second
    sleep 1

    # Launch first command (config)
    # waybar -c ~/.config/waybar/config -s ~/.config/waybar/style &

    echo "Both Waybar instances launched."
else
    echo "Waybar is already running."
    pkill waybar
fi

