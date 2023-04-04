#!/bin/sh

current_dir=$1

srcs=$(find "$current_dir" -type f -name '*.cpp' | sed "s|^$current_dir/||" | awk '{printf(" %s \\\\\n\t", $0)}')
perl -0777 -i -pe "BEGIN {undef $/; \$srcs = qq(${srcs})} s/(SRCS =).*?(?=OBJS =)/\$1\$srcs\\n/smg" "$current_dir/Makefile"
