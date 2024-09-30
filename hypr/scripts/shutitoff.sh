#!/bin/bash
command_output=$(hyprpm list | grep true)
if [[ -n "$command_output" ]]; then
  hyprpm disable hyprbars
  pkill waybar
else
  hyprpm enable hyprbars && pkill waybar && waybar
fi

