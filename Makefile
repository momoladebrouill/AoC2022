make:
	gcc main.c -o main

scanf:
	gcc main.c -o main -fsanitize=address
	./main < input

clean:
	rm main

sex:
	@echo "no you can't"

