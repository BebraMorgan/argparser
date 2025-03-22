#ifndef ARGPARSER_LIBRARY_H
#define ARGPARSER_LIBRARY_H


typedef struct int_arg {
    int value;
    char short_name;
    char *name;
    int default_value;
    char *description;

} int_arg;

typedef struct float_arg {
    float value;
    char short_name;
    char *name;
    float default_value;
    char *description;

} float_arg;

typedef struct string_arg {
    char *value;
    char short_name;
    char *name;
    char *default_value;
    char *description;

} string_arg;

typedef struct bool_arg {
    int value;
    char short_name;
    char *name;
    int default_value;
    char *description;
} bool_arg;

typedef struct args {
    int_arg **int_args;
    int int_count;
    float_arg **float_args;
    int float_count;
    string_arg **string_args;
    int string_count;
    bool_arg **bool_args;
    int bool_count;
} arguments;


arguments *create_args_container();

void args_container_free(arguments *arg_container);

void add_int_arg(arguments *arg_container, char short_name, char *name, char *default_value,
                 char *description);

void add_float_arg(arguments *arg_container, char short_name, char *name, char *default_value,
                   char *description);

void add_bool_arg(arguments *arg_container, char short_name, char *name, char *default_value,
                  char *description);

void add_string_arg(arguments *arg_container, char short_name, char *name, char *default_value,
                    char *description);

int get_int_arg(char* name, arguments * arg_container);

int get_bool_arg(char *name, arguments *arg_container);

float get_float_arg(char *name, arguments *arg_container);

char *get_string_arg(char *name, arguments *arg_container);

int argument_parse(arguments *arg_container, int argc, char *argv[]);


#endif //ARGPARSER_LIBRARY_H
