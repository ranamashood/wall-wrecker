CC = gcc
CFLAGS = -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TARGET = $(BUILD_DIR)/$(LINK)
LINK = wall-wrecker

all: $(TARGET) $(LINK)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(LINK):
	ln -sf $(TARGET) $(LINK)

clean:
	rm -rf $(BUILD_DIR) $(LINK)
