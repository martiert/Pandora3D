LTX := ltx
PDFTEX := ltx2pdf
TEX := CodingStyle.tex

all: $(TEX)
	$(LTX) $(TEX)

pdf: $(TEX)
	$(PDFTEX) $(TEX)

clean:
	rm -f *.dvi *.aux *.log
