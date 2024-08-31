# The qwerty keymap for temperance
## Compile

```bash
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest qmk compile -kb temperance -km default -t targets/temperance_default.hex
```