#!/bin/bash
#########################
# COMPILAR
#########################
if [ -f *.java ]; then
    for file in ./*.java
    do
	javac $file
	base=$(basename $file .java)
	echo "#!/bin/bash" > a.out
	echo "cat - | java $base" >> a.out
	break;
    done
    chmod 755 a.out
elif [ -f *.py ]; then
    for file in *.py
    do
	cp $file a.out
	break;
    done
    chmod 755 a.out
elif [ -f *.lisp ]; then
    for file in *.lisp
    do
        sbcl --load $file --eval "(save-lisp-and-die \"a.out\" :executable t :toplevel #'main)"
        break;
    done
    chmod 755 a.out
elif [ -f *.c ]; then
    for file in *.c
    do
	gcc $file
	break;
    done
elif [ -f *.cpp ]; then 
    for file in *.cpp
    do
	g++ $file
	break;
    done
else
    PWD=$(pwd)
    echo "Nenhum arquivo contendo o código fonte foi encontrado no diretório $PWD"
    exit
fi

#########################
# EXECUTAR TESTES
#########################
    COUNTER=0
    GRADE=0
    rm -rf ./test 2> /dev/null
    mkdir test

    cd ./in
    for f in file*; do
	let COUNTER=COUNTER+1
        touch ../test/$f
	../a.out < ./$f > ../test/$f	
        DIFF=$(diff -w ../test/$f ../out/$f) 
        if [ "$DIFF" == "" ]; then
            let GRADE=GRADE+1
	    echo "$COUNTER ok"
        else 
            echo "$COUNTER incorreto ($f)"
        fi
    done

    cd ../
    rm -rf ./test

    echo -n "Nota " 
    echo -n $(echo "scale=2; $GRADE*10/$COUNTER" | bc)
    echo " ($GRADE de $COUNTER)"
