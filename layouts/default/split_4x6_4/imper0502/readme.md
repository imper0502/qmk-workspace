# The imper0502's keymap

## Compile

### Pragmatic

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" -w /qmk_firmware qmkfm/qmk_cli:latest qmk compile -kb pragmatic -km imper0502 -t targets/pragmatic_imper0502.hex
```

### Temperance

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" -w /qmk_firmware qmkfm/qmk_cli:latest qmk compile -kb temperance -km imper0502 -t targets/temperance_imper0502.hex
```
