#!/bin/bash

for number in {1..23}
do
  (( number < 10 )) && gcc \(ponteiro\)0"$number".c -o 0"$number" || gcc \(ponteiro\)"$number".c -o "$number"
done

exit 0
