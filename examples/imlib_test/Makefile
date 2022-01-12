all : demo1




demo1 :
	python3 project.py build

menuconfig :
	python3 project.py menuconfig

clean :
	python3 project.py clean
	rm -r build 

run : 
	@ echo "run imlib_test!"
	@ echo "------------------------------------------------------------"
	@ build/imlib_test

test :
	@ make 
	@ make run 