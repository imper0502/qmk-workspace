# IMPER0502's QMK Workspace

## Docker Commands
```sh
# Enter Bash
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest /bin/bash

# Check QMK Version
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk --version

# Verify QMK
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk doctor

# QMK Client Help
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk help

# Setup QMK
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk setup -y

# Compile HEX
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" qmkfm/qmk_cli:latest qmk compile -kb <keyboard> -km <keymap> -t targets/<keyboard>_<keymap>.hex

```

## Make Targets
```sh
make install

make imper0502

make pragmatic_imper0502

make clean

make uninstall

```
