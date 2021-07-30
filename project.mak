main: main.o Student.o
		g++ -o main.o Student.o
main.o: main.cpp
# g++ -c 参数表示 只编译不链接，只生成目标文件
		g++ -c main.cpp 
