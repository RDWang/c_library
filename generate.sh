PWD=`pwd`
cd lib
find ./  -type f -iname "*.so" | awk -F "/" '$2 !~ /^lib/{a=$2;b="lib" tolower($2);print a,b;system("mv "a" "b"")}'
cd $PWD
