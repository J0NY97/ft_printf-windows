#!/usr/bin/bash
gcc test_main.c -I . -L . -l libprintf -I ../libft -L ../libft -l libft
