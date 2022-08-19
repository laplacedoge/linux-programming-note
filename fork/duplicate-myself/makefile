BUILD_DIR := ./build

all: dir_target obj_target

dir_target:
	mkdir -p $(BUILD_DIR)

obj_target:
	gcc -o $(BUILD_DIR)/main main.c

clean:
	rm -rf $(BUILD_DIR)
