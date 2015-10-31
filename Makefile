CC = gcc

CFLAGS = -g -O3 -W -Wall -lm

FUENTES = calc.c my_lib.c

FPOT = po/calc.pot

POES = po/es.po

POEN = po/en.po

CPOT1 = xgettext --package-name

CPOT2 = --package-version 0.1 --default-domain

CPOT3 = --from-code=utf-8 --copyright-holder="YolandaAlvarez" --msgid-bugs-address="megan_potter2007@hotmail.com" -s -k_ -L C

FMOES = idioma/es/LC_MESSAGES/calc.mo

FMOEN = idioma/en/LC_MESSAGES/calc.mo

all: compilar

compilar: ${FUENTES} 
	$(CC) $(CFLAGS) ${FUENTES} -o calc

traducir: pot po 

ejecutable: mo

pot: ${FUENTES}
	${CPOT1} calc ${CPOT2} calc --output ${FPOT} ${CPOT3} ${FUENTES}

po: ${FPOT}
	msginit -l es -o ${POES} -i ${FPOT}
	msginit -l en -o ${POEN} -i ${FPOT}

mo: 
	msgfmt -c -v -o ${FMOES} ${POES}
	msgfmt -c -v -o ${FMOEN} ${POEN}

clean: calc
	rm *o calc
