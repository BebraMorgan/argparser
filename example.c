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
    add_float_arg(arg_container, 'i', "float2", "0.2", "description 8");

    if(argument_parse(arg_container, argc, argv) == 1) {
        printf("int: %d\n", get_int_arg("int", arg_container));
        printf("int 2: %d\n", get_int_arg("int2", arg_container));
        printf("bool: %d\n", get_bool_arg("bool", arg_container));
        printf("bool 2: %d\n", get_bool_arg("bool2", arg_container));
        printf("string: %s\n", get_string_arg("string", arg_container));
        printf("string 2: %s\n", get_string_arg("string2", arg_container));
        printf("float: %f\n", get_float_arg("float", arg_container));
        printf("float 2: %f\n", get_float_arg("float2", arg_container));
        args_container_free(arg_container);
    }
    return 0;
}
