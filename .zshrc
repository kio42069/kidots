export ZSH=$HOME/.oh-my-zsh
ZSH_THEME="archcraft"
zstyle ':omz:update' mode disabled  # disable automatic updates
source $ZSH/oh-my-zsh.sh
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

add-zsh-hook -Uz precmd rehash_precmd
alias zshconfig="geany ~/.zshrc"
alias ohmyzsh="thunar ~/.oh-my-zsh"
source /usr/share/zsh-theme-powerlevel10k/powerlevel10k.zsh-theme

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh
# wal -i ~/Downloads/yellow_structure_hd.jpg
#cal
fastfetch --config ~/.config/fastfetch/config.jsonc --logo ~/.config/fastfetch/ascii
alias n='fastfetch'
alias py='python'
alias code='code --ozone-platform=wayland'
alias pi='ssh kid@192.168.239.238'
alias btop='btop --utf-force'
alias vpn='sudo openfortivpn vpn.iiitd.edu.in:10443 --username=surat22517'
alias nm='sudo iwlist wlan0 scan && nmtui'
alias hypr='cd ~/.config/hypr && vim hyprland.conf'
alias zsh='source ~/.zshrc'
alias vim='nvim'
alias n="fastfetch --config ~/.config/fastfetch/config.jsonc --logo ~/.config/fastfetch/ascii"
# cat ~/.cache/wal/sequences
alias sql='sudo mariadb -u root -plp manga'
# source ~/.cache/wal/colors-tty.sh
alias inf="cat ~/.config/hypr/scripts/inf | wl-copy"
alias i="echo 'ios_base::sync_with_stdio(false);cin.tie(NULL);' | wl-copy"
alias rem='pacman -Qdtq | sudo pacman -Rsn -'
alias spotify='spotify & sleep 0.5 && spicetify restart'
alias dock='docker run -it kiddo'
alias m='musikcube'
