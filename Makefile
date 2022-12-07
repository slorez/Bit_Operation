TARGET = main
CC = gcc

PREF_OBJ = ./obj/
PREF_SRC = ./src/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_OBJ)%.c, $(PREF_OBJ)%.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c 
	$(CC) -c $< -o $@

clean :
	del *.exe $(PREF_OBJ)*.o