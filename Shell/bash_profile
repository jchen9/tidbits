# ~/.bash_profile: executed by bash(1) for login shells.
# see /usr/share/doc/bash/examples/startup-files for examples.
# the files are located in the bash-doc package.
umask 022

# Using SSH `keychain`
# /opt/local/bin/keychain ~/.ssh/id_dsa
# . ~/.keychain/${HOSTNAME}-sh

# the rest of this file is commented out.

# include .bashrc if it exists

if [ -f ~/.bashrc ]; then
    source ~/.bashrc
fi

# set PATH so it includes user's private bin if it exists

if [ -d ~/bin ] ; then
    PATH=~/bin:"${PATH}"
fi

# test -r /sw/bin/init.sh && . /sw/bin/init.sh

# Cappuccino
export NARWHAL_ENGINE=jsc
export PATH="/Users/julian/Apps/Cappuccino/narwhal/bin:$PATH"
