#!/bin/bash
command_output=$(hyprpm list | grep true)
if [[ -n "$command_output" ]]; then
  hyprpm disable hyprbars
else
  hyprpm enable hyprbars
  hyprctl dismissnotify
fi

