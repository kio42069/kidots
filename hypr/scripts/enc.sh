#!/bin/bash

while getopts 'ed' flag; do
  case "${flag}" in 
    e) echo "encrypting..."
       zip -r ~/Documents/alright.zip ~/Documents/alright
       gpg --no-symkey-cache -c ~/Documents/alright.zip
       rm -rf ~/Documents/alright
       rm -rf ~/Documents/alright.zip
       echo "done!!!"
       ;;
    d) echo "decrypting..."
       gpg -d ~/Documents/alright.zip.gpg > ~/Documents/alright.zip
       unzip ~/Documents/alright.zip
       rm -rf ~/Documents/alright.zip
       rm -rf ~/Documents/alright.zip.gpg
       ;;
  esac
done

