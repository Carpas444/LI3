CC=gcc

CFLAGS=-Wall -g -Iinclude `pkg-config --cflags glib-2.0`

LDFLAGS=`pkg-config --libs glib-2.0` -lm

TARGET_MAIN := programa-principal

TARGET_TESTS := programa-testes

TARGET_INTER := programa-interativo

OBJS_DIR := ./objs
SRC_DIRS := src

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

OBJS := $(SRCS:%.c=$(OBJS_DIR)/%.o)

all : $(TARGET_MAIN) $(TARGET_TESTS) $(TARGET_INTER)

$(TARGET_TESTS): $(OBJS) $(OBJS_DIR)/testes.o recomendador/recomendador.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	echo $@ feito

$(TARGET_INTER): $(OBJS) $(OBJS_DIR)/interativo.o recomendador/recomendador.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	echo $@ feito

$(TARGET_MAIN): $(OBJS) $(OBJS_DIR)/principal.o recomendador/recomendador.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	echo $@ feito

$(OBJS_DIR)/principal.o : principal.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo $@ feito

$(OBJS_DIR)/testes.o : testes.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo $@ feito

$(OBJS_DIR)/interativo.o : interativo.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo $@ feito

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	echo $@ feito


clean:
	rm -r $(OBJS_DIR) resultados/*.csv resultados/*.txt programa-principal programa-testes programa-interativo

