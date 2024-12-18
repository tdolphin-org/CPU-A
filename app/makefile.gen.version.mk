src/Version.cpp: FORCE
	rm -f $@
	echo "#include <iostream>" >> $@
	echo "#include \"Version.hpp\"" >> $@
	echo "#include \"ProgDefines.hpp\"" >> $@
	echo "#pragma GCC diagnostic push" >> $@
	echo "#pragma GCC diagnostic ignored \"-Wunused-variable\"" >> $@
	echo "static const char *VERSION = AMIGAOS_VER_PREFIX CMD_NAME \" \" APP_VERSION \" \" APP_DATE \" [\" APP_BUILD_COMMIT_HASH \"]\\\r\\\n\";" >> $@
	echo "#pragma GCC diagnostic pop" >> $@
	echo "const char *SCREEN_TITLE = APP_NAME \" \" APP_VERSION \" \" APP_TDOLPHIN_COPYRIGHTS;" >> $@
	echo "using namespace std;" >> $@
	echo "void About() { cout << APP_NAME << \" \" << APP_VERSION << \" \" << APP_DATE << \" [\" << APP_BUILD_COMMIT_HASH << \"]\" << endl \
	<< APP_TDOLPHIN_COPYRIGHTS << endl; }" >> $@

src/Version.hpp: FORCE
	rm -f $@
	echo "#pragma once " >> $@
	echo "#define APP_VERSION \"$(APP_VERSION)\"" >> $@
	echo "#define APP_DATE \"($(APP_DATE))\"" >> $@
	echo "#define APP_BUILD_COMMIT_HASH \"$(APP_BUILD_COMMIT_HASH)\"" >> $@
	echo "extern const char *SCREEN_TITLE;" >> $@
	echo "void About();" >> $@

FORCE:
