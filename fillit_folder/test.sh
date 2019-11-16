#!/bin/bash
echo ----1T Test---
./a.out ../tetris_blocks/valid_1t_c.txt
echo ----1T Comparison Test---
./fillit ../tetris_blocks/valid_1t_c.txt
echo ----2T Test---
./a.out ../tetris_blocks/valid_2t_a.txt
echo ----2T Comparison Test---
./fillit ../tetris_blocks/valid_2t_a.txt
echo ----3T Comparison Test---
./fillit ../tetris_blocks/valid_3t_c.txt
echo ----3T Test---
./a.out ../tetris_blocks/valid_3t_c.txt
echo ----4T Subject Example Test---
./a.out ../tetris_blocks/valid_4t_subject_example.txt
echo ----4T Subject Comparison Test---
./fillit ../tetris_blocks/valid_4t_subject_example.txt
echo ----6T Test----
./a.out ../tetris_blocks/valid_6t.txt
echo ----6T Comparison Test----
./fillit ../tetris_blocks/valid_6t.txt
echo ----HARD 7T Test----
./a.out ../tetris_blocks/valid_hard_7t.txt
echo ----HARD 7T Comparison----
./fillit ../tetris_blocks/valid_hard_7t.txt
echo ----8T Subject Example Test----
./a.out ../tetris_blocks/valid_8t.txt
echo ----8T Subject Comparison----
./fillit ../tetris_blocks/valid_8t.txt
echo ----8T Hard Test----
./a.out ../tetris_blocks/valid_hard_8t.txt
echo ----8T Hard Comparison Test----
./fillit ../tetris_blocks/valid_hard_8t.txt
echo ----10T Test----
./a.out ../tetris_blocks/valid_10.txt
echo ----10T Comparison Test----
./fillit ../tetris_blocks/valid_10.txt