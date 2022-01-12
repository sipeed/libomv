all : imlib_find_blobs_test




imlib_find_blobs_test :
	python3 project.py build

menuconfig :
	python3 project.py menuconfig

clean :
	python3 project.py clean
	$(RM) -r build 
	$(RM) tmp.bmp

run : 
	@ echo "run imlib_find_blobs_test!"
	@ echo "------------------------------------------------------------"
	@ build/imlib_find_blobs_test

test :
	@ make 
	@ make run 