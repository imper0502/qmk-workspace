# pragmatic56

![pragmatic56](imgur.com image replace me!)

_A short description of the keyboard/project_

- Keyboard Maintainer: [James Sa](https://github.com/jamessa)
- Hardware Supported: _The PCBs, controllers supported_
- Hardware Availability: _Links to where you can find this hardware_

Make example for this keyboard (after setting up your build environment):

    make pragmatic56:default

Flashing example for this keyboard:

    make pragmatic56:default:flash

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
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## Layouts

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

### LAYOUT_34keys

```
LAYOUT_split_3x5_2
    ┌───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┐
    │   │   │   │   │   │             │   │   │   │   │   │
    ├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
    │   │   │   │   │   │             │   │   │   │   │   │
    ├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
    │   │   │   │   │   │             │   │   │   │   │   │
    └───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┘
                    ┌───┬───┐     ┌───┬───┐
                    │   │   │     │   │   │
                    └───┴───┘     └───┴───┘
```
