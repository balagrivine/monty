push 1
push 2
push 3
pall
label loop_start
swap
pall
push 1
sub
push 1
if-goto loop_start

