# Zenith-ZMK Build Commands
# Usage: just <command>
#
# Requires: Docker Desktop (https://www.docker.com/products/docker-desktop/)

set shell := ["powershell", "-NoProfile", "-Command"]
set windows-shell := ["powershell", "-NoProfile", "-Command"]

# Docker image for ZMK builds
ZMK_IMAGE := "zmkfirmware/zmk-build-arm:stable"

# Directories
config := justfile_directory() + "/config"
out := justfile_directory() + "/firmware"
workspace := justfile_directory()

default:
    @just --list --unsorted

# Pull the ZMK Docker image
pull:
    @echo "Pulling ZMK build image..."
    docker pull {{ZMK_IMAGE}}

# Initialize west workspace (run once, inside Docker)
init: pull
    @echo "Initializing west workspace..."
    docker run --rm -v "{{workspace}}:/workspace" -w /workspace {{ZMK_IMAGE}} /bin/bash -c "west init -l config && west update && west zephyr-export"
    @echo "Workspace initialized!"

# Update west modules
update:
    docker run --rm -v "{{workspace}}:/workspace" -w /workspace {{ZMK_IMAGE}} /bin/bash -c "west update && west zephyr-export"

# Build a specific shield (ensures workspace is ready)
_build shield:
    @echo "Building {{shield}}..."
    @if (!(Test-Path "{{out}}")) { New-Item -ItemType Directory -Path "{{out}}" | Out-Null }
    docker run --rm -v "{{workspace}}:/workspace" -w /workspace {{ZMK_IMAGE}} /bin/bash -c "if [ ! -f zephyr/.west-initialized ]; then west update && west zephyr-export && touch zephyr/.west-initialized; fi && west build -s zmk/app -b seeeduino_xiao_ble -d .build/{{shield}} --pristine -- -DZMK_CONFIG=/workspace/config -DSHIELD={{shield}} && cp .build/{{shield}}/zephyr/zmk.uf2 /workspace/firmware/{{shield}}.uf2"
    @echo "Created: firmware/{{shield}}.uf2"

# Build left half
left:
    @just _build totem_left

# Build right half
right:
    @just _build totem_right

# Build settings reset firmware
reset:
    @just _build settings_reset

# Build all firmware targets
build: left right reset
    @echo ""
    @echo "All firmware built successfully!"
    @echo "Files in: {{out}}"

# Clean build artifacts
clean:
    @if (Test-Path ".build") { Remove-Item -Recurse -Force ".build" }
    @if (Test-Path "{{out}}") { Remove-Item -Recurse -Force "{{out}}" }
    @echo "Cleaned build artifacts"

# Clean everything including west workspace
clean-all: clean
    @if (Test-Path ".west") { Remove-Item -Recurse -Force ".west" }
    @if (Test-Path "zmk") { Remove-Item -Recurse -Force "zmk" }
    @if (Test-Path "zephyr") { Remove-Item -Recurse -Force "zephyr" }
    @if (Test-Path "modules") { Remove-Item -Recurse -Force "modules" }
    @echo "Cleaned all generated files"

# Show help
help:
    @echo "Zenith-ZMK Build Commands"
    @echo ""
    @echo "First time setup:"
    @echo "  just init     - Initialize workspace (downloads ~2GB)"
    @echo ""
    @echo "Building:"
    @echo "  just build    - Build all firmware"
    @echo "  just left     - Build left half only"
    @echo "  just right    - Build right half only"
    @echo "  just reset    - Build settings reset"
    @echo ""
    @echo "Maintenance:"
    @echo "  just update   - Update ZMK modules"
    @echo "  just clean    - Clean build artifacts"
    @echo "  just pull     - Update Docker image"
    @echo ""
    @echo "Requires: Docker Desktop"
