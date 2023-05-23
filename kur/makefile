TARGET1 = hmain
TARGET2 = imain
# Исходные файлы
SRCS1 = heapsort.c hmain.c
SRCS2 = insertionsort.c imain.c
# Объектные файлы
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -fPIC

# Имя динамической библиотеки
LIBRARY1 = libheapsort.so
LIBRARY2 = libinsertionsort.so
# Правило по умолчанию
all: $(TARGET1) $(TARGET2) 

# Правило сборки heap библиотеки
$(TARGET1): $(OBJS1)
	$(CC) -o $@ $^ -L. -lheapsort

# Правило сборки insertion библиотеки
$(TARGET2): $(OBJS2)
	$(CC) -o $@ $^ -L. -linsertionsort

# Правило компиляции исходных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило сборки динамической библиотеки heap
$(LIBRARY1): heapsort.o
	$(CC) -shared -o $@ $^

# Правило сборки динамической библиотеки insertion
$(LIBRARY2): insertionsort.o
	$(CC) -shared -o $@ $^

# Правило связывания программы с библиотекой
$(TARGET1): $(LIBRARY1)

# Правило связывания программы с библиотекой
$(TARGET2): $(LIBRARY2)

# Правило очистки файлов
clean:
	rm -f $(OBJS1) $(TARGET1) $(LIBRARY1) $(OBJS2) $(TARGET2) $(LIBRARY2)

.PHONY: all clean