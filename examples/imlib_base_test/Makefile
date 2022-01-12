all : imlib_base_test




imlib_base_test :
	python3 project.py build

menuconfig :
	python3 project.py menuconfig

clean :
	python3 project.py clean
	$(RM) -r build 
	$(RM) tmp.bmp

run : 
	@ echo "run imlib_base_test!"
	@ echo "------------------------------------------------------------"
	@ build/imlib_base_test

test :
	@ make 
	@ make run 