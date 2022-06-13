gcc test/main_c.c -L. -lftprintf -o test_c && ./test_c > test_c.txt
gcc test/main_s.c -L. -lftprintf -o test_s && ./test_s > test_s.txt
gcc test/main_u.c -L. -lftprintf -o test_u && ./test_u > test_u.txt
gcc test/main_d.c -L. -lftprintf -o test_d && ./test_d > test_d.txt
gcc test/main_i.c -L. -lftprintf -o test_i && ./test_i > test_i.txt
gcc test/main_x.c -L. -lftprintf -o test_x && ./test_x > test_x.txt
gcc test/main_bigx.c -L. -lftprintf -o test_bigx && ./test_bigx > test_bigx.txt
gcc test/main_p.c -L. -lftprintf -o test_p && ./test_p > test_p.txt
gcc test/main_without_flags.c -L. -lftprintf -o test_w && ./test_w > test_w.txt
cat test_c.txt test_s.txt test_u.txt test_d.txt test_i.txt test_x.txt test_bigx.txt test_p.txt test_w.txt > result.txt
