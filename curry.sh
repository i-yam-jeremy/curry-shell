#!/bin/bash

function handle_line {
  echo "handle_line: " $1
}

while true
do
  printf "> "
  read line
  handle_line "$line"
done
