# Run this from the root of the project file
# Do `sh ./test/buildtest.sh` to run this script

ERR="\033[31m"
GOOD="\033[32m"
COMMANDS="\033[33m"
CLEAR="\033[0m"

# CHECKING ENVIRONMENT
if [ ! -d "test" ]; then
  echo -e "${ERR}Only run from root of project${CLEAR}"
  echo -e "${ERR}Aborted${CLEAR}"
  exit
fi
if [ -f "./test.out" ]; then
  rm ./test.out
fi

# COMPILING TEST
echo -e "${GOOD}Compiling test${CLEAR}";
echo -e "${COMMANDS}> gcc test.c${CLEAR}";

gcc -Og -Wall -o test.out ./test/test.c ./src/{colourmods/colourmods.c,display/display.c,optionhandler/optionhandler.c}
if [ ! -f "./test.out" ]; then
  echo -e "${ERR}Fetal error:${CLEAR} compile failed"
  echo -e "${ERR}Aborted${CLEAR}"
  exit
fi

echo -e "${GOOD}Running tests${CLEAR}";
echo -e "${COMMANDS}> test.out${CLEAR}";
./test.out
