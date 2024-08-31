makefile_path := $(abspath $(lastword $(makefile_list)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(makefile_path))))
image_name := qmkfm/qmk_cli
image_tag := latest
ifndef $(keyboard)
keyboard := pragmatic
endif

.phony: install uninstall clean

install:
ifeq ($(shell `docker images -q $(image_name):$(image_tag)` 2> /dev/null),)
	docker pull $(image_name)
endif
	mkdir -p .build
	mkdir -p targets
	docker run -it --rm -v qmk_firmware_dir:/qmk_firmware qmkfm/qmk_cli:latest qmk setup -y

uninstall: clean
	docker volume rm qmk_firmware_dir
	docker image rm $(image_name):$(image_tag)

clean:
	rm -rf .build
	rm -rf targets

$(keymap): $(keyboard)_$(keymap).hex

$(keyboard)_$(keymap).hex: init
	docker run -it \
		--rm \
		-v qmk_firmware_dir:/qmk_firmware \
		-v $$(pwd)/.build:/qmk_firmware/.build \
		-v $$(pwd)/targets:/qmk_firmware/targets \
		-v $$(pwd)/keyboards:/qmk_firmware/keyboards \
		$(image_name):$(image_tag) \
		qmk compile -kb $(keyboard) -km $(keymap) -t /qmk_firmware/targets/$@
