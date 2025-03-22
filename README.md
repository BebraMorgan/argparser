# Argparser Library

Эта библиотека предоставляет простой способ разбора аргументов командной строки в C. Она поддерживает аргументы целого типа, с плавающей точкой, строковые и логические аргументы, позволяя вам легко определять и получать аргументы с короткими и длинными именами, значениями по умолчанию и описаниями.

## Возможности

- Определение аргументов целого типа, с плавающей точкой, строковых и логических аргументов с короткими и длинными именами.
- Установка значений по умолчанию для аргументов.
- Предоставление описаний для каждого аргумента для создания справочного сообщения.
- Разбор аргументов командной строки и получение их значений.
- Автоматическое создание справочного сообщения с помощью флагов `-h` или `--help`.

## Использование

### 1. Подключение заголовочного файла

Включите заголовочный файл `argparser.h` в ваш исходный код C.
```
  #include "argparser.h"
```
### 2. Создание контейнера аргументов

Создайте контейнер аргументов с помощью функции `create_args_container()`. Этот контейнер будет хранить все определенные аргументы.
```
arguments *args = create_args_container();
```

### 3. Добавление аргументов

Используйте функции `add_int_arg()`, `add_float_arg()`, `add_string_arg()` и `add_bool_arg()` для добавления аргументов в контейнер.
```
add_int_arg(args, 'i', "integer", "10", "Целочисленный аргумент");
add_float_arg(args, 'f', "float", "3.14", "Аргумент с плавающей точкой");
add_string_arg(args, 's', "string", "default", "Строковый аргумент");
add_bool_arg(args, 'b', "boolean", "0", "Логический аргумент (0 или 1)");
```

### 4. Разбор аргументов

Вызовите функцию `argument_parse()` для разбора аргументов командной строки. Эта функция принимает контейнер аргументов и `argc` и `argv` из функции `main()` и возвращает 1, если разбор завершился успешно. Используйте это для проверки и успешной работы дальнейшего кода.
```
int main(int argc, char *argv[]) {
arguments *args = create_args_container();

add_int_arg(args, 'i', "integer", "10", "Целочисленный аргумент");
add_float_arg(args, 'f', "float", "3.14", "Аргумент с плавающей точкой");
add_string_arg(args, 's', "string", "default", "Строковый аргумент");
add_bool_arg(args, 'b', "boolean", "0", "Логический аргумент (0 или 1)");

argument_parse(args, argc, argv);

// ... остальная часть вашего кода

}
```

### 5. Получение значений аргументов

Используйте функции `get_int_arg()`, `get_float_arg()`, `get_string_arg()` и `get_bool_arg()` для получения значений аргументов после разбора.
```
int int_value = get_int_arg("integer", args);
float float_value = get_float_arg("float", args);
char *string_value = get_string_arg("string", args);
int bool_value = get_bool_arg("boolean", args);
```

### 6. Освобождение контейнера аргументов

Освободите память, выделенную для контейнера аргументов, с помощью функции `args_container_free()`.
```
args_container_free(args);
```

### Пример
```
#include <stdio.h>
#include "argparser.h"


int main(int argc, char *argv[]) {
    arguments *arg_container = create_args_container();
    add_int_arg(arg_container, 'a', "int", "122", "description 1");
    add_int_arg(arg_container, 'b', "int2", "12", "description 2");
    add_bool_arg(arg_container, 'c', "bool", "1", "description 3");
    add_bool_arg(arg_container, 'd', "bool2", "0", "description 4");
    add_string_arg(arg_container, 'e', "string", "qwe", "description 5");
    add_string_arg(arg_container, 'f', "string2", "asqwe", "description 6");
    add_float_arg(arg_container, 'g', "float", "1.1", "description 7");
    add_float_arg(arg_container, 'h', "float2", "0.2", "description 8");

    if(argument_parse(arg_container, argc, argv) == 1) {
        printf("%d\n", get_int_arg("int", arg_container));
        printf("%d\n", get_int_arg("int2", arg_container));
        printf("%d\n", get_bool_arg("bool", arg_container));
        printf("%d\n", get_bool_arg("bool2", arg_container));
        printf("%s\n", get_string_arg("string", arg_container));
        printf("%s\n", get_string_arg("string2", arg_container));
        printf("%f\n", get_float_arg("float", arg_container));
        printf("%f\n", get_float_arg("float2", arg_container));
        args_container_free(arg_container);
    }
    return 0;
}
```

Скомпилируйте и запустите пример:
```
cmake .
make
./example --int 123 --int2 333 --bool 0 --bool2 1 --string asd --string2 qq --float 1.11 --float2 121
./example -a 123 -b 333 -c 0 -d 1 -e asd -f qq -g 1.11 -i 121
```

### Ожидаемый вывод
```
int: 123
int 2: 333
bool: 0
bool 2: 1
string: asd
string 2: qq
float: 1.110000
float 2: 121.000000
```

## Справочник по API

### `arguments *create_args_container()`

Создает пустой контейнер аргументов.

### `void args_container_free(arguments *arg_container)`

Освобождает память, выделенную для контейнера аргументов.

### `void add_int_arg(arguments *arg_container, char short_name, char *name, char *default_value, char *description)`

Добавляет целочисленный аргумент в контейнер.

- `arg_container`: Контейнер аргументов.
- `short_name`: Короткое имя аргумента (например, `i`).
- `name`: Длинное имя аргумента (например, `"integer"`).
- `default_value`: Значение аргумента по умолчанию (в виде строки).
- `description`: Описание аргумента.

### `void add_float_arg(arguments *arg_container, char short_name, char *name, char *default_value, char *description)`

Добавляет аргумент с плавающей точкой в контейнер.

- `arg_container`: Контейнер аргументов.
- `short_name`: Короткое имя аргумента (например, `f`).
- `name`: Длинное имя аргумента (например, `"float"`).
- `default_value`: Значение аргумента по умолчанию (в виде строки).
- `description`: Описание аргумента.

### `void add_string_arg(arguments *arg_container, char short_name, char *name, char *default_value, char *description)`

Добавляет строковый аргумент в контейнер.

- `arg_container`: Контейнер аргументов.
- `short_name`: Короткое имя аргумента (например, `s`).
- `name`: Длинное имя аргумента (например, `"string"`).
- `default_value`: Значение аргумента по умолчанию.
- `description`: Описание аргумента.

### `void add_bool_arg(arguments *arg_container, char short_name, char *name, char *default_value, char *description)`

Добавляет логический аргумент в контейнер.

- `arg_container`: Контейнер аргументов.
- `short_name`: Короткое имя аргумента (например, `b`).
- `name`: Длинное имя аргумента (например, `"boolean"`).
- `default_value`: Значение аргумента по умолчанию (в виде строки, `"0"` или `"1"`).
- `description`: Описание аргумента.

### `int get_int_arg(char* name, arguments * arg_container)`

Получает значение целочисленного аргумента.

- `name`: Длинное имя аргумента.
- `arg_container`: Контейнер аргументов.
- Возвращает: Значение аргумента.

### `float get_float_arg(char *name, arguments *arg_container)`

Получает значение аргумента с плавающей точкой.

- `name`: Длинное имя аргумента.
- `arg_container`: Контейнер аргументов.
- Возвращает: Значение аргумента.

### `char *get_string_arg(char *name, arguments *arg_container)`

Получает значение строкового аргумента.

- `name`: Длинное имя аргумента.
- `arg_container`: Контейнер аргументов.
- Возвращает: Значение аргумента. **Не забудьте освободить возвращенный указатель**.

### `int get_bool_arg(char *name, arguments *arg_container)`

Получает значение логического аргумента.

- `name`: Длинное имя аргумента.
- `arg_container`: Контейнер аргументов.
- Возвращает: Значение аргумента.

### `int argument_parse(arguments *arg_container, int argc, char *argv[])`

Разбирает аргументы командной строки.

- `arg_container`: Контейнер аргументов.
- `argc`: Количество аргументов командной строки.
- `argv`: Массив аргументов командной строки.
