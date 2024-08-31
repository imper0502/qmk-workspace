# IMPER0502's QMK Workspace

## Docker Commands
```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest /bin/bash

docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk --version

docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk doctor

docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk help

docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk setup -y

docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" qmkfm/qmk_cli:latest qmk compile -kb <keyboard> -km <keymap> -t targets/<keyboard>_<keymap>.hex

```

## Make Targets
```sh
make install

make imper0502

make pragmatic_imper0502

make clean

make uninstall

```
