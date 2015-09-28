#############################################################################
# You need to perform three steps to add a test case:
#   1.) edit the file `testsuite.at' and add your test case
#   2.) add the files you need for the test to the `testfile' directory
#   3.) add these files (without path) to the `TESTFILES' list
# Do not forget to add your test files to the repository!
#############################################################################

# the files needed by the test cases (without `testfiles/' directory)
TESTFILES = error_parser_lola_01.lola error_parser_lola_02.lola \
	    error_parser_lola_03.lola \
	    error_parser_woflan_01.tpn error_parser_woflan_02.tpn \
	    error_parser_woflan_03.tpn error_parser_woflan_04.tpn \
	    error_parser_woflan_05.tpn error_parser_woflan_06.tpn \
            woflan1.xml.tpn woflan2.xml.tpn woflan3.xml.tpn \
	    woflan4.xml.tpn woflan5.xml.tpn woflan6.xml.tpn \
            test_myCoffee-sm.owfn test_myCoffee-syn.owfn testnet.pnml \
            fiona_coffee.owfn zeus.owfn test_input.pnml cyclicFullCoffee.pnml \
            cyclicFullCoffee.owfn phils.pnml phils.lola \
            prom-2_7.pnml prom-Heuristics.pnml \
            prom-OverlyPreciseModel_artificialStartEndTasks.pnml \
            prom-peller.pnml prom-ADtranslationAccordingToSpec.pnml \
            prom-M1_nonFitting.pnml prom-PetriNet.pnml \
            prom-pellerMaarDanMetReset.pnml prom-Alpha.pnml \
            prom-M2_underfitting.pnml prom-petrify_learn01_5cv.pnml \
            prom-PetriNet_split_onderzoek_behandeling.pnml \
            prom-AlphaPlusPlus.pnml prom-M3_overfitting.pnml \
            prom-Petrinet_diagnosis.pnml prom-petrify_learn02_5cv.pnml \
            prom-BadStructure.pnml prom-M4_perfectNet.pnml prom-Petriy.pnml \
            prom-petrify_learn03_5cv.pnml prom-DuplicatesGenetic.pnml \
            prom-M5_structuralInappropriate.pnml prom-ReferenceModel.pnml \
            prom-petrify_learn04_5cv.pnml prom-GenDupl.pnml \
            prom-M6_behaviouralInappropriate.pnml prom-aab.pnml \
            prom-petrify_learn05_5cv.pnml prom-GenDuplicates.pnml \
            prom-NonFitting.pnml prom-componentnet1.pnml prom-phils.pnml \
            prom-Genetic.pnml prom-NonFittingModel.pnml prom-componentnet2.pnml \
            prom-runningExample.pnml prom-Genetic_withLazyTasks.pnml \
            prom-NonFittingModel_artificialStartEndTasks.pnml prom-eric.pnml \
            prom-runningExample_Alpha.pnml prom-GoodModel.pnml \
            prom-Onderzoek_voor_Behandeling.pnml prom-erm_model.pnml \
            prom-runningExample_AlphaPlusPlus.pnml \
            prom-GoodModel_artificialStartEndTasks.pnml prom-OverlyGeneral.pnml \
            prom-freechoicetelim.pnml prom-runningExample_petriy.pnml \
            prom-Heuristic.pnml prom-OverlyGeneralModel.pnml \
            prom-g24_alphaAlgorithm.pnml prom-test1.pnml \
            prom-HeuristicMiner.pnml \
            prom-OverlyGeneralModel_artificialStartEndTasks.pnml \
            prom-g24_alphaPlusPlusAlgorithm.pnml prom-testnet.pnml \
            prom-Heuristic_withLazyTasks.pnml prom-OverlyPreciseModel.pnml \
            prom-originalModel.pnml N0.owfn N1.owfn N2.owfn N3.owfn \
            travel.owfn travel2.owfn prom-bla.pnml \
	   


# Below you can list all the files you do not want to have counted in the
# coverability report that can be created by calling "make cover". Usually,
# these files are generated code or helper libraries that have not much to
# do with your tool.
# Absolute filenames are expected, but you may use '*' as wildcard. For
# example '*/libs/*' ignores everything in the 'libs' directory and
# '*/cmdline.c' will exclude any file in the sourses called 'cmdline.c'.
NO_COVER_FILES = */cmdline.c */parser-*.cc



#############################################################################
# EVERYTHING BELOW THIS LINE IS GENERIC - YOU MUST NOT CHANGE ANYTHING BELOW
#############################################################################

################
# GNU autotest #
################

TESTSUITE = $(builddir)/testsuite
EXTRA_DIST = testsuite.at wrap.sh wrap-tool.sh \
             $(addprefix testfiles/,$(TESTFILES))
DISTCLEANFILES = atconfig package.m4 $(TESTSUITE)

# run the test suite when calling "make check"
check-local: atconfig $(TESTSUITE)
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS)

# clean the test results on "make clean"
clean-local:
	test ! -f '$(TESTSUITE)' || $(SHELL) '$(TESTSUITE)' --clean

# call a specific test set, (e.g. "make check-basic")
check-%: atconfig $(TESTSUITE)
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS) --keywords=$*

# create the testsuite using autom4te
$(TESTSUITE): $(srcdir)/testsuite.at
	$(AUTOM4TE) --language=autotest -I '$(srcdir)' -o $@.tmp $@.at
	mv $@.tmp $@


######################
# LCOV test coverage #
######################

# distribute the LGOV scripts
EXTRA_DIST += lcov/README lcov/gendesc lcov/genhtml lcov/geninfo lcov/genpng lcov/lcov

# compile the code for code coverage
cover-prepare:
	$(MAKE) --directory=$(top_srcdir) clean all \
	  CXXFLAGS+="-fprofile-arcs -ftest-coverage" \
	  CFLAGS+="-fprofile-arcs -ftest-coverage" \
	  LDFLAGS+="-lgcov"

# get descriptions from the testsuite
descriptions: $(TESTSUITE)
	$(SHELL) '$(TESTSUITE)' -l > descriptions.txt
	$(SED) -i '1,5d;n;d;' descriptions.txt
	$(SED) -i 's/:[ \t]*testsuite.at:[0-9]*[ \t]*/ /;s/^[ \t]*//' descriptions.txt
	$(SED) -i 's/ /\n\t/' descriptions.txt
	lcov/gendesc descriptions.txt -o descriptions1
	cp descriptions1 descriptions10
	cp descriptions1 descriptions100
	$(SED) -i 's/^TN: \([1-9]\)$$/TN: 0\1/' descriptions10
	$(SED) -i 's/^TN: \([1-9]\)$$/TN: 00\1/' descriptions100
	$(SED) -i 's/^TN: \([1-9][1-9]\)$$/TN: 0\1/' descriptions100
	cat descriptions1 descriptions10 descriptions100 > descriptions
	rm descriptions1 descriptions10 descriptions100 descriptions.txt

# execute tests using coverage
cover-check: cover-prepare $(TESTSUITE)
	test ! -d cover || rm -fr cover
	$(MKDIR_P) cover
	-$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS) COVER=LCOV

# exclude generated code using the wildcards specified in NO_COVER_FILES
cover.info:
	cat cover/*.info > cover.info
	lcov/lcov --remove cover.info $(addprefix ",$(addsuffix ", $(NO_COVER_FILES))) -o cover.info

# create a HTML table with results from LCOV
cover-html: descriptions cover.info
	lcov/genhtml cover.info \
	   --output-directory cover-html --title "$(PACKAGE_STRING)" \
	   --show-details --legend --description-file descriptions --sort \
	   --no-function-coverage --prefix $(abs_top_builddir)
	@echo see `pwd`/cover-html/index.html for a coverage report

cover: cover-check cover-html

# use ZCOV for branch coverage
cover-branch: cover-prepare $(TESTSUITE)
	test ! -d cover || rm -fr cover
	$(MKDIR_P) cover
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS) COVER=ZCOV
	zcov/zcov-merge cover/output.zcov cover/*.zcov
	zcov/zcov-genhtml cover/output.zcov cover-html
	@echo see `pwd`/cover-html/index.html for a coverage report

# clean also the temp files in the src directory
CLEANFILES = -fr cover descriptions 
MAINTAINERCLEANFILES = -fr cover-html cover.info
maintainer-clean-local:
	find $(top_builddir) -name *.gcov -exec rm {} \;
	find $(top_builddir) -name *.gcno -exec rm {} \;
	find $(top_builddir) -name *.gcda -exec rm {} \;

