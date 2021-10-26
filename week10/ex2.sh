  308  touch ../week01/f.txt
  309  ls
  310  link ../week01/f.txt _ex2.txt
  311  ls
  312  ls -il
  313  find ../ -inum 1459273 > ex2.txt
  314  cat ex2.txt
  315  find ../ -inum 1459273 -exec rm {} \;
  316  history > ex2.sh
