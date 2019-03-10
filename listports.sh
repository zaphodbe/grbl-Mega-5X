#!/bin/sh
if [ -z $1 ]
then
	export key=ARDUINO_MEGA
else
	export key=$1
fi
grep $key grbl/cpu_map.h | awk '{print $3,"\t",$2;}' | sort -V
