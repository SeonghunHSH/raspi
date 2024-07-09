CC = gcc
CFLAG = -Wall
TARGET = us2
OBJS = us11.o us22.o us33.o
LIBS = wiringPi

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -l$(LIBS)


us11.o : uSonic2.c
	gcc -c -o us11.o uSonic2.c
	
us22.o : us2.c
	gcc -c -o us22.o us2.c
	
us33.o : Trig2.c
	gcc -c -o us33.o Trig2.c

d : 
	rm -f *.o
	
song2 : song2.c
	gcc -o song2 song2.c -l$(LIBS)
	
