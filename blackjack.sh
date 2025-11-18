#!/usr/bin/env bash

set -euo pipefail

# --- Config -------------------------------------------------------------------

BUILD_DIR="build"

# ------------------------------------------------------------------------------

cmd="${1:-}"

case "$cmd" in
  build)
    if ! command -v cmake &> /dev/null; then
      echo "Error: cmake not found. Please install CMake."
      exit 1
    fi
    cmake -S . -B "$BUILD_DIR"
    cmake --build "$BUILD_DIR"
    ;;

  debug)
    if ! command -v cmake &> /dev/null; then
      echo "Error: cmake not found. Please install CMake."
      exit 1
    fi
    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -S . -B "$BUILD_DIR"
    cmake --build "$BUILD_DIR"
    ;;

  clean)
    rm -rf "$BUILD_DIR"
    ;;

  *)
    echo "Usage: $0 {build|debug|clean}"
    exit 1
    ;;
esac

# ------------------------------------------------------------------------------
