#include "argparser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE                                                                   \
  printf("+---------+-------+------------------+---------------+-------------" \
         "-----"                                                               \
         "---------------+\n")
arguments *create_args_container() {
  arguments *container = NULL;
  if ((container = (arguments *)malloc(sizeof(arguments))) != NULL) {
    container->int_count = 0;
    container->float_count = 0;
    container->string_count = 0;
    container->bool_count = 0;
    container->int_args = NULL;
    container->bool_args = NULL;
    container->string_args = NULL;
    container->float_args = NULL;
  } else
    perror("Error with arg container memory\n");
  return container;
}

void int_args_free(arguments *arg_container) {
  int i;
  if (arg_container->int_args) {
    for (i = 0; i < arg_container->int_count; i++) {
      if (arg_container->int_args[i]->name) {
        free(arg_container->int_args[i]->name);
        arg_container->int_args[i]->name = NULL;
      }
      if (arg_container->int_args[i]->description) {
        free(arg_container->int_args[i]->description);
        arg_container->int_args[i]->description = NULL;
      }
      free(arg_container->int_args[i]);
      arg_container->int_args[i] = NULL;
    }
    free(arg_container->int_args);
    arg_container->int_args = NULL;
  }
}

void float_args_free(arguments *arg_container) {
  int i;
  if (arg_container->float_args) {
    for (i = 0; i < arg_container->float_count; i++) {
      if (arg_container->float_args[i]->name) {
        free(arg_container->float_args[i]->name);
        arg_container->float_args[i]->name = NULL;
      }
      if (arg_container->float_args[i]->description) {
        free(arg_container->float_args[i]->description);
        arg_container->float_args[i]->description = NULL;
      }
      free(arg_container->float_args[i]);
      arg_container->float_args[i] = NULL;
    }
    free(arg_container->float_args);
    arg_container->float_args = NULL;
  }
}

void bool_args_free(arguments *arg_container) {
  int i;
  if (arg_container->bool_args) {
    for (i = 0; i < arg_container->bool_count; i++) {
      if (arg_container->bool_args[i]->name) {
        free(arg_container->bool_args[i]->name);
        arg_container->bool_args[i]->name = NULL;
      }
      if (arg_container->bool_args[i]->description) {
        free(arg_container->bool_args[i]->description);
        arg_container->bool_args[i]->description = NULL;
      }
      free(arg_container->bool_args[i]);
      arg_container->bool_args[i] = NULL;
    }
    free(arg_container->bool_args);
    arg_container->bool_args = NULL;
  }
}

void string_args_free(arguments *arg_container) {
  int i;
  if (arg_container->string_args) {
    for (i = 0; i < arg_container->string_count; i++) {
      if (arg_container->string_args[i]->name) {
        free(arg_container->string_args[i]->name);
        arg_container->string_args[i]->name = NULL;
      }
      if (arg_container->string_args[i]->description) {
        free(arg_container->string_args[i]->description);
        arg_container->string_args[i]->description = NULL;
      }
      if (arg_container->string_args[i]->value) {
        free(arg_container->string_args[i]->value);
        arg_container->string_args[i]->value = NULL;
      }
      if (arg_container->string_args[i]->default_value) {
        free(arg_container->string_args[i]->default_value);
        arg_container->string_args[i]->default_value = NULL;
      }
      free(arg_container->string_args[i]);
      arg_container->string_args[i] = NULL;
    }
    free(arg_container->string_args);
    arg_container->string_args = NULL;
  }
}

void args_container_free(arguments *arg_container) {
  if (arg_container) {
    int_args_free(arg_container);
    float_args_free(arg_container);
    bool_args_free(arg_container);
    string_args_free(arg_container);
    free(arg_container);
    arg_container = NULL;
  }
}

void add_int_arg(arguments *arg_container, char short_name, char *name,
                 char *default_value, char *description) {
  if ((arg_container->int_args = (int_arg **)realloc(
           arg_container->int_args,
           sizeof(int_arg *) * (arg_container->int_count + 1))) != NULL) {
    arg_container->int_count++;
    if ((arg_container->int_args[arg_container->int_count - 1] =
             (int_arg *)malloc(sizeof(int_arg))) != NULL) {
      if ((arg_container->int_args[arg_container->int_count - 1]->name =
               (char *)malloc(sizeof(char) * strlen(name) + 1)) != NULL) {
        if ((arg_container->int_args[arg_container->int_count - 1]
                 ->description = (char *)malloc(
                 sizeof(char) * strlen(description) + 1)) != NULL) {
          arg_container->int_args[arg_container->int_count - 1]->short_name =
              short_name;
          strcpy(arg_container->int_args[arg_container->int_count - 1]->name,
                 name);
          arg_container->int_args[arg_container->int_count - 1]->default_value =
              atoi(default_value);

          strcpy(arg_container->int_args[arg_container->int_count - 1]
                     ->description,
                 description);
        }
      }
    }
  } else
    perror("error with reallocating memory!");
}

void add_float_arg(arguments *arg_container, char short_name, char *name,
                   char *default_value, char *description) {
  if ((arg_container->float_args = (float_arg **)realloc(
           arg_container->float_args,
           sizeof(float_arg *) * (arg_container->float_count + 1))) != NULL) {
    arg_container->float_count++;
    if ((arg_container->float_args[arg_container->float_count - 1] =
             (float_arg *)malloc(sizeof(float_arg))) != NULL) {
      if ((arg_container->float_args[arg_container->float_count - 1]->name =
               (char *)malloc(sizeof(char) * strlen(name) + 1)) != NULL) {
        if ((arg_container->float_args[arg_container->float_count - 1]
                 ->description = (char *)malloc(
                 sizeof(char) * strlen(description) + 1)) != NULL) {
          arg_container->float_args[arg_container->float_count - 1]
              ->short_name = short_name;
          strcpy(
              arg_container->float_args[arg_container->float_count - 1]->name,
              name);
          arg_container->float_args[arg_container->float_count - 1]
              ->default_value = atof(default_value);
          strcpy(arg_container->float_args[arg_container->float_count - 1]
                     ->description,
                 description);
        }
      }
    }
  } else
    perror("error with reallocating memory!");
}

void add_bool_arg(arguments *arg_container, char short_name, char *name,
                  char *default_value, char *description) {
  if ((arg_container->bool_args = (bool_arg **)realloc(
           arg_container->bool_args,
           sizeof(bool_arg *) * (arg_container->bool_count + 1))) != NULL) {
    arg_container->bool_count++;
    if ((arg_container->bool_args[arg_container->bool_count - 1] =
             (bool_arg *)malloc(sizeof(bool_arg))) != NULL) {

      if ((arg_container->bool_args[arg_container->bool_count - 1]->name =
               (char *)malloc(sizeof(char) * strlen(name) + 1)) != NULL) {

        if ((arg_container->bool_args[arg_container->bool_count - 1]
                 ->description = (char *)malloc(
                 sizeof(char) * strlen(description) + 1)) != NULL) {

          arg_container->bool_args[arg_container->bool_count - 1]->short_name =
              short_name;
          strcpy(arg_container->bool_args[arg_container->bool_count - 1]->name,
                 name);
          arg_container->bool_args[arg_container->bool_count - 1]
              ->default_value = atoi(default_value);
          strcpy(arg_container->bool_args[arg_container->bool_count - 1]
                     ->description,
                 description);
        }
      }
    }
  } else
    perror("error with reallocating memory!");
}

void add_string_arg(arguments *arg_container, char short_name, char *name,
                    char *default_value, char *description) {
  if ((arg_container->string_args = (string_arg **)realloc(
           arg_container->string_args,
           sizeof(string_arg *) * (arg_container->string_count + 1))) != NULL) {
    arg_container->string_count++;
    if ((arg_container->string_args[arg_container->string_count - 1] =
             (string_arg *)malloc(sizeof(string_arg))) != NULL) {
      if ((arg_container->string_args[arg_container->string_count - 1]->name =
               (char *)malloc(sizeof(char) * strlen(name) + 1)) != NULL) {

        if ((arg_container->string_args[arg_container->string_count - 1]
                 ->description = (char *)malloc(
                 sizeof(char) * strlen(description) + 1)) != NULL) {
          if ((arg_container->string_args[arg_container->string_count - 1]
                   ->default_value = (char *)malloc(
                   sizeof(char) * strlen(default_value))) != NULL) {

            arg_container->string_args[arg_container->string_count - 1]
                ->short_name = short_name;

            strcpy(arg_container->string_args[arg_container->string_count - 1]
                       ->name,
                   name);

            strcpy(arg_container->string_args[arg_container->string_count - 1]
                       ->default_value,
                   default_value);

            strcpy(arg_container->string_args[arg_container->string_count - 1]
                       ->description,
                   description);
          }
        }
      }
    }

  } else
    puts("error with reallocating memory!");
}

int get_int_arg(char *name, arguments *arg_container) {
  int i;
  int res;
  int flag;
  flag = 0;
  for (i = 0; i < arg_container->int_count && flag == 0; i++) {
    if (strcmp(arg_container->int_args[i]->name, name) == 0) {
      res = arg_container->int_args[i]->value;
      flag = 1;
    }
  }
  if (flag == 0) {
    perror("Argument searching error. Could not found argument of type \"int\" "
           "with such name");
    exit(-1);
  }
  return res;
}

int get_bool_arg(char *name, arguments *arg_container) {
  int i;
  int res;
  int flag;
  flag = 0;
  for (i = 0; i < arg_container->bool_count && flag == 0; i++) {
    if (strcmp(arg_container->bool_args[i]->name, name) == 0) {
      res = arg_container->bool_args[i]->value;
      flag = 1;
    }
  }
  if (flag == 0) {
    perror(
        "Argument searching error. Could not found argument of type \"bool\" "
        "with such name");
    exit(-1);
  }
  return res;
}

float get_float_arg(char *name, arguments *arg_container) {
  int i;
  float res;
  int flag;
  flag = 0;
  for (i = 0; i < arg_container->float_count && flag == 0; i++) {
    if (strcmp(arg_container->float_args[i]->name, name) == 0) {
      res = arg_container->float_args[i]->value;
      flag = 1;
    }
  }
  if (flag == 0) {
    perror(
        "Argument searching error. Could not found argument of type \"float\" "
        "with such name");
    exit(-1);
  }
  return res;
}

char *get_string_arg(char *name, arguments *arg_container) {
  int i;
  char *res;
  int flag;
  flag = 0;
  for (i = 0; i < arg_container->string_count && flag == 0; i++) {
    if (strcmp(arg_container->string_args[i]->name, name) == 0) {
      if ((res = (char *)malloc(
               sizeof(char) * strlen(arg_container->string_args[i]->value))) !=
          NULL) {
        strcpy(res, arg_container->string_args[i]->value);
        flag = 1;
      }
    }
  }
  if (flag == 0) {
    perror("Argument searching error. Could not found argument of type "
           "\"string\" with such name");
    exit(-1);
  }
  return res;
}

int argument_parse(arguments *arg_container, int argc, char *argv[]) {
  int i, k;
  int bool_val;
  int code;
  if (argc != 1) {
    for (i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        printf("%s help:\n", argv[0]);
        LINE;
        printf("| Option  | Short | Long Option      | Default Value | "
               "Description                     |\n");
        LINE;

        for (k = 0; k < arg_container->int_count; k++) {
          printf("| %-7s | %-5c | %-16s | %-13d | %-31s |\n", "int",
                 arg_container->int_args[k]->short_name,
                 arg_container->int_args[k]->name,
                 arg_container->int_args[k]->default_value,
                 arg_container->int_args[k]->description);
        }

        for (k = 0; k < arg_container->float_count; k++) {
          printf("| %-7s | %-5c | %-16s | %-13f | %-31s |\n", "float",
                 arg_container->float_args[k]->short_name,
                 arg_container->float_args[k]->name,
                 arg_container->float_args[k]->default_value,
                 arg_container->float_args[k]->description);
        }

        for (k = 0; k < arg_container->bool_count; k++) {
          printf("| %-7s | %-5c | %-16s | %-13d | %-31s |\n", "bool",
                 arg_container->bool_args[k]->short_name,
                 arg_container->bool_args[k]->name,
                 arg_container->bool_args[k]->default_value,
                 arg_container->bool_args[k]->description);
        }

        for (k = 0; k < arg_container->string_count; k++) {
          printf("| %-7s | %-5c | %-16s | %-13s | %-31s |\n", "string",
                 arg_container->string_args[k]->short_name,
                 arg_container->string_args[k]->name,
                 arg_container->string_args[k]->default_value,
                 arg_container->string_args[k]->description);
        }
        LINE;
        exit(0);
      } else if (argv[i][0] == '-') {
        if (argv[i + 1] != NULL) {
          for (k = 0; k < arg_container->int_count; k++) {
            if (arg_container->int_args[k]->short_name == argv[i][1]) {
              arg_container->int_args[k]->value = atoi(argv[i + 1]);
            } else {
              arg_container->int_args[k]->value =
                  arg_container->int_args[k]->default_value;
            }
          }
          for (k = 0; k < arg_container->float_count; k++) {
            if (arg_container->float_args[k]->short_name == argv[i][1]) {
              arg_container->float_args[k]->value = atof(argv[i + 1]);
            } else {
              arg_container->float_args[k]->value =
                  arg_container->float_args[k]->default_value;
            }
          }
          for (k = 0; k < arg_container->bool_count; k++) {
            if (arg_container->bool_args[k]->short_name == argv[i][1]) {
              bool_val = atoi(argv[i + 1]);
              if (bool_val == 1 || bool_val == 0)
                arg_container->bool_args[k]->value = bool_val;
              else {
                puts("Bool values might be \"1\" or \"0\".");
                code = 0;
              }
            } else {
              arg_container->bool_args[k]->value =
                  arg_container->bool_args[k]->default_value;
            }
          }
          for (k = 0; k < arg_container->string_count; k++) {
            if (arg_container->string_args[k]->short_name == argv[i][1]) {
              if ((arg_container->string_args[k]->value = (char *)malloc(
                       sizeof(char) * strlen(argv[i]))) != NULL) {
                strcpy(arg_container->string_args[k]->value, argv[i]);
              }
            } else {
              if ((arg_container->string_args[k]->value = (char *)malloc(
                       sizeof(char) *
                       strlen(arg_container->string_args[k]->default_value))) !=
                  NULL) {
                strcpy(arg_container->string_args[k]->value,
                       arg_container->string_args[k]->default_value);
              }
            }
          }
          code = 1;
        } else {
          puts("-h to help");
          code = 0;
        }
      }
    }
  } else {
    puts("-h to help");
    code = 0;
  }
  return code;
}
