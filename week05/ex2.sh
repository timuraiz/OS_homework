if [ ! -f numbers.txt ]; then
  echo "0" > numbers.txt
fi
while [ $(tail -1 numbers.txt ) -le 999 ]; do
  if ln numbers.txt numbers.lock
  then
    (cat numbers.txt | tail -n 1 | tr "\012" "+"; echo "1") | bc >> numbers.txt;
    rm numbers.lock
  else
    echo "Blocked!"
    fi
done
