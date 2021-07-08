#! /bin/bash

declare -a cmd_original
declare -a cmd_pipex
declare -a filein
declare -a fileout

export cmd_original
export cmd_pipex
export filein
export fileout

cmd_original+=("")
cmd_pipex+=("$pipex_pathname")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("only_one_wrong_command")
cmd_pipex+=("$pipex_pathname only_one_wrong_command")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< filein cat")
cmd_pipex+=("$pipex_pathname filein cat")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< wrong_infile@àà# cat | wc > fileout")
cmd_pipex+=("$pipex_pathname wrong_infile@àà# cat wc fileout")
filein+=("wrong_infile@àà#")
fileout+=("fileout")

cmd_original+=("< filein cmd_invalid | wc > fileout")
cmd_pipex+=("$pipex_pathname filein cmd_invalid wc fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< file_not_exist cat | wc > fileout")
cmd_pipex+=("$pipex_pathname file_not_exist cat wc fileout")
filein+=("file_not_exist")
fileout+=("fileout")

cmd_original+=("< empty_file cat | cat > empty_file")
cmd_pipex+=("$pipex_pathname empty_file cat cat empty_file")
filein+=("empty_file")
fileout+=("empty_file")

cmd_original+=("< filein2 cat | cat > filein2")
cmd_pipex+=("$pipex_pathname filein2 cat cat filein2")
filein+=("filein2")
fileout+=("filein2")

cmd_original+=("< filein cat | wc > fileout")
cmd_pipex+=("$pipex_pathname filein cat wc fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< ls_info cat | grep .sh > fileout")
cmd_pipex+=("$pipex_pathname ls_info cat \"grep .sh\" fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< filein cat | wc > fileout")
cmd_pipex+=("$pipex_pathname filein cat wc fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< filein ls -l | wc -l > fileout")
cmd_pipex+=("$pipex_pathname filein \"ls -l\" \"wc -l\" fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< filein ls -l | cat -e > fileout")
cmd_pipex+=("$pipex_pathname filein \"ls -l\" \"cat -e\" fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< infile_grep grep a1 | wc -w > fileout")
cmd_pipex+=("$pipex_pathname infile_grep \"grep a1\" \"wc -w\" fileout")
filein+=("infile_grep")
fileout+=("fileout")

cmd_original+=("< ls_info cat | grep .sh | wc -l > fileout")
cmd_pipex+=("$pipex_pathname ls_info cat \"grep .sh\" \"wc -l\" fileout")
filein+=("ls_info")
fileout+=("fileout")