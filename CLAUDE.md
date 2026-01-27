# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Zenith-ZMK is a ZMK firmware configuration for a **custom variant of the TOTEM keyboard**. This is vendor-provided firmware for a modified TOTEM design that adds an extra column compared to the original TOTEM layout. The keyboard runs on the Seeeduino XIAO BLE microcontroller and uses the ZMK (Zephyr Mechanical Keyboard) firmware framework.

**Key components:**
- **Board:** Seeeduino XIAO BLE (nrf52 ARM processor)
- **Shield:** Custom TOTEM variant (split keyboard with left/right halves)
- **Firmware Base:** ZMK + urob's ZMK modules for advanced features

**Hardware layout:**
- 42 keys total (6 columns × 3 rows + 3 thumb keys per side)
- Split wireless keyboard with Bluetooth connectivity

## Advanced Features

This configuration includes advanced features ported from urob's zmk-config:

| Feature | Description |
|---------|-------------|
| **Timeless Homerow Mods** | GACS mods on home row with no misfires or delays |
| **Smart Num Layer** | Auto-toggle num_word that deactivates after numbers |
| **Magic Shift** | Repeat after alpha, sticky-shift otherwise, caps-word on double-tap |
| **Symbol Combos** | Fast symbol access via key combinations |
| **Leader Key** | Multi-key sequences for system commands |
| **Mod-Morphs** | Context-aware punctuation (comma→semicolon, dot→colon) |

## Directory Structure

```
config/                             # User configuration (main editing location)
├── totem.keymap                   # Main keymap with layers and bindings
├── totem.conf                     # ZMK feature configuration
├── west.yml                       # West manifest with ZMK modules
├── key-labels-42.h                # Key position aliases (LT0, RM1, etc.)
├── behaviors.dtsi                 # Custom behaviors (HRMs, smart layers)
├── combos.dtsi                    # Symbol combo definitions
└── leader.dtsi                    # Leader key sequences

boards/
├── arm/seeeduino_xiao_ble/        # Board definition (DO NOT MODIFY)
└── shields/totem/                 # Shield definition (DO NOT MODIFY)
    ├── totem.dtsi                 # Matrix and GPIO configuration
    ├── totem_left.overlay         # Left half pin assignments
    └── totem_right.overlay        # Right half pin assignments

Justfile                           # Local build commands
build.yaml                         # CI build targets
```

## Build System

### Local Build (using Just)

```bash
# First time setup
just init

# Build all firmware
just build

# Build individual targets
just left      # Left half only
just right     # Right half only
just reset     # Settings reset firmware

# Clean build artifacts
just clean
```

### GitHub Actions Build

Push to repository triggers automatic build. Download firmware artifacts from Actions tab.

### Manual West Commands

```bash
west build -b seeeduino_xiao_ble -s zmk/app -- -DZMK_CONFIG=config -DSHIELD=totem_left
west build -b seeeduino_xiao_ble -s zmk/app -- -DZMK_CONFIG=config -DSHIELD=totem_right
```

## Keymap Structure

**Layers:**
- `DEF (0)`: Base QWERTY with homerow mods
- `NAV (1)`: Navigation, arrows, editing
- `GAMING (2)`: Gaming mode (no homerow mods)
- `NUM (3)`: Numbers and function keys
- `SYS (4)`: System layer (BT, reset) - activated by NAV+NUM

**Key Position Labels** (defined in `key-labels-42.h`):
```
╭──────────────────────────────────╮   ╭──────────────────────────────────╮
│ LT5  LT4  LT3  LT2  LT1  LT0    │   │ RT0  RT1  RT2  RT3  RT4  RT5    │
│ LM5  LM4  LM3  LM2  LM1  LM0    │   │ RM0  RM1  RM2  RM3  RM4  RM5    │
│ LB5  LB4  LB3  LB2  LB1  LB0    │   │ RB0  RB1  RB2  RB3  RB4  RB5    │
╰───────────╮ LH2  LH1  LH0       │   │      RH0  RH1  RH2 ╭────────────╯
            ╰─────────────────────╯   ╰──────────────────────╯
```

## ZMK Modules (from urob)

The `west.yml` includes these modules from urob's GitHub:
- `zmk-helpers` - Macro helpers for behaviors
- `zmk-auto-layer` - Smart layer behaviors (num_word)
- `zmk-tri-state` - Three-state behaviors (swapper)
- `zmk-adaptive-key` - Context-aware keys (magic shift)
- `zmk-leader-key` - Leader key sequences
- `zmk-unicode` - Unicode input support

## Critical Files (DO NOT MODIFY)

These files define hardware configuration and must not be changed:
- `boards/shields/totem/totem.dtsi` - Matrix and row GPIOs
- `boards/shields/totem/totem_left.overlay` - Left half column pins
- `boards/shields/totem/totem_right.overlay` - Right half column pins
- `boards/shields/totem/Kconfig.*` - Split keyboard settings
- `boards/arm/seeeduino_xiao_ble/*` - Board definition

## Firmware Flashing

1. Put keyboard half in bootloader mode (double-tap reset button)
2. USB drive appears (name varies: "NICENANO", "XIAO", etc.)
3. Copy `.uf2` file from `firmware/` folder to the drive
4. Keyboard reboots automatically

Flash both halves when updating keymap.

## Common Customization Tasks

### Adding a New Combo
Edit `config/combos.dtsi`:
```c
ZMK_COMBO(name, &binding, KEY1 KEY2, LAYERS, COMBO_TERM_FAST, COMBO_IDLE_FAST)
```

### Adding a New Layer
1. Add layer index in `config/totem.keymap`: `#define NEWLAYER 5`
2. Add layer definition in keymap section
3. Add layer access key on existing layer

### Modifying Homerow Mods
Edit timing in `config/behaviors.dtsi`:
- `tapping-term-ms` - Hold duration threshold
- `require-prior-idle-ms` - Typing cooldown
- `quick-tap-ms` - Double-tap threshold

### Adding Leader Sequences
Edit `config/leader.dtsi`:
```c
ZMK_LEADER_SEQUENCE(name, &binding, K E Y S)
```

## Debugging

- **Build errors**: Check GitHub Actions logs or local west output
- **Keys not working**: Verify matrix positions in keymap match hardware
- **Bluetooth issues**: Use `settings_reset` firmware to clear pairing
- **Homerow mod misfires**: Adjust timing in `behaviors.dtsi`

## References

- [ZMK Documentation](https://zmk.dev/)
- [urob's zmk-config](https://github.com/urob/zmk-config) - Feature source
- [ZMK Discord](https://zmk.dev/community/discord/invite) - Community support
