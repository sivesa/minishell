# 42 minishell project
I was tasked to write Unix command interpreter a program called minishell with minimal commands and features.

## About
This UNIX command interpreter must display a prompt (a simple prompt for example $>) and wait till you type a command line, validated by pressing enter.The prompt is shown again only once the command has been completely executed.
The command lines are simple, no pipes, no redirections or any other advanced functions. The executable are those you can find in the paths indicated in the PATH variable. In cases where the executable cannot be found, it has to show an error message and display the prompt again. You must manage the errors without using errno, by displaying a message adapted to the error output.
You must deal correctly with the PATH and the environment (copy of system char **environ). You must implement a series of builtins: 

* exit
* echo
* cd
* setenv
* unsetenv

## License
[MIT](https://choosealicense.com/licenses/mit/)
