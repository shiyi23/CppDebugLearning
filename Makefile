EXECUTABLE:= chapter03
LIBDIR:=
LIBS:=
INCLUDES:=.
SRCDIR:=

CC:=g++
CFLAGS:= -g -Wall 
CPPFLAGS:= $(CFLAGS)
CPPFLAGS+= $(addprefix -I, $(INCLUDES) )
CPPFLAGS+= -I.
CPPFLAGS+= -MMD

RM-F:= rm -f

SRCS:= $(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR) ))
OBJS:= $(patsubst %.cpp, %.o, $(SRCS) )
DEPS:= $(patsubst %.o, %.d, $(OBJS) )
MISSING_DEPS:= $(filter-out $(wildcard $(DEPS)), $(DEPS) )
MISSING_DEPS_SOURCES:= $(wildcard $(patsubst %.d, %.cpp, $(MISSING_DEPS) ) )

.PHONY: all deps clean
all:$(EXECUTABLE)
deps:$(DEPS)

objs:$(OBJS)
clean:
		@$(RM-F) *.o
		@$(RM-F) *.d

ifneq ($(MISSING_DEPS), )
$(MISSING_DEPS):
		@$(RM-F) $(patsubst %.d, %.o, $@)
endif
-include $(DEPS)
$(EXECUTABLE) : $(OBJS)
		$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -L, $(LIBDIR) ) $(addprefix -1,$(LIBS) )



# main: main.o Student.o
# 		g++ -o another_cha03 main.o Student.o
# main.o: main.cpp
# # g++ -c 参数表示 只编译不链接，只生成目标文件
# 		g++ -c main.cpp
# Student.o: Student.cpp Student.h
# 		g++ -c Student.cpp
