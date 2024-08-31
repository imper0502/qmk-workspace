# Temperance

![temperance](imgur.com image replace me!)

_A short description of the keyboard/project_

- Keyboard Maintainer: [imper0502](https://github.com/imper0502)
- Hardware Supported: _The PCBs, controllers supported_
- Hardware Availability: _Links to where you can find this hardware_

Make example for this keyboard (after setting up your build environment):

    make temperance:default

Flashing temperance for this keyboard:

    make temperance:default:flash

See the
[build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and
the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for
more information. Brand new to QMK? Start with our
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top
  left key or Escape) and plug in the keyboard
- **Physical reset button**: Briefly press the button on the back of the PCB -
  some may have pads you must short instead
- **Keycode in layout**: Press the key mapped to `RESET` if it is available

## Setup

```bash
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest qmk setup
```

## Bash

```bash
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest /bin/bash
```

## Compile

```shell
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest qmk compile -kb temperance -km default -t targets/temperance_default.hex
```

## Layouts

### LAYOUT_58keys

```
LAYOUT_split_4x6_5
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
            ┌───┤   │   │   │     │   │   │   ├───┐
            │   ├───┴───┴─┬─┴─┐ ┌─┴─┬─┴───┴───┤   │
            └───┘         │   │ │   │         └───┘
                          └───┘ └───┘
```

### LAYOUT_56keys

```
LAYOUT_split_4x6_4
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
            ┌───┤   │   │   │     │   │   │   ├───┐
            │   ├───┴───┴───┘     └───┴───┴───┤   │
            └───┘                             └───┘
```

### LAYOUT_54keys

```
LAYOUT_split_4x6_3
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
                │   │   │   │     │   │   │   │
                └───┴───┴───┘     └───┴───┴───┘
```

### LAYOUT_44keys

```
LAYOUT_split_3x6_4
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
            ┌───┤   │   │   │     │   │   │   ├───┐
            │   ├───┴───┴───┘     └───┴───┴───┤   │
            └───┘                             └───┘
```

### LAYOUT_42keys

```
LAYOUT_split_3x6_3
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │             │   │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
                │   │   │   │     │   │   │   │
                └───┴───┴───┘     └───┴───┴───┘
```
