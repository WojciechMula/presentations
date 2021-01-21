DEPS=*.cpp *.png pictures/*.tex

vector-instructions.pdf: vector-instructions.tex $(DEPS)
	pdflatex vector-instructions.tex

vector-instructions-plain.tex: vector-instructions.tex
	sed 's/\\pause//g' vector-instructions.tex > /tmp/vector-instructions-plain.tex
	mv /tmp/vector-instructions-plain.tex .

vector-instructions-plain.pdf: vector-instructions-plain.tex $(DEPS)
	pdflatex vector-instructions-plain.tex

images: cat_grayscale.png scripts/saturated_add.py
	scripts/saturated_add.py cat_grayscale.png 180
