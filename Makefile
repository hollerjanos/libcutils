CC       ?= cc
AR       ?= ar

CFLAGS   ?= -std=c11 -Wall -Wextra -Wpedantic -O2
CPPFLAGS += -Iinclude

TARGET   := lib/libcutils.a
SOURCES  := src/error.c
OBJECTS  := $(pathsubst src/%.c, obj/%.o, $(SOURCES))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(AR) rcs $@ $^

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj lib
