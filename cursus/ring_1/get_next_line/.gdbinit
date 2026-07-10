set pagination off
set print pretty on

tui enable
layout src

break get_next_line
commands
    silent
    display fd
    display storage
    display buffer
end

break fill_storage
commands
    silent
    display fd
    display buffer
    display storage 
end

break read_buffer
commands
    silent
    display nr_bytes
    display size
    display storage
end
set args con_newline_test.txt
run
