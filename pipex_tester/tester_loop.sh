#! /bin/bash

nb_tests=${#cmd_original[@]}

for (( i=0; i < $nb_tests; i++ )); do
	expected_out=$(eval ${cmd_original[$i]} 2>&1)
	test -e ${fileout[$i]} && expected_fileout=$(< ${fileout[$i]} cat) || expected_fileout=""
	rm -f ${fileout[$i]}

	pipex_out=$(eval ${cmd_pipex[$i]} 2>&1)
	test -e ${fileout[$i]} && pipex_fileout=$(< ${fileout[$i]} cat) || pipex_fileout=""
	rm -f ${fileout[$i]}
	
	TEST_CLR="$GRN"
	OK_OUT=1
	OK_FILEOUT=1
	
	if [ "$expected_out" != "$pipex_out" ]; then
		TEST_CLR="$YEL"
		OK_OUT=0
	fi;
	if [ "$expected_fileout" != "$pipex_fileout" ]; then
		TEST_CLR="$RED"
		OK_FILEOUT=0
	fi;
	
	echo -e "\n-----------------------------------------"
	echo -e "$TEST_CLR Test$i:$WHT ${cmd_original[$i]}"
	if [ $OK_OUT == 0 ]; then
		echo -e "$YEL Differences in program output:$WHT"
		echo -e "$BLU bash output :$WHT"
		echo "$expected_out"
		echo -e "$BLU pipex output:$WHT"
		echo "$pipex_out"
	fi;
	if [ $OK_FILEOUT == 0 ]; then
		echo -e "$YEL Differences in final file:$WHT"
		echo -e "${BLU}bash file :${WHT}"
		echo "$expected_fileout"
		echo -e "${BLU}pipex file:${WHT}"
		echo "$pipex_fileout"
	fi;
done
