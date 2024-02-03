if [ ! -d "test" ]; then
  echo "only run from root of project"
  echo "Aborting"
  exit
fi

gcc -Og -o test.out ./test/test.c ./src/{colourmods/colourmods.c,display/display.c,optionhandler/optionhandler.c}
