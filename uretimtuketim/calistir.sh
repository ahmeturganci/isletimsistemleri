gcc uretici-producer.c -o uretici -lrt
gcc tuketici-consumer.c -o tuketici -lrt
./uretici
./tuketici