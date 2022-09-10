#! /usr/bin/zsh

mkdir $1 
touch $1/main.go

if [[ $2 == "c" ]]
then
    code $1/main.go
fi
