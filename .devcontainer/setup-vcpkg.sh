#!/usr/bin/env bash
set -e

if [ ! -d "$HOME/vcpkg/.git" ]; then
  git clone https://github.com/microsoft/vcpkg.git "$HOME/vcpkg"
fi

"$HOME/vcpkg/bootstrap-vcpkg.sh"
