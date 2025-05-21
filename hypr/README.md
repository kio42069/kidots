<div align="center">
    <h1>✦ Google-ish Hyprlock Theme ✦</h1>
    <h3></h3>
</div>

## ▶️ Preview
<details>
	<summary><b>Without Profile & User Info</b></summary>
	<img src="https://github.com/user-attachments/assets/7bbacd47-b0d7-4132-9951-53dc0ead604c" alt="Hyprlock-Without-Profile" width="1280">
</details>
<details>
	<summary><b>With Profile & User Info</b></summary>
	<img src="https://github.com/user-attachments/assets/9a58a6e2-a71f-4b28-998a-8a45c8950aaf" alt="Hyprlock-With-Profile" width="1280">
</details>
<details>
	<summary><b>With Profile & User Info [12H Format]</b></summary>
	<img src="https://github.com/user-attachments/assets/e0049860-7511-432e-8814-8d17d448182b" alt="Hyprlock-With-Profile" width="1280">
</details>

## 📦 Installation
><i><b>❗ This configuration is based on a 1080p display, if you are using a higher screen resolution,</br>you may need to reconfigure the sizes and recoordinate all the components.</b></i>

<b>Auto-Installation :</b>
```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tamarindtype/googlish-hyprlock-theme/main/install.sh)"
```
</br><b>Manual Installation :</b>
```bash
# Backup your current Hyprlock config first!
# Clone the repository
git clone https://github.com/Tamarindtype/googlish-hyprlock-theme.git

# Move all the files to the hyprland config folder
mv ./googlish-hyprlock-theme/* ~/.config/hypr/

# Go to script folder
cd $HOME/.config/hypr/hyprlock/

# Change all the scripts permission to make them executable
chmod +x *.sh

# Run the Hyprlock
hyprlock
```

## 🗄️ Directory Location
```md
$HOME
└── .config
    └── hypr
        ├── hyprlock
        │  ├── assets
        │  ├── battery.sh
        │  ├── bluetooth.sh
        │  ├── greeting.sh
        │  ├── network.sh
        │  ├── medianotif.sh
        │  └── weatherinfo.sh
        └── hyprlock.conf
```

## 🗨️ FAQ
| Question | Answer |
| --- | --- |
| Profile & User info does not appear? | By default, it set without profile and user info. You can enable it by uncomment the `image` @PROFILE PICTURE and `label` @USER INFO in `hyprlock.conf` |
| Battery percentage number does not appear? | Change your battery module in `battery.sh`. The default is `BAT0`, you can check it by running this command `ls /sys/class/power_supply/` |
| How to change the 24H Format to 12H Format? | Comment the 24H format and uncomment the 12H format. also uncomment the AM/PM `label` & `shape` in `hyprlock.conf` |
| null location or Unable to determine your location? | Change the IP Geolocation provider in `weatherinfo.sh` |

## 🏅 Recommendations
| Type | Name | Links |
| --- | --- | --- |
| Regular | PP Neue Machina | [Pangram Pangram](https://pangrampangram.com/products/neue-machina) |
| Nerd Font | Geist & Space Mono | [Nerd Fonts](https://github.com/ryanoasis/nerd-fonts/releases) |
| Emoji | Apple Emoji | [apple-emoji-linux](https://github.com/samuelngs/apple-emoji-linux) |

## ✨ Special Thanks & Credits

| Details | Credit |
| --- | --- |
| Battery & Playerctl Widget Scripts | @ashish-kus [minimal Hyprlock](https://gist.github.com/ashish-kus/dd562b0bf5e8488a09e0b9c289f4574c) |
| Helped Me Create Dynamic WiFi, Bluetooth, Weathercast and Greeting Widget | @OPENAI [ChatGPT](https://chatgpt.com/)|


## 🤖 ChatGPT in Action
<details>
  <summary>Some help from ChatGPT</summary>

## My Dynamic WiFi prompt:
>Can you please create a working dynamic wifi widget? I got u a script example from battery widget:
```bash
#!/bin/bash

# Get the current battery percentage
battery_percentage=$(cat /sys/class/power_supply/BAT0/capacity)

# Get the battery status (Charging or Discharging)
battery_status=$(cat /sys/class/power_supply/BAT0/status)

# Define the battery icons for each 10% segment
battery_icons=("󰂃" "󰁺" "󰁻" "󰁼" "󰁽" "󰁾" "󰁿" "󰂀" "󰂁" "󰁹")

# Define the charging icon
charging_icon="󰂄"

# Calculate the index for the icon array
icon_index=$((battery_percentage / 10))

# Get the corresponding icon
battery_icon=${battery_icons[icon_index]}

# Check if the battery is charging
if [ "$battery_status" = "Charging" ]; then
	battery_icon="$charging_icon"
fi

# Output the battery percentage and icon
echo "$battery_percentage% $battery_icon"
```
## ChatGPT Answer:
Here's a **dynamic Wi-Fi widget** script inspired by your battery widget example. This script fetches the Wi-Fi connection status, SSID, and signal strength, then displays an appropriate icon based on the signal quality.

### Wi-Fi Widget Script (wifi_widget.sh)
```bash
#!/bin/bash

# Get Wi-Fi connection status
wifi_status=$(nmcli -t -f WIFI g)

# Check if Wi-Fi is enabled
if [ "$wifi_status" != "enabled" ]; then
    echo "󰤮 Wi-Fi Off"
    exit 0
fi

# Get active Wi-Fi connection details
wifi_info=$(nmcli -t -f ACTIVE,SSID,SIGNAL dev wifi | grep '^yes')

# If no active connection, show "Disconnected"
if [ -z "$wifi_info" ]; then
    echo "󰤮 No Wi-Fi"
    exit 0
fi

# Extract SSID
ssid=$(echo "$wifi_info" | cut -d':' -f2)

# Extract signal strength
signal_strength=$(echo "$wifi_info" | cut -d':' -f3)

# Define Wi-Fi icons based on signal strength
wifi_icons=("󰤯" "󰤟" "󰤢" "󰤥" "󰤨") # From low to high signal

# Calculate the icon index based on signal strength (0–100 -> 0–4)
icon_index=$((signal_strength / 25))

# Get the corresponding icon
wifi_icon=${wifi_icons[icon_index]}

# Output the SSID and icon
echo "$wifi_icon $ssid"

```

## How It Works

1. Wi-Fi Status Check:
	- Uses nmcli -t -f WIFI g to check if Wi-Fi is enabled.
	- If Wi-Fi is off, it outputs 󰤮 Wi-Fi Off.

2. Active Connection Details:
	- Uses nmcli to fetch the SSID and signal strength of the active connection.
	- If no connection is active, it outputs 󰤮 No Wi-Fi.

3. Signal Strength Icons:
	- Maps signal strength (0–100) to icons (󰤯 to 󰤨).

4. Dynamic Output:
	- Displays the icon, SSID, and signal strength percentage.

## Example Outputs

1. Wi-Fi Connected:
```bash
󰤥 MyWiFiNetwork
```
2. WiFi Off:
```bash
󰤮 Wi-Fi Off
```
3. No Connection
```bash
󰤮 No Wi-Fi
```

## Integration with `hyprlock.conf`
No changes needed to your `hyprlock.conf`:
```conf
label {
    # Wi-Fi Widget
    monitor = 0
    text = "$(bash ~/.config/hypr/hyprlock/wifi_widget.sh)"
    
	 shadow_passes = 1
    shadow_boost = 0.5
    color = $text_color
    font_size = 30
    font_family = $font_family

    position = 0, 700
    halign = center
    valign = center
}
```

## Setup Instructions

1. Save the Script: Save the script in your $scrPath directory as wifi_widget.sh:
```bash
nano ~/.config/hypr/hyprlock/wifi_widget.sh
```
2. Make It Executable:
```bash
chmod +x ~/.config/hypr/hyprlock/wifi_widget.sh
```
3. Test the Script: Run the script to verify:
```bash
~/.config/hypr/hyprlock/wifi_widget.sh
```
4. Reload Hyprlock: Reload or restart Hyprlock to see the widget in action.

## Dependencies

- Ensure nmcli is installed (comes with NetworkManager).
```bash
    sudo pacman -S networkmanager
```
Let me know if you'd like any further customization! 😊

</details>
