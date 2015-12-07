LIBPATH=.

all: app1 app2

app1: libdp.so app1.c
	gcc -c app1.c
	gcc -Wall -Wl,-rpath=${LIBPATH} -L${LIBPATH} -o app1 app1.o -lpthread -ldp

libdp.so: dp.c
	gcc -Wall -fpic -c dp.c
	gcc -Wall -shared -o libdp.so dp.o
	
app2: libhash.so app2.c
	gcc -c app2.c
	gcc -Wall -Wl,-rpath=${LIBPATH} -L${LIBPATH} -o app2 app2.o -lpthread -lhash

libhash.so: hash.c
	gcc -Wall -fpic -c hash.c
	gcc -Wall -shared -o libhash.so hash.o

clean: 
	rm -fr app1 app2 *.o *.so 
