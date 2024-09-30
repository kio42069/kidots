#!/usr/bin/env bash

op=$( echo -e "  pow\n  reb\n  sus\n  bye" | wofi -i --dmenu --conf ~/.config/hypr/wofi/config --style ~/.config/hypr/wofi/style.css --width 10 --height 200 --xoffset 800 --yoffset 450 )

case $op in
  poweroff)
    poweroff
    ;&
  reboot)
    reboot
    ;&
  logout)
    pkill Hyprland
    ;;
  hibernate)
    systemctl suspend
    ;;
esac
