CC=g++ # Notre compilateur
CFLAGS=-W -Wall -ansi -pedantic # Les flags pour le compilateur
LDFLAGS=      # Les flags pour l'éditeur de liens (ici, aucun)
EXEC=crossref # Le nom de notre éxécutable
SRC= $(wildcard *.cpp) # Tous les fichiers .c
OBJ= $(SRC:.cpp=.o) # Tous les fichiers .c, sans .c mais avec .o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
  
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
    
clean:
	rm *.o
      
mrproper: clean
	rm $(EXEC)
