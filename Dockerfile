# Автор: Конов Владимир, группа 241-326
FROM ubuntu:18.04

# Установка компилятора
RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# Создание рабочей директории
WORKDIR /app

# Копирование всех файлов
COPY . .

# Компиляция программы
RUN g++ -o cache_app main.cpp MemoryCache.cpp -std=c++11

# Запуск приложения
CMD ["./cache_app"]