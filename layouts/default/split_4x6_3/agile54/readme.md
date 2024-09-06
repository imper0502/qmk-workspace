# Agile54

## Keymap

```
LAYOUT_split_4x6_3
┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┐
│del│ ^ │ @ │ # │ ( │ ) │             │ $ │ & │ * │ ? │ ! │` ~│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│tab│ q │ w │ f │ p │ b │             │ j │ l │ u │ y │- _│= +│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│esc│ a │ r │ s │ t │ g │             │ m │ n │ e │ i │ o │/ %│
├───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┤
│alt│ z │ x │ c │ d │ v │             │ k │ h │, ;│. :│' "│alt│
└───┴───┴───┴───┴───┴───┘             └───┴───┴───┴───┴───┴───┘
                ┌───┬───┬───┐     ┌───┬───┬───┐
                │ctl│sft│bs │     │ent│spc│\ |│
                └───┴───┴───┘     └───┴───┴───┘
```

## Compile

### Pragmatic

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" qmkfm/qmk_cli:latest qmk compile -kb pragmatic -km  
```

### Temperance

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/.build:/qmk_firmware/.build" -v "$(pwd)/targets:/qmk_firmware/targets" -v "$(pwd)/keyboards:/qmk_firmware/keyboards" -v "$(pwd)/layouts:/qmk_firmware/layouts" qmkfm/qmk_cli:latest qmk compile -kb temperance -km agile
```

## Fetch Hex files

```sh
docker run -it --rm -v qmk_firmware_dir:/qmk_firmware -v "$(pwd)/targets:/qmk_firmware/targets" -w /qmk_firmware qmkfm/qmk_cli:latest bash -c "mv *.hex targets/"
```
