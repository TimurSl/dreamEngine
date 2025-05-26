# Minimal Sphinx documentation Makefile

SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
SOURCEDIR     = .
BUILDDIR      = _build

.PHONY: help clean html

help:
	@echo "Makefile for Sphinx documentation"
	@echo "  make html     # build HTML docs"
	@echo "  make clean    # remove build output"

html:
	$(SPHINXBUILD) -b html "$(SOURCEDIR)" "$(BUILDDIR)/html" $(SPHINXOPTS)
	@echo "Build finished. HTML docs are in $(BUILDDIR)/html"

clean:
	rm -rf "$(BUILDDIR)"
