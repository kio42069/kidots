# export LC_ALL="en_US.UTF-8"
# export LC_CTYPE="en_US.UTF-8"
export PATH="$HOME/.local/bin:$PATH"
export ZSH=$HOME/.oh-my-zsh
export ZSH_COMPDUMP=$ZSH/cache/.zcompdump-$HOST
ZSH_THEME="cloud"
zstyle ':omz:update' mode disabled  # disable automatic updates
zshcache_time="$(date +%s%N)"

autoload -Uz add-zsh-hook

rehash_precmd() {
  if [[ -a /var/cache/zsh/pacman ]]; then
    local paccache_time="$(date -r /var/cache/zsh/pacman +%s%N)"
    if (( zshcache_time < paccache_time )); then
      rehash
      zshcache_time="$paccache_time"
    fi
  fi
}

plugins=(git archlinux battery catimg colored-man-pages copybuffer copyfile copypath dirhistory dnote lol man ssh sudo z)
source $ZSH/oh-my-zsh.sh

# wal -i .config/hypr/wallpapers/wonder.jpg > /dev/null
wal -R > /dev/null
add-zsh-hook -Uz precmd rehash_precmd
fastfetch --config ~/.config/fastfetch/config.jsonc --logo ~/.config/fastfetch/ascii

# =============== ALIASES =============== # 
alias n='fastfetch'
alias py='python'
# alias code='codium --ozone-platform=wayland'
alias vpn='sudo openfortivpn vpn.iiitd.edu.in:10443 --username=surat22517'
alias nm='sudo iwlist wlan0 scan && nmtui'
alias hypr='cd ~/.config/hypr && vim hyprland.conf'
alias zsh='source ~/.zshrc'
alias vim='nvim'
alias i="echo 'ios_base::sync_with_stdio(false);cin.tie(NULL);' | wl-copy"
alias rem='pacman -Qdtq | sudo pacman -Rsn -'
alias cam='mpv av://v4l2:/dev/video0'
export PATH=$PATH:/home/surt/.spicetify
alias gcl='git clone'
alias btop='btop --force-utf'
# alias refresh='sudo virsh net-start default'
alias kio='ssh kio@172.24.32.12'

# =============== TERMINAL COUNTER =============== # 
TERMINAL_COUNT_FILE="$HOME/.terminal_launch_count"
count=$(<"$TERMINAL_COUNT_FILE")
count=$((count + 1))
echo "$count" > "$TERMINAL_COUNT_FILE"
# echo "gg $count terminals"
