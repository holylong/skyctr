skyctr -origin make -path Makefile -gen cmake -out CMakeList.txt
skyctr meson.build -g cmake -o CMakeList.txt
skyctr configure -g cmake -o CMakeList.txt
skyctr example.vcxproj -g cmake -o CMakeList.txt 