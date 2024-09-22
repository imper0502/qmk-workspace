# imper0502's 56-key keymap

## Keymap

```
LAYOUT_split_4x6_4
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│ « │ » │ @ │ # │ ( │ ) │             │ ^ │ & │ * │ $ │ins│del│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│tab│ q │ w │ f │ p │ b │             │ j │ l │ u │ y │- _│= +│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│esc│ a │ r │ s │ t │ g │             │ m │ n │ e │ i │ o │/ %│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│a&c│ z │ x │ c │ d │ v │             │ k │ h │, ;│. :│' "│\ |│
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
            ┌───┤ctl│sft│bs │     │ent│spc│` ~├───┐
            │   ├───┴───┴───┘     └───┴───┴───┤   │
            └───┘                             └───┘
```

## Compile

### Pragmatic

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" -v "$(pwd)/users:/qmk_firmware/users" qmkfm/qmk_cli:latest qmk compile -kb pragmatic -km imper0502 -e FORCE_LAYOUT=split_4x6_4
```

### Temperance

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" -v "$(pwd)/users:/qmk_firmware/users" qmkfm/qmk_cli:latest qmk compile -kb temperance -km imper0502 -e FORCE_LAYOUT=split_4x6_4
```

## Fetch Hex files

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest bash -c "mv *.hex targets/"
```
