#! /bin/bash

mainMenu()
{
        echo "__Driver:MAIN_MENU__"
        echo "1: Check In"
        echo "2: Check Out for Build"
        echo "3: Build Driver"
        echo "4: Insert Driver"
        echo "5: Watch Driver"
        echo "6: Remove Driver"
        echo "7: Check out for Development"
        echo "8: Build application"
        echo "9: Test Driver with Application"
        echo "0: Exit Script"
        echo "please Enter your choise.........!!"
        read resp
        case $resp in
                1)
                        checkIn
                        ;;
                2)
                        checkOutBuild
                        ;;
                3)
                        buildDriver
                        ;;
                4)
                        insertDriver
                        ;;
                5)
                        watchDriver
                        ;;
                6)
                        removeDriver
                        ;;
                7)
                        checkOutDevelopment
                        ;;
                8)
                        buildApp
                        ;;
                9)
                        testWithApp
                        ;;
                0)
                        exit 0
          esac
}
testWithApp()
{
	mknod mycdd c $majorNo 0    #creating the entry
	ls -al        #to see th node
	if( ./app )
	then
	    echo	
           # echo "Application run Successfully"
	    echo 
    	else
	    echo
            echo "ERROR: Application run failled"
	    echo
	fi
}
buildApp()
{
        if( make -C ./Applications )
        then
                echo 
                echo "Application Build Successfully......Good Job Aman"
                echo
                mv ./Applications/app .
	else
                echo
                echo "ERROR: Application Build Failled"
                read
        fi

}
checkOutDevelopment()
{
        for file in $(ls *.h,v) $(ls *.c,v)
        do
                co -l $file
        done
}
removeDriver()
{
        sudo rmmod mycdd
}
watchDriver()
{
        lsmod
        read
        dmesg
        read
	echo "Enter major No:"
	read majorNo
        cat /proc/devices
        read
        cat /sys/dev
        read
        cat /proc/modules
        read
}
insertDriver()
{
        sudo insmod ./modules/mycdd.ko nod=20 registerSize=4 noofRegisters=8 deviceSize=256
}
buildDriver()
{
        if( make )
        then
                echo 
                echo "Driver Build Successfully......Good Job Aman"
                echo
        else
                echo
                echo "ERROR: Driver Build Failled"
                read
        fi
}
checkOutBuild()
{
        for file in $(ls *.h,v) $(ls *.c,v)
        do
                co $file
        done
}
checkIn()
{
        for file in $(ls *.h) $(ls *.c)
        do
                ci $file
        done
}

while true
do
        mainMenu
done
