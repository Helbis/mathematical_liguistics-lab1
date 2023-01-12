CXX = clang++
FLAGS = -std=c++20 -Wall -pedantic


output: main.cpp
	${CXX} ${FLAGS} $< -o $@

run:
	./output

clean:
	rm ./output
	rm *.aux *.log

docs:
	pdflatex report.tex
	open report.pdf
