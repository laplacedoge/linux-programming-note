BUILD_DIR := ./build

all: dir_target obj_target

dir_target:
	mkdir -p $(BUILD_DIR)

obj_target:
	gcc -o $(BUILD_DIR)/parent parent.c
	gcc -o $(BUILD_DIR)/child1 child1.c
	gcc -o $(BUILD_DIR)/child2 child2.c
	gcc -o $(BUILD_DIR)/child3 child3.c

clean:
	rm -rf $(BUILD_DIR)
