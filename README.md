# skyctr
```
skyctr Makefile -g cmake -o CMakeList.txt
skyctr meson.build -g cmake -o CMakeList.txt
skyctr configure -g cmake -o CMakeList.txt
skyctr example.vcxproj -g cmake -o CMakeList.txt
````

# meson.build
## 1.解析
    解析meson.build所有编译选项到内存中
## 2.合成
    将内存中的编译选项合成到cmake文件中

## 正则表达式匹配
    /.*  ---> 匹配所有 /* dsdd */ 