#!/bin/bash

raise_volume() {
    if [[ $(pamixer --get-volume) -lt 120 ]]; then
        pamixer --unmute
        pactl set-sink-volume @DEFAULT_SINK@ +5%
    else
        pactl set-sink-volume @DEFAULT_SINK@ 120%
    fi
    current_volume=$(pamixer --get-volume)
    notify-send -i ~/.config/dunst/assets/ui/volume_up.png -h string:x-canonical-private-synchronous:sys-notify $current_volume
}

lower_volume() {
    pamixer --unmute
    pactl set-sink-volume @DEFAULT_SINK@ -5%
    current_volume=$(pamixer --get-volume)
    notify-send -i ~/.config/dunst/assets/ui/volume_down.png -h string:x-canonical-private-synchronous:sys-notify $current_volume
}

toggle_mute() {
    pamixer --toggle-mute
}

case $1 in
    raise)
        raise_volume;;
    lower)
        lower_volume;;
    mute)
        toggle_mute;;
esac


