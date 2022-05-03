CROSS=						#cross compiler name
CC=$(CROSS)gcc
EXE=test				#실행파일이름은 변경
#DEFINES= -DDEBUG					#DEBUG를 define하는 예시
#CFLAGS= -I./include $(DEFINES)		#./include를 포함시켜서 컴파일하는 예시
#LDFLAGS= -lpthread				#pthread 라이브러리를 추가하여 컴파일하는 예시

C_SRC= $(wildcard *.c)
OBJS= $(C_SRC:.c=.o)				#wildcard명령어로 확장자를 .c에서 .o로 바꾸는 작업

all : $(EXE)
	echo compile completed!

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)	#여기서 $@==$(EXE), $^==$(OBJS)를 의미

clean :
	rm *.o
	rm *~*
	rm $(EXE)
