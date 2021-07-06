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

cmd_original+=("< filein cat")
cmd_pipex+=("$pipex_pathname filein cat")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< fil@àà# cat | wc > fileout")
cmd_pipex+=("$pipex_pathname fil@àà# cat wc fileout")
filein+=("fil@àà#")
fileout+=("fileout")

cmd_original+=("< filein cat | wc > fileout")
cmd_pipex+=("$pipex_pathname filein cat wc fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< ls_info cat | grep '.sh' > fileout")
cmd_pipex+=("$pipex_pathname ls_info cat \"grep '.sh'\" fileout")
filein+=("filein")
fileout+=("fileout")

cmd_original+=("< filein cat | wc > fileout")
cmd_pipex+=("$pipex_pathname filein cat wc fileout")
filein+=("filein")
fileout+=("fileout")