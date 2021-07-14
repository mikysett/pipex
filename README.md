# Pipex - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

Pipe differents commands and mimic bash piping system

`> ./pipex file1 cmd1 cmd2 file2` is equivalent to bash command `< file1 cmd1 | cmd2 > file2`.

Compile the program with `make bonus` to use also two bonus functionalities:

- Handle multiple pipes: `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
- Support « and » when the first parameter is "here_doc": `./pipex here_doc LIMITER cmd cmd1 file` is equivalent to `cmd << LIMITER | cmd1 >> file`.

## Pipex tester
 - In `pipex_tester` you'll find a bash script that will execute valid and invalid commands on both pipex and the bash and compare program and file output.
 - To run the tester your binary should be located in `../pipex/pipex`, to change the path just modify pipex_pathname in `pipex_tester.sh`.
 - You can add/remove or modify tests easily in `init_tests.sh`.

 ### Disclaimer
 The tester is not by any mean a complete check, it helps but must be used with caution. It doesn't check memory leaks and it doesn't account for every possible scenario.
 I encourage you to add more tests and test files and give feedback about possible new tests implementation.

