set pagination off
set confirm off
set print pretty on

tui enable
layout src

#
# Breakpoints
#

break ft_printf
set $bp_printf = $bpnum

break loop_format
set $bp_loop = $bpnum

break parser_type
set $bp_parser = $bpnum

break print_char
set $bp_char = $bpnum

break print_str
set $bp_str = $bpnum

break print_ptr
set $bp_ptr = $bpnum

break print_hex
set $bp_hex = $bpnum

break print_int
set $bp_int = $bpnum

#
# Grupos de breakpoints
#

define bp_main
    enable $bp_printf
    enable $bp_loop
    disable $bp_parser
    disable $bp_char
    disable $bp_str
    disable $bp_ptr
    disable $bp_hex
    disable $bp_int
end
document bp_main
Activa únicamente ft_printf y loop_format.
end

define bp_parser
    enable $bp_printf
    enable $bp_loop
    enable $bp_parser
    disable $bp_char
    disable $bp_str
    disable $bp_ptr
    disable $bp_hex
    disable $bp_int
end
document bp_parser
Activa hasta parser_type.
end

define bp_print
    disable $bp_printf
    disable $bp_loop
    disable $bp_parser
    enable $bp_char
    enable $bp_str
    enable $bp_ptr
    enable $bp_hex
    enable $bp_int
end
document bp_print
Activa únicamente las funciones de impresión.
end

define bp_all
    enable $bp_printf
    enable $bp_loop
    enable $bp_parser
    enable $bp_char
    enable $bp_str
    enable $bp_ptr
    enable $bp_hex
    enable $bp_int
end
document bp_all
Activa todos los breakpoints.
end

define bp_none
    disable $bp_printf
    disable $bp_loop
    disable $bp_parser
    disable $bp_char
    disable $bp_str
    disable $bp_ptr
    disable $bp_hex
    disable $bp_int
end
document bp_none
Desactiva todos los breakpoints.
end

#
# Estado inicial
#

bp_main

#
# Mostrar automáticamente información cada vez que GDB se detiene
#

define hook-stop
    printf "\n=====================================================\n"
    frame
    printf "-----------------------------------------------------\n"
    info args
    printf "-----------------------------------------------------\n"
    info locals
    printf "-----------------------------------------------------\n"
    list
    printf "=====================================================\n\n"
end

#
# Ejecutar el programa
#

set args con_newline_test.txt
run