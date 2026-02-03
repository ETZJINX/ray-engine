CC = gcc

RAYLIB_PATH = src/raylib-5.5_win64_mingw-w64


INCLUDES = -I$(RAYLIB_PATH)/include -Isrc.
LIBS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm -ldsound -luser32

SRC_DIR = src
SRCS = $(SRC_DIR)/*.c

TARGET = main.exe

all:
	$(CC) $(SRCS) $(INCLUDES) $(LIBS) -o $(TARGET)


run: $(TARGET)
	.\$(TARGET)
clean:
	del /Q *.exe
