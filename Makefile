make:
	gcc main.c -o main

scanf:
	gcc main.c -o main -fsanitize=undefined
	./main < input

clean:
	rm main

sex:
	@echo "no you can't"
