# #!/usr/bin/env sh
# HYPRGAMEMODE=$(hyprctl getoption animations:enabled | awk 'NR==1{print $2}')
# if [ "$HYPRGAMEMODE" = 1 ] ; then
#     hyprctl --batch "\
#         keyword animations:enabled 0;\
#         keyword decoration:drop_shadow 0;\
#         keyword decoration:blur:enabled 0;\
#         keyword general:gaps_in 0;\
#         keyword general:gaps_out 0;\
#         keyword general:border_size 1;\
#         keyword misc:vfr true;\
#         keyword decoration:rounding 0"
#     exit
# fi
# hyprctl reload
#
#!/bin/bash

on=$(hyprctl -j getoption animations:enabled | jq --raw-output '.int')

if [[ $on -eq 1 ]]; then
    hyprctl keyword animations:enabled 0
    brightnessctl s 5000
    cp ~/.config/hypr/scripts/low.conf ~/.config/hypr/hypridle.conf
    pkill swww
    pkill hyprpaper
    hyprpm disable hyprbars
    pkill waybar
    pkill hypridle
    hyprctl keyword animations:enabled 0
    hypridle & hyprctl notify -1 1000 "rgb(e06c75)" "Animations off"
  else
    hyprctl keyword animations:enabled 1
    pkill hypridle
    cp ~/.config/hypr/scripts/high.conf ~/.config/hypr/hypridle.conf
    swww-daemon & hyprpaper & hypridle & hyprpm enable hyprbars & waybar & hyprctl notify -1 1000 "rgb(98c379)" "Animations on"
fi
