# The vial keymap for pragmatic
## Compile

```sh

docker run -it --rm -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmk_workspace:latest /bin/bash -c "qmk compile -kb pragmatic56 -km vial; mv ./pragmatic56_vial.hex ./targets/pragmatic56_vial.hex"

```
