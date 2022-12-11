make:
	gcc main.c -o main -fsanitize=address
	./main 

py:
	python3 main.py

scanf:
	gcc main.c -o main -fsanitize=address
	./main < input

clean:
	rm main

AJD = $(shell date +"J%d")

hello:
	@cp template $(AJD) -r 
	@cd $(AJD);
	@firefox adventofcode.com
	@echo "Hello bgx"

sex:
	@echo "no you can't"

