# push_swap

Algorythmyc project about sorting a stacks. Yes stacks.
On init phase we have full first stack(stack A) and empty stack(stack). The aim is to sort numbers in stack A in ascending order in as few operation as it possible (5200 operation for 500 numbers).

The whole task is in [this pdf](https://github.com/franckevicz/push_swap/blob/master/push_swap.en.pdf). It's not described very clear as long as it's a part of the task.
Here is just a quick explanation.

To reach this goal in our arsenal we have some commands:
```
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.
rrr : rra and rrb at the same time.
```

**push_swap** binary must output the list of command with help of which stack can be sorted.

**checher** binary takes stack as argument and commands via stdin and checks is stack A is sorted after applying all those operation(and stack B is empty).

The best way to operate with this :

make

`ARG="10 2 3 14 5 6 7 8 1"; ./push_swap $ARG | ./checker $ARG`


There is some flags in ./checker program:
```
  -n - number of operations
  -v - temporary state of stack while sorting
  -c - color output
  ```
