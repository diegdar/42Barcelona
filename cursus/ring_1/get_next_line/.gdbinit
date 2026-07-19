set pagination off
set confirm off
set print pretty on

tui enable
layout src

#
# Breakpoints
#

break get_next_line
break fill_storage
break read_buffer
break extract_line
break cut_excess
break ft_strjoin

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
