if [ "$(hyprctl activewindow -j | jq -r ".class")" = "Code" ]; then
    xdotool getactivewindow windowunmap
else
    hyprctl dispatch killactive ""
fi
