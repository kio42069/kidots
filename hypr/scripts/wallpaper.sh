#!/bin/bash
#WALLPAPER_LIST="/home/surt/.config/hypr/scripts/available_wallpapers"
#INDEX_FILE="/home/surt/.config/hypr/scripts/.current_wallpaper_index"
#CURRENT_INDEX=$(cat "$INDEX_FILE")
#mapfile -t WALLPAPERS < "$WALLPAPER_LIST"
#NEXT_INDEX=$(( (CURRENT_INDEX + 1) % ${#WALLPAPERS[@]} ))
# #hyprctl hyprpaper wallpaper "eDP-1,${WALLPAPERS[$NEXT_INDEX]}"
#image=${WALLPAPERS[$NEXT_INDEX]}
#swww img "$image" --transition-step 1 --transition-fps 60  --transition-type any
# # echo "swww img $image --transition-step 10 --transition-fps 60"
#echo "$NEXT_INDEX" > "$INDEX_FILE"
#echo $image



# Set the path to the wallpapers directory
wallpapersDir="$HOME/.config/hypr/wallpapers"
wallpapers=("$wallpapersDir"/*)
wallpaperIndex=$(( RANDOM % ${#wallpapers[@]} ))
selectedWallpaper="${wallpapers[$wallpaperIndex]}"

auto(){
  while true;
  do
    wallpaperIndex=$(( RANDOM % ${#wallpapers[@]} ))
    selectedWallpaper="${wallpapers[$wallpaperIndex]}"
    swww img "$selectedWallpaper" --transition-step 1 --transition-fps 60
    sleep 10m
  done
}

balls(){
  swww img "$selectedWallpaper" --transition-step 1 --transition-fps 60
}

case "$1" in
  auto)
    auto;;
  *)
    balls;;
esac
