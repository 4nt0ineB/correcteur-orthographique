# Variables de compilation
CC = gcc
CFLAGS = -ansi -pedantic -Wall
LDFLAGS =
# Définitions des répertoire de travail
SRC_DIR = src
HEADERS_DIR= include
OUT_DIR = bin
OBJ_DIR = $(OUT_DIR)/obj
#
exe =
ARGS =
# Résolution des chemins (et on extrait les nos main avec grep)
SRC = $(shell find src/ -name \*.c | grep -v "correcteur_.")
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEP = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))

all: install

# Compilation
$(exe): $(OBJ) $(OBJ_DIR)/$(exe).o
	$(CC) $^ -o $(OUT_DIR)/$@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/$(exe).o: $(SRC_DIR)/$(exe).c
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS)

#include la definitions des dependance de chaque fichier objet x.o: x.c x.h
-include ${DEP}

# Créer les répertoires des fichiers objets et executable
--make_install_dir:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(shell dirname $(OBJ))

# verifier l'argument pour choisir l'executable lors de la compilation
--checkargs:
ifndef exe
	$(error Erreur. Il manque un argument, make --> exec=correcteur_x <-- [install/run/uninstall])
endif

.PHONY: clean
clean:
	@rm -rf $(OUT_DIR)

install: --checkargs --make_install_dir $(exe)
uninstall: clean

exemple1: install
	./$(OUT_DIR)/$(exe) ./data/a_corriger_0.txt ./data/dico_1.dico

exemple2: install
	./$(OUT_DIR)/$(exe) ./data/a_corriger_1.txt ./data/dico_2.dico



