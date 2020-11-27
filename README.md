# Ojashell (Oyugo + James Shell):

A simple UNIX command line interpreter

## Description :

Ojashell is a simple UNIX command language interpreter that reads commands from either standard input and executes them.

### Invocation :

To invoke **Ojashell**, compile all `.c` files in the repository and run the resulting executable.

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
$ ./hsh
```

Ojashell can be invoked both interactively and non-interactively. If it is invoked with standard input not connected to a terminal, it reads and executes re
eceived commands in order.

Example:
```
$ echo "echo 'hello'" | ./hsh
'hello'
$
```

If it is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened\
. When executing interactively, Ojashell displays the prompt `Ojashell$ ` when it is ready to read a command.

Example:
```
$./hsh
Ojashell$ ls
Ojashell$ main.c AUTHORS
Ojashell$ exit
$
```

## Built in commands

Ojashell supports commands such as
* env
* exit
* echo

## Authors :black_nib:

* Oyugo Obonyo <[OyugoObonyo](https://github.com/OyugoObonyo)>
* Ewar James <[EwarJames](https://github.com/EwarJames)>
